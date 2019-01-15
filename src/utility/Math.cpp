#include "../../include/utility/Math.h"

  // Uz pomoc http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/
  // i https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

  mat4 createTransformationMatrix(vec3 translation, vec3 rotation, float scaleFactor) {

    mat4 transformationMatrix = mat4(1.0f);

    transformationMatrix = translate(transformationMatrix, translation);

    transformationMatrix = rotate(transformationMatrix, radians(rotation.x), vec3(1,0,0));

    transformationMatrix = rotate(transformationMatrix, radians(rotation.y), vec3(0,1,0));

    transformationMatrix = rotate(transformationMatrix, radians(rotation.z), vec3(0,0,1));
  
    transformationMatrix = scale(transformationMatrix, vec3(scaleFactor, scaleFactor, scaleFactor));

    return transformationMatrix;
  }

  mat4 createViewMatrix(vec3 position, float pich, float yaw) {

    mat4 viewMatrix = mat4(1.0);

    viewMatrix = rotate(viewMatrix, radians(pich), vec3(1,0,0));

    viewMatrix = rotate(viewMatrix, radians(yaw), vec3(0,1,0));

    vec3 negativePosition(-position.x, -position.y, -position.z);

    viewMatrix = translate(viewMatrix, negativePosition);

    
    return viewMatrix;

  }

  float barryCentric(vec3 p1, vec3 p2, vec3 p3, vec2 position){
    
    float det = (p2.z - p3.z)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.z - p3.z);
    float l1 = ((p2.z - p3.z)*(position.x - p3.x) + (p3.x - p2.x)*(position.y - p3.z))/det;
    float l2 = ((p3.z - p1.z)*(position.x - p3.x) + (p1.x - p3.x)*(position.y - p3.z))/det;
    float l3 = 1 - l1 - l2;
    return l1*p1.y + l2*p2.y + l3*p3.y;
  }


