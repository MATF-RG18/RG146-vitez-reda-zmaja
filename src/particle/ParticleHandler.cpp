#include "../../include/particle/ParticleHandler.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://www.opengl-tutorial.org/intermediate-tutorials/billboards-particles/particles-instancing/
// https://learnopengl.com/In-Practice/2D-Game/Particles

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
