#ifndef _SKYBOX_RENDERER_H_
#define _SKYBOX_RENDERER_H_

#include "../model/RawModel.h"
#include "../shader/SkyboxShader.h"
#include "../core/VaoLoader.h"

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Ukljucivanje biblioteka.
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <vector>

using namespace std;
using namespace model;
using namespace shader;
using namespace glm;

#define CUBE_SIZE 500

namespace core {

    class SkyboxRenderer {

        private:
            float FOV = 70;
            float NEAR_PLANE = 0.1;
            float FAR_PLANE = 1000;
            vector<const char *> dayTextureFiles;
            vector<const char *> nightTextureFiles;
            RawModel *cube;
            GLuint dayTextureID;
            GLuint nightTextureID;
            SkyboxShader *skyboxShader;
            float time;

        public:
            SkyboxRenderer(VaoLoader *vaoLoader);
            ~SkyboxRenderer();
            void render(Camera *camera, float r, float g, float b, FpsData *fpsData);
        private:
            mat4 createProjectionMatrix();
            void bindTextures(FpsData *fpsData);

    };
}

#endif