#include "../../include/core/SkyboxRenderer.h"

// Klasa je implementirana po uzoru na internet clanke https://learnopengl.com/Advanced-OpenGL/Cubemaps,
// http://ogldev.atspace.co.uk/www/tutorial25/tutorial25.html
// kao i video tutorijal https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace core {

    SkyboxRenderer::SkyboxRenderer(VaoLoader *vaoLoader) {

        this->time = 0.0;

        float VERTICES[] = {        
            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,

            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,

            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,

            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,

            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE,
            -CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE,

            -CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE,
            -CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE,
            CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE
        };


        this->dayTextureFiles = {"res/day_skybox/right.png", 
                            "res/day_skybox/left.png", 
                            "res/day_skybox/top.png", 
                            "res/day_skybox/bottom.png",
                            "res/day_skybox/back.png",
                            "res/day_skybox/front.png"};

        this->nightTextureFiles = {"res/night_skybox/right.png", 
                            "res/night_skybox/left.png", 
                            "res/night_skybox/top.png", 
                            "res/night_skybox/bottom.png",
                            "res/night_skybox/back.png",
                            "res/night_skybox/front.png"};

        // Ucitavamo kocku na koju ce biti nalepljene teksture neba
        this->cube = vaoLoader->loadToVao(VERTICES, sizeof(VERTICES)/sizeof(VERTICES[0]), 3);
        
        // Ucitavamo texture
        this->dayTextureID = vaoLoader->loadCubeMap(this->dayTextureFiles);
        this->nightTextureID = vaoLoader->loadCubeMap(this->nightTextureFiles);

        // Pokrecemo sejder program
        this->skyboxShader = new SkyboxShader();
        this->skyboxShader->start();

        // Povezujemo dnevno i nocno nebo
        this->skyboxShader->connectTextureUnits();

        // Pravimo i ucitavamo matricu projekcije
        mat4 projectionMatrix = createProjectionMatrix();
        this->skyboxShader->loadProjectionMatrix(projectionMatrix);

        // Zaustavljamo sejder 
        this->skyboxShader->stop();
    }

    SkyboxRenderer::~SkyboxRenderer() {

    }

    void SkyboxRenderer::render(Camera *camera, float r, float g, float b, FpsData *fpsData) {

        // Pokrecemo sejder
        this->skyboxShader->start();

        // Ucitavamo matricu pogleda
        this->skyboxShader->loadViewMatrix(camera, fpsData);

        // Ucitavamo boju magle
        this->skyboxShader->loadFogColour(r, g, b);

        // Ucitavanje podataka i tekstura
        glBindVertexArray(this->cube->getVaoID());
        glEnableVertexAttribArray(0);
        
        bindTextures(fpsData);

        // Iscrtavanje neba
        glDrawArrays(GL_TRIANGLES, 0, this->cube->getVertexCount());

        // Otkacinjanje podataka 
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);

        // Zaustavljanje sejdera
        this->skyboxShader->stop();

    }

    void SkyboxRenderer::bindTextures(FpsData *fpsData) {

        float blendFactor = 0.0;
        if (fpsData->getFpsCount() != 0)
            this->time += (1.0/float(fpsData->getFpsCount()));
        if (this->time >= 40)
            this->time -= 40;

        if(this->time <= 10)
            // Svice
            blendFactor = (10 - time)/10;
        else if(this->time > 10 && this->time <= 20) 
            // Dan
            blendFactor = 0.0;
        else if(this->time > 20 && this->time <= 30) 
            // Smrkava se
            blendFactor = (time-20)/10;
        else if(this->time > 30)
            // Noc
            blendFactor = 1.0;
   



        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, this->dayTextureID);
         glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_CUBE_MAP, this->nightTextureID);
        this->skyboxShader->loadBlendFactor(blendFactor);

    }

    mat4 SkyboxRenderer::createProjectionMatrix() {

    float aspectRatio = (float)glutGet(GLUT_SCREEN_WIDTH)/(float)glutGet(GLUT_SCREEN_HEIGHT);

    mat4 projectionMatrix = perspective(radians(FOV), aspectRatio, NEAR_PLANE, FAR_PLANE);

    return projectionMatrix;

  }
}