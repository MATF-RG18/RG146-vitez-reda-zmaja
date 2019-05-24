#ifndef _BONE_H_
#define _BONE_H_

#include <string>
#include <vector>
#include <glm/matrix.hpp>

using namespace std;
using namespace glm;

namespace model {

    class Bone {
    private:
        int ID;
        string name;
        vector<Bone*> childrens;
        mat4 animatedTransform;
        mat4 localBindTransform;
        mat4 inverseBindTransform;
    public:
        Bone(int ID, string name, mat4 localBindTransform);
        ~Bone();
        void addChild(Bone *child);
        int getID();
        vector<Bone*> getChildrens();
        string getName();
        mat4 getAnimatedTransform();
        void setAnimatedTransform(mat4 animatedTransform);
        mat4 getInverseBindTransform();
        void calculateInverseBindTransform(mat4 parentTransform);

    };
}



#endif
