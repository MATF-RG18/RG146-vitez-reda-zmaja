#include "../../include/core/Loader.h"

namespace core {

  Loader::Loader() {

  }

  Loader::~Loader() {

  }

  AnimatedModel *Loader::loadAnimatedModel(const char *fileName, VaoLoader *vaoLoader) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(fileName, aiProcess_Triangulate);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
      printf("[!]Err: (Assimp) %s\n",importer.GetErrorString());
    }

    vector<GLint> meshesVaoID;
    vector<GLint> meshesVertexCount;
    vector<Texture *> textures;

    Bone *rootNode = nullptr;

    for(int i = 0; i < scene->mNumMeshes; i++) {
      aiMesh *mesh = scene->mMeshes[i];

      textures.push_back(loadMaterial(scene->mMaterials[mesh->mMaterialIndex], fileName, vaoLoader));

      vector<float> vertices;
      vector<float> texCoords;
      vector<float> normals;
      vector<int> indices;
      vector<int> boneIndices(mesh->mNumVertices * 4);
      vector<float> weights(mesh->mNumVertices * 4);

      loadBoneData(mesh, boneIndices, weights);

      aiNode *rootBone = nullptr;

      findRootBone(scene->mRootNode, rootBone);

      rootNode = loadBoneHierarchy(rootBone, mesh);

      for (int j = 0; j < mesh->mNumVertices; j++) {
        vertices.push_back(mesh->mVertices[j].x);
        vertices.push_back(mesh->mVertices[j].y);
        vertices.push_back(mesh->mVertices[j].z);

        normals.push_back(mesh->mNormals[j].x);
        normals.push_back(mesh->mNormals[j].y);
        normals.push_back(mesh->mNormals[j].z);

        texCoords.push_back(mesh->mTextureCoords[0][j].x);
        texCoords.push_back(mesh->mTextureCoords[0][j].y);
      }

      for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
      }


      GLint vaoID = vaoLoader->loadToVao(&vertices[0], vertices.size(),
                                  &indices[0], indices.size(),
                                  &texCoords[0], texCoords.size(),
                                  &normals[0], normals.size(),
                                  &boneIndices[0], boneIndices.size(),
                                  &weights[0], weights.size());
      meshesVaoID.push_back(vaoID);
      meshesVertexCount.push_back(indices.size());
    }

    TexturedModel *texturedModel = new TexturedModel(new RawModel(meshesVaoID, meshesVertexCount), textures);

    AnimatedModel *animatedModel = new AnimatedModel(texturedModel, rootNode, this->bonesMap.size());

    loadAnimation(animatedModel, scene);

    return animatedModel;
  }

  TexturedModel *Loader::loadTexturedModel(const char *fileName, VaoLoader *vaoLoader) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(fileName, aiProcess_Triangulate);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
      printf("[!]Err: (Assimp) %s\n",importer.GetErrorString());
    }

    vector<GLint> meshesVaoID;
    vector<GLint> meshesVertexCount;
    vector<Texture *> textures;

    for(int i = 0; i < scene->mNumMeshes; i++) {
      aiMesh *mesh = scene->mMeshes[i];

      textures.push_back(loadMaterial(scene->mMaterials[mesh->mMaterialIndex], fileName, vaoLoader));

      vector<float> vertices;
      vector<float> texCoords;
      vector<float> normals;
      vector<int> indices;

      for (int j = 0; j < mesh->mNumVertices; j++) {
        vertices.push_back(mesh->mVertices[j].x);
        vertices.push_back(mesh->mVertices[j].y);
        vertices.push_back(mesh->mVertices[j].z);

        normals.push_back(mesh->mNormals[j].x);
        normals.push_back(mesh->mNormals[j].y);
        normals.push_back(mesh->mNormals[j].z);

        texCoords.push_back(mesh->mTextureCoords[0][j].x);
        texCoords.push_back(mesh->mTextureCoords[0][j].y);
      }

      for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
      }


      GLint vaoID = vaoLoader->loadToVao(&vertices[0], vertices.size(),
                                  &indices[0], indices.size(),
                                  &texCoords[0], texCoords.size(),
                                  &normals[0], normals.size());
      meshesVaoID.push_back(vaoID);
      meshesVertexCount.push_back(indices.size());
    }

    return new TexturedModel(new RawModel(meshesVaoID, meshesVertexCount), textures);
  }

  RawModel *Loader::loadRawModel(const char *fileName, VaoLoader *vaoLoader) {

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(fileName, aiProcess_Triangulate);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
      printf("[!]Err: (Assimp) %s\n",importer.GetErrorString());
    }

    vector<GLint> meshesVaoID;
    vector<GLint> meshesVertexCount;

    for(int i = 0; i < scene->mNumMeshes; i++) {
      aiMesh *mesh = scene->mMeshes[i];
      vector<float> vertices;
      vector<float> texCoords;
      vector<float> normals;
      vector<int> indices;

      for (int j = 0; j < mesh->mNumVertices; j++) {
        vertices.push_back(mesh->mVertices[j].x);
        vertices.push_back(mesh->mVertices[j].y);
        vertices.push_back(mesh->mVertices[j].z);

        normals.push_back(mesh->mNormals[j].x);
        normals.push_back(mesh->mNormals[j].y);
        normals.push_back(mesh->mNormals[j].z);

        texCoords.push_back(mesh->mTextureCoords[0][j].x);
        texCoords.push_back(mesh->mTextureCoords[0][j].y);
      }

      for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
      }

      GLint vaoID = vaoLoader->loadToVao(&vertices[0], vertices.size(),
                                  &indices[0], indices.size(),
                                  &texCoords[0], texCoords.size(),
                                  &normals[0], normals.size());
      meshesVaoID.push_back(vaoID);
      meshesVertexCount.push_back(indices.size());
    }

    return new RawModel(meshesVaoID, meshesVertexCount);
  }

  Texture *Loader::loadMaterial(aiMaterial *material, const char *fileName, VaoLoader *vaoLoader) {

    aiString textureFile;
    material->GetTexture(aiTextureType_DIFFUSE, 0, &textureFile);
    string texturePath(fileName);
    texturePath = texturePath.substr(0, texturePath.find_last_of("/")+1) + textureFile.C_Str();
    Texture *texture = new Texture(vaoLoader->loadTexture(texturePath.c_str()));
    texture->setShine(200);
    texture->setReflectivity(0.1);
    return texture;
  }

  void Loader::loadBoneData(aiMesh *mesh, vector<int> &boneIndices, vector<float> &weights) {

    for (int i = 0; i < mesh->mNumBones; i++) {
      this->bonesMap[string(mesh->mBones[i]->mName.C_Str())] = i;

      for (int j = 0; j < mesh->mBones[i]->mNumWeights; j++) {
        GLint vertexId = mesh->mBones[i]->mWeights[j].mVertexId;
        GLfloat weight = mesh->mBones[i]->mWeights[j].mWeight;
        GLint boneIndex = i;
        for (int k = 0; k < MAX_BONES_PER_VERTEX; k++) {
          if(weight > weights[vertexId*MAX_BONES_PER_VERTEX+k]) {
            while(k < MAX_BONES_PER_VERTEX) {
              GLfloat savedWeight = weights[vertexId*MAX_BONES_PER_VERTEX+k];
              GLint savedBoneIndex = boneIndices[vertexId*MAX_BONES_PER_VERTEX+k];
              weights[vertexId*MAX_BONES_PER_VERTEX+k] = weight;
              boneIndices[vertexId*MAX_BONES_PER_VERTEX+k] = boneIndex;
              weight = savedWeight;
              boneIndex = savedBoneIndex;
              k++;
            }
            break;
          }
        }
      }
    }
  }

  Bone *Loader::loadBoneHierarchy(aiNode *rootBone, aiMesh *mesh) {
    int boneId = this->bonesMap[rootBone->mName.C_Str()];
    string boneName = rootBone->mName.C_Str();
    mat4 offsetMatrix = convertAiMatrix(mesh->mBones[boneId]->mOffsetMatrix);
    Bone *bone = new Bone(boneId, boneName, offsetMatrix);
    for(int i = 0; i < rootBone->mNumChildren; i++) {
      bone->addChild(loadBoneHierarchy(rootBone->mChildren[i], mesh));
    }
    return bone;
  }

  void Loader::findRootBone(aiNode *node, aiNode *&rootBone) {
    if (this->bonesMap.find(node->mName.C_Str()) != this->bonesMap.end()) {
      rootBone = node;
    } else {
      for (int i = 0; i < node->mNumChildren; i++) {
        findRootBone(node->mChildren[i], rootBone);
      }
    }
  }

  void Loader::loadAnimation(AnimatedModel *animatedModel, const aiScene *scene) {

    for (int i = 0; i < scene->mNumAnimations; i++) {
      aiAnimation * animation = scene->mAnimations[i];
      float animationLength = animation->mDuration / animation->mTicksPerSecond;
      string animationName = animation->mName.C_Str();
      vector<KeyFrame *> keyFrames;
      map<float, map<string, BoneTransform*>> timeBasedMap;
      for (int j = 0; j < animation->mNumChannels; j++) {
        aiNodeAnim *animationNode = animation->mChannels[j];
        string nodeName = animationNode->mNodeName.C_Str();
        if (animationNode->mNumPositionKeys != animationNode->mNumRotationKeys) {
          printf("[!]Err: (Assimp) Unsuported animation type.\n Different number of rotations and positions keys\n");
        }
        for (int k = 0; k < animationNode->mNumPositionKeys; k++) {
          aiVectorKey positionKey = animationNode->mPositionKeys[k];
          aiQuatKey rotationKey = animationNode->mRotationKeys[k];
          if (positionKey.mTime != rotationKey.mTime) {
            printf("[!]Err: (Assimp) Unsuported animation type\n Different time stamps for rotation and positions key\n");
          }
          float timeStamp = positionKey.mTime;
          quat q(rotationKey.mValue.w, rotationKey.mValue.x, rotationKey.mValue.y, rotationKey.mValue.z);
          vec3 p(positionKey.mValue.x, positionKey.mValue.y, positionKey.mValue.z);
          BoneTransform *boneTransform = new BoneTransform(p, q);
          timeBasedMap[timeStamp][nodeName] = boneTransform;
        }
      }
      for (auto it : timeBasedMap) {
        keyFrames.push_back(new KeyFrame(it.first, it.second));
      }
      Animation *anim = new Animation(animationLength, keyFrames);
      animatedModel->addAnimation(animationName, anim);
    }
  }

  mat4 Loader::convertAiMatrix(aiMatrix4x4 aiMatrix) {

    mat4 glmMatrix;
    glmMatrix[0][0] = aiMatrix.a1;
    glmMatrix[1][0] = aiMatrix.a2;
    glmMatrix[2][0] = aiMatrix.a3;
    glmMatrix[3][0] = aiMatrix.a4;

    glmMatrix[0][1] = aiMatrix.b1;
    glmMatrix[1][1] = aiMatrix.b2;
    glmMatrix[2][1] = aiMatrix.b3;
    glmMatrix[3][1] = aiMatrix.b4;

    glmMatrix[0][2] = aiMatrix.c1;
    glmMatrix[1][2] = aiMatrix.c2;
    glmMatrix[2][2] = aiMatrix.c3;
    glmMatrix[3][2] = aiMatrix.c4;

    glmMatrix[0][3] = aiMatrix.d1;
    glmMatrix[1][3] = aiMatrix.d2;
    glmMatrix[2][3] = aiMatrix.d3;
    glmMatrix[3][3] = aiMatrix.d4;

    return transpose(glmMatrix);
  }

}
