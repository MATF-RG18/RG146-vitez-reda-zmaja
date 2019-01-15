#include "../../include/core/TerrainRenderer.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace core {

    TerrainRenderer::TerrainRenderer(TerrainShader *terrainShader) {
        this->terrainShader = terrainShader;
        mat4 projectionMatrix = createProjectionMatrix();
        this->terrainShader->start();
        this->terrainShader->loadProjectionMatrix(projectionMatrix);
        this->terrainShader->connectTextureUnits();
        this->terrainShader->stop();
    }

    TerrainRenderer::~TerrainRenderer() {

    }

    void TerrainRenderer::render(list<Terrain *> terrains) {

        for(Terrain *terrain:terrains) {
            prepareTerrain(terrain);
            loadModelMatrix(terrain);
            glDrawElements(GL_TRIANGLES, terrain->getModel()->getVertexCount(), GL_UNSIGNED_INT, 0);
            unbindTerrain();
        }
    }

    void TerrainRenderer::prepareTerrain(Terrain *terrain) {

        RawModel *rawModel = terrain->getModel();
        glBindVertexArray(rawModel->getVaoID());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        bindTextures(terrain);
        terrainShader->loadShineVariables(1, 0);
        
    }

    void TerrainRenderer::bindTextures(Terrain *terrain){

        TerrainTexturePack * texturePack = terrain->getTexturePack();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texturePack->getBackgroundTexture()->getTextureID());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texturePack->getRTexture()->getTextureID());
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, texturePack->getGTexture()->getTextureID());
        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D, texturePack->getBTexture()->getTextureID());
        glActiveTexture(GL_TEXTURE4);
        glBindTexture(GL_TEXTURE_2D, terrain->getBlendMap()->getTextureID());


    }

    void TerrainRenderer::unbindTerrain() {

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glBindVertexArray(0);
    }

    void TerrainRenderer::loadModelMatrix(Terrain *terrain) {

        mat4 transformationMatrix = createTransformationMatrix(vec3 (terrain->getX(),0,terrain->getZ()), vec3 (0,0,0), 1);
        terrainShader->loadTransformationMatrix(transformationMatrix);
    }

    mat4 TerrainRenderer::createProjectionMatrix() {

    float aspectRatio = (float)glutGet(GLUT_SCREEN_WIDTH)/(float)glutGet(GLUT_SCREEN_HEIGHT);

    mat4 projectionMatrix = perspective(radians(FOV), aspectRatio, NEAR_PLANE, FAR_PLANE);

    return projectionMatrix;

  }
}