#include "../../include/model/Bone.h"

namespace model {

  Bone::Bone(int ID, string name, mat4 inverseBindTransform) {

      this->ID = ID;
      this->name = name;
      this->inverseBindTransform = inverseBindTransform;
      this->animatedTransform = mat4(1.0f);
  }

  Bone::~Bone() {

  }

  void Bone::addChild(Bone *child) {

    this->childrens.push_back(child);
  }

  int Bone::getID() {

    return this->ID;
  }

  vector<Bone*> Bone::getChildrens() {

    return this->childrens;
  }

  string Bone::getName() {

    return this->name;
  }

  mat4 Bone::getAnimatedTransform() {

    return this->animatedTransform;
  }

  void Bone::setAnimatedTransform(mat4 animatedTransform) {

    this->animatedTransform = animatedTransform;
  }

  mat4 Bone::getInverseBindTransform() {

    return this->inverseBindTransform;
  }

}
