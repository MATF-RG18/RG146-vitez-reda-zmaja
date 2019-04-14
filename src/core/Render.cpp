#include "../../include/core/Render.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace core {

  Render::Render(Shader *shader) {
    
    this->shader = shader;
    mat4 projectionMatrix = createProjectionMatrix();
    this->shader->start();
    this->shader->loadProjectionMatrix(projectionMatrix);
    this->shader->stop();
  }

  Render::~Render() {

  }


  void Render::render(map<TexturedModel *, list<Entity *>> entities) {

    for(pair<TexturedModel *, list<Entity *>> entity:entities){
      TexturedModel *model = entity.first;
      prepareTexturedModel(model);
      for(Entity * e: entity.second){
        prepareInstance(e);
        glDrawElements(GL_TRIANGLES, model->getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
      }
      unbindTexturedModel();
    }
  }

  void Render::prepareTexturedModel(TexturedModel *model) {

    RawModel rawModel = model->getRawModel();
    glBindVertexArray(rawModel.getVaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    ModelTexture *texture = model->getTexture();
    if (texture->getHasTransparency()) {
     // MainRenderer->disableCulling();
    }
    shader->loadFakeLightning(texture->getUseFakeLightning());
    shader->loadShineVariables(texture->getShine(), texture->getReflectivity());
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model->getTexture()->getID());
  }

  void Render::unbindTexturedModel() {

    //MainRenderer->enableCulling();
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
  }

  void Render::prepareInstance(Entity *entity) {

    mat4 transformationMatrix = createTransformationMatrix(entity->getPosition(), entity->getRotation(), entity->getScale());
    shader->loadTransformationMatrix(transformationMatrix);
  }

  mat4 Render::createProjectionMatrix() {

    float aspectRatio = (float)glutGet(GLUT_SCREEN_WIDTH)/(float)glutGet(GLUT_SCREEN_HEIGHT);

    mat4 projectionMatrix = perspective(radians(FOV), aspectRatio, NEAR_PLANE, FAR_PLANE);

    return projectionMatrix;
    
  }

} // core
