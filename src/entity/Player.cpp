#include "../../include/entity/Player.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// kao i http://jerome.jouvie.free.fr/opengl-tutorials/Tutorial26.php

namespace entity {

    Player::Player(AnimatedModel *model, vec3 position, vec3 rotation, float scale, Terrain *terrain, FpsData *fpsData, Animator *animator) : AnimatedEntity(model, position, rotation, scale) {
        this->currentSpeed = 0;
        this->currentTurnSpeed = 0;
        this->terrain = terrain;
        this->keyBuffer = new bool[256];
        for(int i = 0; i < 256; i++) {
            this->keyBuffer[i] = false;
        }
        this->fpsData = fpsData;
        this->animator = animator;
        this->animationOn = false;

    }

    Player::~Player() {

    }

    void Player::handleKeyUp(unsigned char key) {

        this->keyBuffer[key] = false;
        this->animationOn = false;
        this->animator->doAnimation(nullptr);
    }

    void Player::handleKeyDown(unsigned char key) {

        this->keyBuffer[key] = true;
        if(!this->animationOn) {
          this->animator->doAnimation(this->getModel()->getAnimation(""));
        }
    }

    void Player::move() {


        float fps = this->fpsData->getFpsCount();

        if (this->keyBuffer[GLUT_KEY_UP]) {

            this->currentSpeed = RUN_SPEED/fps;
        }
        else if (this->keyBuffer[GLUT_KEY_DOWN]) {

            this->currentSpeed = -RUN_SPEED/fps;
        }
        else {
            this->currentSpeed = 0;
        }

        if (this->keyBuffer[GLUT_KEY_LEFT]) {

            this->currentTurnSpeed = TURN_SPEED/fps;
        }
        else if (this->keyBuffer[GLUT_KEY_RIGHT]) {

            this->currentTurnSpeed = -TURN_SPEED/fps;
        }
        else {
            this->currentTurnSpeed = 0;
        }


        this->increaseRotation(vec3 {0, this->currentTurnSpeed, 0});

        float deltaX = this->currentSpeed*sin(radians(this->getRotation().y));
        float deltaZ = this->currentSpeed*cos(radians(this->getRotation().y));

        this->increasePosition(vec3 (deltaX, 0, deltaZ));
        float terrainHeight = this->terrain->getHeightOfTerrain(this->getPosition().x, this->getPosition().z);
        this->setPosition(vec3(this->getPosition().x, terrainHeight ,this->getPosition().z));

    }
}
