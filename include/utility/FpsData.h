#ifndef _FPS_DATA_H_
#define _FPS_DATA_H_

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

namespace utility {

    class FpsData {

        private:
          float lastFrameTime;
          float currentFrameTime;
          int fpsCount;
          int numOfFrames;

        public:
          FpsData();
          ~FpsData();
          void update();
          int getFpsCount();

    };
}

#endif