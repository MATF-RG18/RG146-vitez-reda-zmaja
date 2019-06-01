#ifndef _PARTICLE_HANDLER_H_
#define _PARTICLE_HANDLER_H_

#include "../particle/ParticleRenderer.h"
#include "../texture/Texture.h"

using namespace texture;

namespace particle {

  class ParticleHandler {
  private:
    list<Particle *> particles;
    ParticleRenderer *particleRenderer;
    Texture *texture;
  public:
    ParticleHandler(VaoLoader *vaoLoader);
    ~ParticleHandler();
    void update();
    void renderParticles(Camera *camera, Texture *texture);
    void cleanUp();
    void addParticle(Particle *particle);
  };
}

#endif
