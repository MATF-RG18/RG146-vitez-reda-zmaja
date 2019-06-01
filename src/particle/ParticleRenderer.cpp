#include "../../include/particle/ParticleRenderer.h"

namespace particle {

  ParticleRenderer::ParticleRenderer(VaoLoader *vaoLoader) {

    float VERTICES[] = {
      -0.5, 0.5,
      -0.5, -0.5,
      0.5, 0.5,
      0.5, -0.5
    };

    GLint verticesSize = sizeof(VERTICES)/sizeof(VERTICES[0]);
    GLint vaoID = vaoLoader->loadToVao(VERTICES, verticesSize, 2);
    GLint vertexCount = verticesSize/2;
    this->rawModel = new RawModel(vector<GLint> {vaoID}, vector<GLint> {vertexCount});
    this->particleShader = new ParticleShader(PARTICLE_VERTEX_SHADER, PARTICLE_FRAGMENT_SHADER);

    this->particleShader->start();
    mat4 projectionMatrix = createProjectionMatrix();
    this->particleShader->loadProjectionMatrix(projectionMatrix);
    this->particleShader->stop();
  }

  ParticleRenderer::~ParticleRenderer() {

  }

  void ParticleRenderer::render(list<Particle *> particles, Camera *camera, Texture *texture) {

    mat4 viewMatrix = createViewMatrix(camera->getPosition(), camera->getPich(), camera->getYaw());
    prepare();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->getID());
    for (Particle *particle : particles) {
      updateModelViewMatrix(particle->getPosition(), particle->getRotation(), particle->getScale(), viewMatrix);
      glDrawArrays(GL_TRIANGLE_STRIP, 0, this->rawModel->getMeshesVertexCount()[0]);
    }
    finishRendering();
  }

  void ParticleRenderer::cleanUp() {

    this->particleShader->cleanUp();
  }

  void ParticleRenderer::prepare() {

    this->particleShader->start();
    glBindVertexArray(this->rawModel->getMeshesVaoID()[0]);
    glEnableVertexAttribArray(0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(false);
  }

  void ParticleRenderer::finishRendering() {

    glDepthMask(true);
    glDisable(GL_BLEND);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    this->particleShader->stop();
  }

  mat4 ParticleRenderer::createProjectionMatrix() {

    float aspectRatio = (float)glutGet(GLUT_SCREEN_WIDTH)/(float)glutGet(GLUT_SCREEN_HEIGHT);

    mat4 projectionMatrix = perspective(radians(FOV), aspectRatio, NEAR_PLANE, FAR_PLANE);

    return projectionMatrix;
  }

  void ParticleRenderer::updateModelViewMatrix(vec3 position, float rotation, float scaleFactor, mat4 viewMatrix) {

    mat4 modelMatrix = mat4(1.0f);
    modelMatrix = translate(modelMatrix, position);
    modelMatrix[0][0] = viewMatrix[0][0];
    modelMatrix[0][1] = viewMatrix[1][0];
    modelMatrix[0][2] = viewMatrix[2][0];
    modelMatrix[1][0] = viewMatrix[0][1];
    modelMatrix[1][1] = viewMatrix[1][1];
    modelMatrix[1][2] = viewMatrix[2][1];
    modelMatrix[2][0] = viewMatrix[0][2];
    modelMatrix[2][1] = viewMatrix[1][2];
    modelMatrix[2][2] = viewMatrix[2][2];
    modelMatrix = rotate(modelMatrix, radians(rotation), vec3(0,0,1));
    modelMatrix = scale(modelMatrix, vec3(scaleFactor, scaleFactor, scaleFactor));

    mat4 updatedModelViewMatrix = viewMatrix*modelMatrix;
    this->particleShader->loadModelViewMatrix(updatedModelViewMatrix);
  }

}
