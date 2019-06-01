#include "../../include/particle/WeatherSystem.h"

namespace particle {

  WeatherSystem::WeatherSystem(float particlesPerSecond, float fallIntensity, float lifeLength, float cloudSize, FpsData *fpsData, Texture *texture) {

    this->particlesPerSecond = particlesPerSecond;
    this->fallIntensity = fallIntensity;
    this->lifeLength = lifeLength;
    this->cloudSize = cloudSize;
    this->fpsData = fpsData;
    this->texture = texture;
  }

  WeatherSystem::~WeatherSystem() {

  }

  void WeatherSystem::generateParticles(ParticleHandler *particleHandler, vec3 cloudCenter) {

    int particleCount = floor(this->particlesPerSecond * this->fpsData->getFrameDeltaTime());
    for (int i = 0; i < particleCount; i++) {
      float posX = cloudCenter.x + (this->cloudSize/2 - rand()%(int)(this->cloudSize));
      float posZ = cloudCenter.z + (this->cloudSize/2 - rand()%(int)(this->cloudSize));
      float posY = cloudCenter.y;
      Particle *particle = new Particle(vec3(posX, posY, posZ), vec3(0, -this->fallIntensity, 0),
                                        1, this->lifeLength, 0, 0.2, this->fpsData);
      particleHandler->addParticle(particle);
    }
  }

  void WeatherSystem::setTexture(Texture *texture){

    this->texture = texture;
  }

  Texture *WeatherSystem::getTexture(){

    return this->texture;
  }


}
