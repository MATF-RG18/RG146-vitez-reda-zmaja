#include "../../include/model/TexturedModel.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace model {

  TexturedModel::TexturedModel(RawModel *model, ModelTexture *texture) {

    this->rawModel = model;
    this->texture = texture;
  }

  TexturedModel::~TexturedModel() {

  }

  RawModel TexturedModel::getRawModel(void) {

    return *rawModel;
  }

  ModelTexture *TexturedModel::getTexture(void) {

    return texture;
  }

} // model
