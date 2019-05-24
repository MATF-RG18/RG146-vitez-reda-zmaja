#include "../../include/animation/BoneTransform.h"

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
      matrix = matrixCompMult(matrix, toMat4(this->rotation));
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
