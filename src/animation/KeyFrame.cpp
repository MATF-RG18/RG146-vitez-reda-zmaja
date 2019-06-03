#include "../../include/animation/KeyFrame.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

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
