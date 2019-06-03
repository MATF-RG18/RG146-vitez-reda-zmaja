#include "../../include/particle/Particle.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://www.opengl-tutorial.org/intermediate-tutorials/billboards-particles/particles-instancing/
// https://learnopengl.com/In-Practice/2D-Game/Particles

namespace particle {

  Particle::Particle(vec3 position, vec3 speed, float gravity, float lifeLength, float rotation, float scale, FpsData *fpsData) {

    this->position = position;
    this->speed = speed;
    this->gravity = gravity;
    this->lifeLength = lifeLength;
    this->rotation = rotation;
    this->scale = scale;
    this->fpsData = fpsData;
    this->currentLifeTime = 0;
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
