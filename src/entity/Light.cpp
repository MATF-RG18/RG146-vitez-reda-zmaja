#include "../../include/entity/Light.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace entity {

    Light::Light(vec3 position, vec3 colour) {
        this->position = position;
        this->colour = colour;
    }

    Light::~Light() {

    }

    vec3 Light::getPosition() {

        return this->position;
    }

    vec3 Light::getColour() {

        return this->colour;
    }
}