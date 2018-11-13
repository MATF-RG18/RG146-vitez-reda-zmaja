#include "../../include/entity/Light.h"

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