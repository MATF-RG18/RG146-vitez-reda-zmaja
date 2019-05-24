#ifndef _LOADER_H_
#define _LOADER_H_

#define MAX_BONES_PER_VERTEX 4

#include "../model/AnimatedModel.h"
#include "../animation/Animation.h"
#include "../core/VaoLoader.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <map>
#include <glm/mat4x4.hpp>
#include "glm/ext.hpp"

using namespace Assimp;
using namespace glm;

namespace core {

  class Loader {
  private:
    map<string, int> bonesMap;
  public:
    Loader();
    ~Loader();
    AnimatedModel *loadAnimatedModel(const char *fileName, VaoLoader *vaoLoader);
    TexturedModel *loadTexturedModel(const char *fileName, VaoLoader *vaoLoader);
    RawModel *loadRawModel(const char *fileName, VaoLoader *vaoLoader);
  private:
    Texture *loadMaterial(aiMaterial *material, const char *fileName, VaoLoader *vaoLoader);
    void loadBoneData(aiMesh *mesh, vector<int> &boneIndices, vector<float> &weights);
    Bone *loadBoneHierarchy(aiNode *rootBone, aiMesh *mesh);
    void findRootBone(aiNode *node, aiNode *&rootBone);
    void loadAnimation(AnimatedModel *animatedModel, const aiScene *scene);
    mat4 convertAiMatrix(aiMatrix4x4 aiMatrix);

  };

}

#endif
