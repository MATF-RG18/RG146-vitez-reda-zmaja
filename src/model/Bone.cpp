#include "../../include/model/Bone.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

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
