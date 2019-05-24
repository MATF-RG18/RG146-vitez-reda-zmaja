#include "../../include/animation/KeyFrame.h"

namespace animation {

  KeyFrame::KeyFrame(float timeStamp, map<string, BoneTransform *>  positions) {

    this->timeStamp = timeStamp;
    this->positions = positions;
  }

  KeyFrame::~KeyFrame() {

  }

  float KeyFrame::getTimeStamp() {

    return this->timeStamp;
  }

  map<string, BoneTransform *> KeyFrame::getPositions() {

      return this->positions;
  }

}
