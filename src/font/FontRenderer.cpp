#include "../../include/font/FontRenderer.h"

// Klasa je implementirana po uzoru na clanak
// https://learnopengl.com/In-Practice/Text-Rendering

namespace font {

    FontRenderer::FontRenderer() {

        this->fontShader = new FontShader(FONT_VERTEX_SHADER, FONT_FRAGMENT_SHADER);
        this->screenWidth = (float)glutGet(GLUT_SCREEN_WIDTH);
        this->screenHeight = (float)glutGet(GLUT_SCREEN_HEIGHT);
    }

    FontRenderer::~FontRenderer() {

    }

    void FontRenderer::render(Text *text) {

        glGenVertexArrays(1, &this->vaoID);
        glGenBuffers(1, &this->vboID);
        glBindVertexArray(this->vaoID);
        glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        this->fontShader->start();
        this->fontShader->loadTextColor(text->getColor());
        mat4 transformationMatrix = createTransformationMatrix(text->getPosition(), text->getScale(), text->getRotation());
        fontShader->loadTransformationMatrix(transformationMatrix);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(this->vaoID);
        glEnableVertexAttribArray(0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_DEPTH_TEST);
        string::const_iterator c;
        GLfloat x = text->getPosition().x;
        GLfloat y = text->getPosition().y;
        for (c = text->getText().begin(); c != text->getText().end(); c++) {

            FontData *fontData = text->getFont()->getCharData(*c);

            GLfloat xpos = (x + fontData->bearing.x)/this->screenWidth;
            GLfloat ypos = (y - (fontData->size.y - fontData->bearing.y))/this->screenHeight;

            GLfloat w = fontData->size.x/this->screenWidth;
            GLfloat h = fontData->size.y/this->screenHeight;

            GLfloat vertices[6][4] = {
                { xpos,     ypos + h,   0.0, 0.0 },
                { xpos,     ypos,       0.0, 1.0 },
                { xpos + w, ypos,       1.0, 1.0 },

                { xpos,     ypos + h,   0.0, 0.0 },
                { xpos + w, ypos,       1.0, 1.0 },
                { xpos + w, ypos + h,   1.0, 0.0 }
            };

            glBindTexture(GL_TEXTURE_2D, fontData->textureID);
            glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            x += (fontData->advance >> 6);
        }
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        this->fontShader->stop();

        return;
    }

    void FontRenderer::cleanUp() {

        this->fontShader->cleanUp();

        return;
    }

} // font
