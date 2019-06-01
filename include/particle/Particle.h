#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "../utility/FpsData.h"

#include <glm/vec3.hpp>
#include <stdio.h>

using namespace glm;
using namespace utility;

namespace particle {

  class Particle {

  private:
    vec3 position;
    vec3 speed;
    float gravity;
    float lifeLength;
    float currentLifeTime;
    float rotation;
    float scale;
    FpsData *fpsData;
  public:
    Particle(vec3 position, vec3 speed, float gravity, float lifeLength, float rotation, float scale, FpsData *fpsData);
    ~Particle();
    vec3 getPosition();
    float getRotation();
    float getScale();
    bool update();

  };

}
#endif
