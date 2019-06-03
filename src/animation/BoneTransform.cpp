#include "../../include/animation/BoneTransform.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

namespace animation {

  BoneTransform::BoneTransform(vec3 position, quat rotation) {

    this->position = position;
    this->rotation = rotation;
  }

  BoneTransform::~BoneTransform() {

  }

  mat4 BoneTransform::getLocalTransform() {

      mat4 matrix(1.0f);
      matrix = translate(matrix, this->position);
      matrix = matrix * toMat4(this->rotation);
      return matrix;
  }

  BoneTransform *BoneTransform::interpolate(BoneTransform *frameA, BoneTransform *frameB, float progression) {

    vec3 pos = interpolate(frameA->position, frameB->position, progression);
    quat rot = lerp(frameA->rotation, frameB->rotation, progression);
    return new BoneTransform(pos, rot);
  }

  vec3 BoneTransform::interpolate(vec3 start, vec3 end, float progression) {

    float x = start.x + (end.x - start.x)*progression;
    float y = start.y + (end.y - start.y)*progression;
    float z = start.z + (end.z - start.z)*progression;
    return vec3(x,y,z);
  }

}
