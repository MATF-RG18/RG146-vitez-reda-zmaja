#include "../../include/model/RawModel.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace model {

  RawModel::RawModel(int vaoID, int vertexCount) {

    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
  }

  RawModel::~RawModel() {

  }

  int RawModel::getVaoID(void) {

    return vaoID;
  }

  int RawModel::getVertexCount(void) {

    return vertexCount;
  }

} // model
