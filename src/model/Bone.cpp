#include "../../include/model/Bone.h"

namespace model {

  Bone::Bone(int ID, string name, mat4 localBindTransform) {

      this->ID = ID;
      this->name = name;
      this->localBindTransform = localBindTransform;
      this->animatedTransform = mat4(1.0f);
      this->inverseBindTransform = mat4(1.0f);
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

  void Bone::calculateInverseBindTransform(mat4 parentTransform) {

    mat4 bindTransform = matrixCompMult(parentTransform, this->localBindTransform);
    this->inverseBindTransform = inverse(bindTransform);
    for(Bone* child: this->childrens) {
      child->calculateInverseBindTransform(bindTransform);
    }
  }
}
