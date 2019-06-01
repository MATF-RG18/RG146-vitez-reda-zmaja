#ifndef _WEATHER_SYSTEM_H_
#define _WEATHER_SYSTEM_H_

#include "../particle/ParticleHandler.h"

namespace particle {

  class WeatherSystem {
  private:
    float particlesPerSecond;
    float fallIntensity;
    float lifeLength;
    float cloudSize;
    ParticleHandler *particleHandler;
    FpsData *fpsData;
    Texture *texture;
  public:
    WeatherSystem(float particlesPerSecond, float fallIntensity, float lifeLength, float cloudSize, FpsData *fpsData, Texture *texture);
    ~WeatherSystem();
    void generateParticles(ParticleHandler *particleHandler, vec3 cloudCenter);
    void setTexture(Texture *texture);
    Texture *getTexture();
  };

}

#endif
