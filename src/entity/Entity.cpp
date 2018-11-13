#include "../../include/entity/Entity.h"

namespace entity {

  Entity::Entity(TexturedModel *model, vec3 position, vec3 rotation, float scale) {

    this->model = model;
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

  }

  Entity::~Entity() {

  }

  void Entity::increasePosition(vec3 deltaPosition) {
    this->position.x += deltaPosition.x;
    this->position.y += deltaPosition.y;
    this->position.z += deltaPosition.z;
  }

  void Entity::increaseRotation(vec3 deltaRotation) {
    this->rotation.x += deltaRotation.x;
    this->rotation.y += deltaRotation.y;
    this->rotation.z += deltaRotation.z;
  }

  TexturedModel *Entity::getModel() {
    return this->model;
  }

  void Entity::setModel(TexturedModel *model) {
    this->model = model;
  }

  vec3 Entity::getPosition() {
    return this->position;
  }

  void Entity::setPosition(vec3 position) {
    this->position = position;
  }

  vec3 Entity::getRotation() {
    return this->rotation;
  }

  void Entity::setRotation(vec3 rotation) {
    this->rotation = rotation;
  }

  float Entity::getScale() {
    return this->scale;
  }

  void Entity::setScale(float scale) {
    this->scale = scale;
  }


} /* entity */
