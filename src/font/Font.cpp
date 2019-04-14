#include "../../include/font/Font.h"

// Klasa je implementirana po uzoru na clanak
// https://learnopengl.com/In-Practice/Text-Rendering

namespace font {
    Font::Font(const char *fontName, int fontSize) {

        if (FT_Init_FreeType(&this->ft)) {
            cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        }

        if (FT_New_Face(this->ft, fontName, 0, &this->face)) {
            cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        }

        FT_Set_Pixel_Sizes(face, 0, fontSize);

        loadFontData();
    }

    Font::~Font() {

    }

    FontData * Font::getCharData(GLchar c) {

        return this->fontCharacters[c];
    }

    void Font::loadFontData() {

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        for(int c = 0; c < 128; c++) {

            if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
                cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }

            GLuint textureID;
            glGenTextures(1, &textureID);
            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                this->face->glyph->bitmap.width,
                this->face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                this->face->glyph->bitmap.buffer
            );

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            this->fontCharacters[c] = new FontData(
                textureID,
                vec2(this->face->glyph->bitmap.width, this->face->glyph->bitmap.rows),
                vec2(this->face->glyph->bitmap_left, this->face->glyph->bitmap_top),
                this->face->glyph->advance.x
            );

        }

        FT_Done_Face(this->face);
        FT_Done_FreeType(this->ft);
        return;
    }

}
