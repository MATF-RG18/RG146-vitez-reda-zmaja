#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "../animation/KeyFrame.h"

#include <vector>

using namespace std;

namespace animation {

  class Animation {
  private:
    float length;
    vector<KeyFrame *> keyFrames;
  public:
    Animation(float length, vector<KeyFrame *> keyFrames);
    ~Animation();
    float getLength();
    vector<KeyFrame *> getKeyFrames();
  };

}

#endif
