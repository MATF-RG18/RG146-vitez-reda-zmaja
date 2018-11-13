#include "../../include/texture/SkyboxTextureData.h"

namespace texture {

    SkyboxTextureData::SkyboxTextureData(int width, int height, unsigned char * buffer) {

        this->width = width;
        this->height = height;
        this->buffer = buffer;
    }

    int SkyboxTextureData::getWidth() {

        return this->width;
    }

    int SkyboxTextureData::getHeight() {

        return this->height;
    }

    unsigned char * SkyboxTextureData::getBuffer() {

        return this->buffer;
    }
}