#include "../../include/animation/Animator.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

namespace animation {

  Animator::Animator(AnimatedModel *model, FpsData *fpsData) {

    this->model = model;
    this->animationTime = 0;
    this->fpsData = fpsData;
  }

  Animator::~Animator() {

  }

  void Animator::doAnimation(Animation *animation) {

    this->animationTime = 0;
    this->currentAnimation = animation;
  }

  void Animator::update() {

    if (currentAnimation == nullptr) {
      return;
    }
    increaseAnimationTime();
    vector<KeyFrame *> allFrames = this->currentAnimation->getKeyFrames();
    if(allFrames[0]->getTimeStamp() >= this->animationTime)
      return;
    map<string, mat4> currentPose = calculateCurrentAnimationPose();
    for (int i = 0; i < this->model->getNumRootNodes(); i++) {
      applyPoseToBones(currentPose, model->getRootNode(i), mat4(1.0f));
    }
  }

  void Animator::increaseAnimationTime() {

    this->animationTime += fpsData->getFrameDeltaTime();
    if(this->animationTime > this->currentAnimation->getLength()) {
      this->animationTime = fmod(this->currentAnimation->getLength(), this->animationTime);//check
    }
  }

  map<string, mat4> Animator::calculateCurrentAnimationPose() {

    vector<KeyFrame *> frames = getPreviousAndNextFrames();
    float progression = calculateProgression(frames[0], frames[1]);
    return interpolatePoses(frames[0], frames[1], progression);
  }

  void Animator::applyPoseToBones(map<string, mat4> currentPose, Bone *bone, mat4 parentTransform) {

    mat4 currentLocalTransform = currentPose[bone->getName()];
    mat4 currentTransform = parentTransform * currentLocalTransform;
    for (Bone *child: bone->getChildrens()) {
      applyPoseToBones(currentPose, child, currentTransform);
    }
    currentTransform = currentTransform * bone->getInverseBindTransform();
    bone->setAnimatedTransform(currentTransform);
  }

  vector<KeyFrame *> Animator::getPreviousAndNextFrames() {

    vector<KeyFrame *> allFrames = this->currentAnimation->getKeyFrames();
    KeyFrame *previous = allFrames[0];
    KeyFrame *next = allFrames[0];
    for (KeyFrame *frame : allFrames) {
      next = frame;
      if (next->getTimeStamp() >= this->animationTime) {
        break;
      }
      previous = next;
    }
    return vector<KeyFrame *> {previous, next};
  }

  float Animator::calculateProgression(KeyFrame *previous, KeyFrame *next) {

    float totalTime = next->getTimeStamp() - previous->getTimeStamp();
    float currentTime = this->animationTime - previous->getTimeStamp();

    return currentTime/totalTime;
  }

  map<string, mat4> Animator::interpolatePoses(KeyFrame *previous, KeyFrame *next, float progression) {

    map<string, mat4> currentPose;
    for (auto pos : previous->getPositions()) {
      BoneTransform *previousTransform =  previous->getPositions()[pos.first];
      BoneTransform *nextTransform =  next->getPositions()[pos.first];
      BoneTransform *currentTransform;
      currentTransform = currentTransform->interpolate(previousTransform, nextTransform, progression);
      currentPose[pos.first] = currentTransform->getLocalTransform();
    }
    return currentPose;
  }

}
