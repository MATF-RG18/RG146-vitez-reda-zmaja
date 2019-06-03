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
        vector<Bone *> rootNodes;
        vector<int> bonesCount;
        map<string, Animation*> animations;
        int numRootNodes;
    public:
        AnimatedModel(TexturedModel *model, vector<Bone *> rootNodes, vector<int> bonesCount);
        ~AnimatedModel();
        TexturedModel *getModel();
        Bone *getRootNode(int rootBoneID);
        mat4 *getBoneTransforms(int rootBoneID);
        void addBones(Bone *headBone, mat4 *boneMatrices);
        Animation *getAnimation(string animationName);
        void addAnimation(string animationName, Animation *animation);
        int getNumRootNodes();
    };

} // modeln


#endif
