#include "../../include/font/FontData.h"

// Klasa je implementirana po uzoru na clanak
// https://learnopengl.com/In-Practice/Text-Rendering

namespace font {

    FontData::FontData(GLuint textureID, vec2 size, vec2 bearing, GLuint advance) {

        this->textureID = textureID;
        this->size = size;
        this->bearing = bearing;
        this->advance = advance;
    }

    FontData::~FontData() {

    }

} // font
