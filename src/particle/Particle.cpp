#include "../../include/particle/Particle.h"

namespace particle {

  Particle::Particle(vec3 position, vec3 speed, float gravity, float lifeLength, float rotation, float scale, FpsData *fpsData) {

    this->position = position;
    this->speed = speed;
    this->gravity = gravity;
    this->lifeLength = lifeLength;
    this->rotation = rotation;
    this->scale = scale;
    this->fpsData = fpsData;
  }

  Particle::~Particle() {

  }

  vec3 Particle::getPosition() {

    return this->position;
  }

  float Particle::getRotation() {

    return this->rotation;
  }

  float Particle::getScale() {

    return this->scale;
  }

  bool Particle::update() {

    vec3 dPosition = this->speed * this->gravity * this->fpsData->getFrameDeltaTime();
    this->position += dPosition;
    this->currentLifeTime += this->fpsData->getFrameDeltaTime();
    return (this->currentLifeTime > this->lifeLength);
  }

}
