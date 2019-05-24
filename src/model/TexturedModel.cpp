#include "../../include/model/TexturedModel.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace model {

  TexturedModel::TexturedModel(RawModel *model, vector<Texture *> textures) {

    this->rawModel = model;
    this->textures = textures;
  }

  TexturedModel::~TexturedModel() {

  }

  RawModel *TexturedModel::getRawModel(void) {

    return this->rawModel;
  }

  vector<Texture *> TexturedModel::getTextures(void) {

    return this->textures;
  }

} // model
