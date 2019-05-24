#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "../model/AnimatedModel.h"
#include "../animation/Animation.h"
#include "../utility/FpsData.h"

using namespace model;
using namespace utility;

namespace animation {
  class Animator {
  private:
    AnimatedModel *model;
    Animation *currentAnimation;
    float animationTime;
    FpsData *fpsData;
  public:
    Animator(AnimatedModel *model, FpsData *fpsData);
    ~Animator();
    void doAnimation(Animation *animation);
    void update();
  private:
    void increaseAnimationTime();
    map<string, mat4> calculateCurrentAnimationPose();
    void applyPoseToBones(map<string, mat4> currentPose, Bone *bone, mat4 parentTransform);
    vector<KeyFrame *> getPreviousAndNextFrames();
    float calculateProgression(KeyFrame *previous, KeyFrame *next);
    map<string, mat4> interpolatePoses(KeyFrame *previous, KeyFrame *next, float progression);
  };

}

#endif
