#include "../../include/model/AnimatedModel.h"

// Klasa je implementirana po uzoru na video tutorijal:
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
// i internet stranice i clanke:
// http://ogldev.atspace.co.uk/www/tutorial38/tutorial38.html
// https://bib.irb.hr/datoteka/890911.Final_0036473606_56.pdf

namespace model {

    AnimatedModel::AnimatedModel(TexturedModel *model, vector<Bone *> rootNodes, vector<int> bonesCount) {

        this->model = model;
        this->rootNodes = rootNodes;
        this->bonesCount = bonesCount;
        this->numRootNodes = rootNodes.size();
    }

    AnimatedModel::~AnimatedModel() {

    }

    TexturedModel *AnimatedModel::getModel() {

        return this->model;
    }

    Bone *AnimatedModel::getRootNode(int rootBoneID) {

        return this->rootNodes[rootBoneID];
    }


    mat4 *AnimatedModel::getBoneTransforms(int rootBoneID) {

        Bone *rootNode = this->rootNodes[rootBoneID];
        mat4 *boneMatrices = (mat4 *)malloc(this->bonesCount[rootBoneID] * sizeof(mat4));
        if (rootNode == nullptr) {
          return nullptr;
        }
        addBones(rootNode, boneMatrices);
        return boneMatrices;

    }

    void AnimatedModel::addBones(Bone *headBone, mat4* boneMatrices) {

        boneMatrices[headBone->getID()] = headBone->getAnimatedTransform();
        for(Bone *child : headBone->getChildrens()) {
            addBones(child, boneMatrices);
        }
    }

    Animation *AnimatedModel::getAnimation(string animationName) {

      if(this->animations.find(animationName) != animations.end()) {
        return animations[animationName];
      }

      return nullptr;
    }

    void AnimatedModel::addAnimation(string animationName, Animation *animation) {

      this->animations[animationName] = animation;
    }

    int AnimatedModel::getNumRootNodes() {

      return this->numRootNodes;
    }
}
