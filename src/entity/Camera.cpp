#include "../../include/entity/Camera.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// kao i http://www.opengl-tutorial.org/beginners-tutorials/tutorial-6-keyboard-and-mouse/

namespace entity {

  Camera::Camera(Player *player) {

    this->position = vec3(player->getPosition());
    this->distanceFromPlayer = 50;
    this->angleAroundPlayer = 0;
    this->pich = 25;
    this->yaw = 180;
    this->roll = 0;
    this->player = player;
    this->sensitivity = 0.001;
  }

  Camera::~Camera() {

  }

  void Camera::move() {

    float horizontalDistance = calculateHorizontalDistance();
    float verticalDistance = calculateVerticalDistance();
    calculateCameraPosition(horizontalDistance, verticalDistance);
    this->yaw = 180 - this->angleAroundPlayer;
  }

  void Camera::handleMouseInput(int button, int state, int x, int y) {

    calculateZoom(button, state);
    float horizontalDistance = calculateHorizontalDistance();
    float verticalDistance = calculateVerticalDistance();
    calculateCameraPosition(horizontalDistance, verticalDistance);
    this->yaw = 180 - this->angleAroundPlayer;
  }

  void Camera::handleKeyboardInput(unsigned char key) {
    calculatePich(key);
    calculateAngleAroundPlayer(key);
    float horizontalDistance = calculateHorizontalDistance();
    float verticalDistance = calculateVerticalDistance();
    calculateCameraPosition(horizontalDistance, verticalDistance);
    this->yaw = 180 - this->angleAroundPlayer;
  }


  vec3 Camera::getPosition() {

    return this->position;
  }

  float Camera::getPich() {

    return this->pich;
  }

  float Camera::getYaw() {

    return this->yaw;
  }

  float Camera::getRoll() {

    return this->roll;
  }

  void Camera::calculateZoom(int button, int state) {
    if (state == GLUT_UP) {
      switch (button) {
        case 3:
          this->distanceFromPlayer -= 4;
          break;
        case 4:
          this->distanceFromPlayer += 4;
          break;
      }
    }
  }

  void Camera::calculatePich(unsigned char key) {

    switch (key) {
            case 'w':
            case 'W':
                this->pich += 0.5;
                break;
            case 's':
            case 'S':
                this->pich -= 0.5;
                break;

    }
  }

  void Camera::calculateAngleAroundPlayer(unsigned char key) {

    switch (key) {
            case 'a':
            case 'A':
                this->angleAroundPlayer += 0.5;
                break;
            case 'd':
            case 'D':
                this->angleAroundPlayer -= 0.5;
                break;

    }
  }

  float Camera::calculateHorizontalDistance() {

    return this->distanceFromPlayer * cos(this->pich*PI/180);
  }

  float Camera::calculateVerticalDistance() {

    return this->distanceFromPlayer * sin(this->pich*PI/180);
  }

  void Camera::calculateCameraPosition(float horizontalDistance, float verticalDistance) {

    float theta = this->angleAroundPlayer;
    float offsetX = horizontalDistance*sin(theta*PI/180);
    float offsetZ = horizontalDistance*cos(theta*PI/180);
    this->position.x = this->player->getPosition().x - offsetX;
    this->position.y = this->player->getPosition().y + verticalDistance;
    this->position.z = this->player->getPosition().z - offsetZ;
  }

} /* entity */
