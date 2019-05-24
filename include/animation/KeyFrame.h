#ifndef _KEY_FRAME_H_
#define _KEY_FRAME_H_

#include "../animation/BoneTransform.h"

#include <map>
#include <vector>

using namespace std;

namespace animation {

  class KeyFrame {
  private:
    float timeStamp;
    map<string, BoneTransform *>  positions;
  public:
    KeyFrame(float timeStamp, map<string, BoneTransform *>  positions);
    ~KeyFrame();
    float getTimeStamp();
    map<string, BoneTransform *> getPositions();
  };

}

#endif
