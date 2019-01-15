#include "../../include/core/ObjLoader.h"

#define TINYOBJLOADER_IMPLEMENTATION

#include "../../include/external_libs/tiny_obj_loader.h"

using namespace tinyobj;

// Klasa je implementirana uz pomoc dokumentacije sa repozitorijuma biblioteke http://syoyo.github.io/tinyobjloader/
// i pomocu video tutorijala https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP


namespace core {

    ObjLoader::ObjLoader() {

    }

    ObjLoader::~ObjLoader() {

    }

    RawModel * ObjLoader::loadObjModel(const char *fileName, VaoLoader *vaoLoader) {
      vector <int> indices;
      float *verticesArray = NULL;
      float *texturesArray = NULL;
      float *normalsArray = NULL;
      int *indicesArray = NULL;
     
      attrib_t attrib;
      vector<shape_t> shapes;
      vector<material_t> materials;
      std::string error;

      bool ret = LoadObj(&attrib, &shapes, &materials, &error, fileName);


      verticesArray = new float[attrib.vertices.size()];
      texturesArray = new float[attrib.vertices.size()/3*2];
      normalsArray = new float[attrib.vertices.size()];

      for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {

            indices.push_back(index.vertex_index);

            texturesArray[index.vertex_index*2] = attrib.texcoords[2 * index.texcoord_index + 0];
            texturesArray[index.vertex_index*2 + 1] = attrib.texcoords[2 * index.texcoord_index + 1];

            normalsArray[index.vertex_index*3] = attrib.normals[3*index.normal_index + 0];
            normalsArray[index.vertex_index*3 + 1] = attrib.normals[3*index.normal_index + 1];
            normalsArray[index.vertex_index*3 + 2] = attrib.normals[3*index.normal_index + 2];
        }
      }

      indicesArray = new int[indices.size()];
      for (int i = 0; i < indices.size(); i++) {
        indicesArray[i] = indices[i];
      }

      for(int i =0; i < attrib.vertices.size(); i++) {
        verticesArray[i] = attrib.vertices[i];
      }

      return vaoLoader->loadToVao(verticesArray, attrib.vertices.size(),
                                  indicesArray, indices.size(),
                                  texturesArray, attrib.texcoords.size(),
                                  normalsArray, attrib.normals.size()*3);
    }
} /* core */
