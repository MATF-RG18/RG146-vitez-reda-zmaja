#include "../../include/entity/AnimatedEntity.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace entity {

  AnimatedEntity::AnimatedEntity(AnimatedModel *model, vec3 position, vec3 rotation, float scale) {

    this->model = model;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

  }

  AnimatedEntity::~AnimatedEntity() {

  }

  void AnimatedEntity::increasePosition(vec3 deltaPosition) {
    this->position.x += deltaPosition.x;
    this->position.y += deltaPosition.y;
    this->position.z += deltaPosition.z;
  }

  void AnimatedEntity::increaseRotation(vec3 deltaRotation) {
    this->rotation.x += deltaRotation.x;
    this->rotation.y += deltaRotation.y;
    this->rotation.z += deltaRotation.z;
  }

  AnimatedModel *AnimatedEntity::getModel() {
    return this->model;
  }

  void AnimatedEntity::setModel(AnimatedModel *model) {
    this->model = model;
  }

  vec3 AnimatedEntity::getPosition() {
    return this->position;
  }

  void AnimatedEntity::setPosition(vec3 position) {
    this->position = position;
  }

  vec3 AnimatedEntity::getRotation() {
    return this->rotation;
  }

  void AnimatedEntity::setRotation(vec3 rotation) {
    this->rotation = rotation;
  }

  float AnimatedEntity::getScale() {
    return this->scale;
  }

  void AnimatedEntity::setScale(float scale) {
    this->scale = scale;
  }


} /* entity */
