#include "../../include/model/AnimatedModel.h"

namespace model {

    AnimatedModel::AnimatedModel(TexturedModel *model, Bone *rootNode, int boneCount) {

        this->model = model;
        this->rootNode = rootNode;
        this->boneCount = boneCount;
        rootNode->calculateInverseBindTransform(mat4(1.0f));
    }

    AnimatedModel::~AnimatedModel() {

    }

    TexturedModel *AnimatedModel::getModel() {

        return this->model;
    }

    Bone *AnimatedModel::getRootNode() {

        return this->rootNode;
    }


    mat4 *AnimatedModel::getBoneTransforms() {

        mat4 *boneMatrices = (mat4 *)malloc(this->boneCount * sizeof(mat4));
        addBones(this->rootNode, boneMatrices);
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
}
