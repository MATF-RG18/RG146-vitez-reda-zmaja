#include "../../include/hud/HudRenderer.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace hud {

    HudRenderer::HudRenderer(VaoLoader *vaoLoader) {

        float positions[] = {-1,1,-1,-1,1,1,1,-1};
        this->quad = vaoLoader->loadToVao(positions, sizeof(positions)/sizeof(positions[0]),2);
        this->hudShader = new HudShader(HUD_VERTEX_SHADER, HUD_FRAGMENT_SHADER);
    }

    HudRenderer::~HudRenderer() {

    }

    void HudRenderer::render(vector<HudTexture*> huds) {

        this->hudShader->start();
        glBindVertexArray(this->quad->getVaoID());
        glEnableVertexAttribArray(0);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_DEPTH_TEST);
        for(HudTexture *hudTex: huds) {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, hudTex->getTextureID());
            mat4 transformationMatrix = createTransformationMatrix(hudTex->getPosition(), hudTex->getScale(), hudTex->getRotation());
            hudShader->loadTransformationMatrix(transformationMatrix);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, this->quad->getVertexCount());
        }
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
        this->hudShader->stop();
    }

    void HudRenderer::cleanUp() {

        this->hudShader->cleanUp();
    }

}
