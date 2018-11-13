#include "../../include/model/RawModel.h"


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
