#include "../../include/utility/FpsData.h"

// Implementirano pomocu http://www.opengl-tutorial.org/miscellaneous/an-fps-counter/

namespace utility {

    FpsData::FpsData() {
      
      this->numOfFrames = 0;
      this->lastFrameTime = 0.0;
      this->currentFrameTime = 0.0;
      this->fpsCount = 0;
    }

    FpsData::~FpsData() {

    }

    void FpsData::update() {

      this->numOfFrames++;
      this->currentFrameTime = glutGet(GLUT_ELAPSED_TIME);
      float deltaTime = this->currentFrameTime - this->lastFrameTime;
      if (deltaTime > 1000.0) {
        this->fpsCount = this->numOfFrames * 1000.0 / deltaTime;
        this->lastFrameTime = this->currentFrameTime;
        this->numOfFrames = 0;
      }
    
    }

    int FpsData::getFpsCount() {

      return this->fpsCount;
    }
}