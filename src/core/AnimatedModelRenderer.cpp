#include "../../include/core/AnimatedModelRenderer.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace core {

  AnimatedModelRenderer::AnimatedModelRenderer(AnimatedModelShader *shader) {

    this->shader = shader;
    mat4 projectionMatrix = createProjectionMatrix();
    this->shader->start();
    this->shader->loadProjectionMatrix(projectionMatrix);
    this->shader->stop();
  }

  AnimatedModelRenderer::~AnimatedModelRenderer() {

  }


  void AnimatedModelRenderer::render(map<AnimatedModel *, list<AnimatedEntity *>> entities) {

    for(pair<AnimatedModel *, list<AnimatedEntity *>> entity:entities){
      AnimatedModel *model = entity.first;
      for(AnimatedEntity * e: entity.second){
        prepareInstance(e);
        drawAnimatedModel(model);
      }
      unbindAnimatedModel();
    }
  }

  void AnimatedModelRenderer::drawAnimatedModel(AnimatedModel *model) {

    RawModel *rawModel = model->getModel()->getRawModel();
    vector<GLint> meshes = rawModel->getMeshesVaoID();
    vector<Texture *> textures = model->getModel()->getTextures();
    vector<GLint> vertexCounts = rawModel->getMeshesVertexCount();
    for (int i = 0; i < meshes.size(); i++) {
      glBindVertexArray(meshes[i]);
      glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
      glEnableVertexAttribArray(2);
      glEnableVertexAttribArray(3);
      glEnableVertexAttribArray(4);
      Texture *texture = textures[i];
      if (texture->getHasTransparency()) {
       // MainRenderer->disableCulling();
      }
      shader->loadFakeLightning(texture->getUseFakeLightning());
      shader->loadShineVariables(texture->getShine(), texture->getReflectivity());
      shader->loadBoneTransforms(model->getBoneTransforms(), MAX_BONES);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, texture->getID());

      glDrawElements(GL_TRIANGLES, vertexCounts[i] , GL_UNSIGNED_INT, 0);
    }
  }

  void AnimatedModelRenderer::unbindAnimatedModel() {

    //MainRenderer->enableCulling();
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(4);
    glBindVertexArray(0);
  }

  void AnimatedModelRenderer::prepareInstance(AnimatedEntity *entity) {

    mat4 transformationMatrix = createTransformationMatrix(entity->getPosition(), entity->getRotation(), entity->getScale());
    shader->loadTransformationMatrix(transformationMatrix);
  }

  mat4 AnimatedModelRenderer::createProjectionMatrix() {

    float aspectRatio = (float)glutGet(GLUT_SCREEN_WIDTH)/(float)glutGet(GLUT_SCREEN_HEIGHT);

    mat4 projectionMatrix = perspective(radians(FOV), aspectRatio, NEAR_PLANE, FAR_PLANE);

    return projectionMatrix;

  }

} // core
