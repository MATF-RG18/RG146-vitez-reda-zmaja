#include "../../include/texture/TerrainTexture.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

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