#ifndef _ANIMATED_MODEL_H_
#define _ANIMATED_MODEL_H_

#include "../model/TexturedModel.h"
#include "../model/Bone.h"
#include "../animation/Animation.h"

#include <map>

using namespace std;
using namespace animation;

namespace model {
    class AnimatedModel {
    private:
        TexturedModel *model;
        Bone *rootNode;
        int boneCount;
        map<string, Animation*> animations;
    public:
        AnimatedModel(TexturedModel *model, Bone *rootNode, int boneCount);
        ~AnimatedModel();
        TexturedModel *getModel();
        Bone *getRootNode();
        mat4 *getBoneTransforms();
        void addBones(Bone *headBone, mat4 *boneMatrices);
        Animation *getAnimation(string animationName);
        void addAnimation(string animationName, Animation *animation);
    };

} // modeln


#endif
