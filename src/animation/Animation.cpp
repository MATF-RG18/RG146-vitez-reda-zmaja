#include "../../include/animation/Animation.h"

namespace animation {

  Animation::Animation(float length, vector<KeyFrame *> keyFrames) {

    this->length = length;
    this->keyFrames = keyFrames;
  }

  Animation::~Animation() {

  }

  float Animation::getLength() {

    return this->length;
  }

  vector<KeyFrame *> Animation::getKeyFrames() {

    return this->keyFrames;
  }

}
