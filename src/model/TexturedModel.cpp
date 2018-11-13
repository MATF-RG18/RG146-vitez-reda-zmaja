#include "../../include/model/TexturedModel.h"

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
