#include "../../include/animation/Animation.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

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
