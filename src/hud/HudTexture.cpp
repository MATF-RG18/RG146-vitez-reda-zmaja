#include "../../include/hud/HudTexture.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace hud {

    HudTexture::HudTexture(int textureID, vec2 position, vec2 scale, float rotation) {

        this->textureID = textureID;
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;
    }

    HudTexture::~HudTexture() {

    }

    int HudTexture::getTextureID() {

        return this->textureID;
    }

    vec2 HudTexture::getPosition() {

        return this->position;
    }

    vec2 HudTexture::getScale() {

        return this->scale;
    }

    float HudTexture::getRotation() {

        return this->rotation;
    }
}
