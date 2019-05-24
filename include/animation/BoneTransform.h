#ifndef _BONE_TRANSFORM_H_
#define _BONE_TRANSFORM_H_

#include <glm/gtc/quaternion.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include <stdio.h>
using namespace glm;

namespace animation {

  class BoneTransform {
  private:
    vec3 position;
    quat rotation;
  public:
    BoneTransform(vec3 position, quat rotation);
    ~BoneTransform();
    mat4 getLocalTransform();
    BoneTransform *interpolate(BoneTransform *frameA, BoneTransform *frameB, float progression);
    vec3 interpolate(vec3 start, vec3 end, float progression);
  };

}

#endif
