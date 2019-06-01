#include "../../include/particle/ParticleHandler.h"

namespace particle {

  ParticleHandler::ParticleHandler(VaoLoader *vaoLoader) {

    this->particleRenderer = new ParticleRenderer(vaoLoader);
  }

  ParticleHandler::~ParticleHandler() {

  }

  void ParticleHandler::update() {

    this->particles.remove_if([](Particle *p){return p->update();});
  }

  void ParticleHandler::renderParticles(Camera *camera, Texture *texture) {

    particleRenderer->render(this->particles, camera, texture);
  }

  void ParticleHandler::cleanUp() {

    this->particleRenderer->cleanUp();
  }

  void ParticleHandler::addParticle(Particle *particle) {

    this->particles.push_back(particle);
  }

}