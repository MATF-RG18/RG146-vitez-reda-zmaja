#include "../../include/entity/Player.h"

namespace entity {

    Player::Player(TexturedModel *model, vec3 position, vec3 rotation, float scale, Terrain *terrain) : Entity(model, position, rotation, scale) {
        this->currentSpeed = 0;
        this->currentTurnSpeed = 0;
        this->terrain = terrain;
        this->keyBuffer = new bool[256];
        for(int i = 0; i < 256; i++) {
            this->keyBuffer[i] = false;
        }
        
    }

    Player::~Player() {

    }

    void Player::handleKeyUp(unsigned char key) {

        this->keyBuffer[key] = false;
    }

    void Player::handleKeyDown(unsigned char key) {

        this->keyBuffer[key] = true;
    }

    void Player::move(FpsData *fpsData) {


        float fps = fpsData->getFpsCount();

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