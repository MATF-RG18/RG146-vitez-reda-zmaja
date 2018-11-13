#include "../../include/texture/TerrainTexture.h"

namespace texture {

    TerrainTexture::TerrainTexture(int textureID) {
        
        this->textureID = textureID;
    }

    TerrainTexture::~TerrainTexture() {
        
    }

    int TerrainTexture::getTextureID() {

        return this->textureID;
    }
}