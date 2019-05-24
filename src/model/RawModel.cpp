#include "../../include/model/RawModel.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace model {

  RawModel::RawModel(vector<GLint> meshesVaoID, vector<GLint> meshesVertexCount) {

    this->meshesVaoID = meshesVaoID;
    this->meshesVertexCount = meshesVertexCount;
  }

  RawModel::~RawModel() {

  }

  vector<GLint> RawModel::getMeshesVaoID(void) {

    return this->meshesVaoID;
  }

  vector<GLint> RawModel::getMeshesVertexCount(void) {

    return this->meshesVertexCount;
  }

} // model
