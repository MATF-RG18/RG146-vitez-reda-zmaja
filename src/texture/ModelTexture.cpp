#include "../../include/texture/ModelTexture.h"

// Klasa je implementirana po uzoru na video tutorijal 
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace texture {

  ModelTexture::ModelTexture(int id) {

    this->textureID = id;
    this->shine = 1;
    this->reflectivity = 0;
    this->hasTransparency = false;
    this->useFakeLightning = false;
  }

  ModelTexture::~ModelTexture() {

  }

  int ModelTexture::getID() {

    return this->textureID;
  }

  float ModelTexture::getShine() {
    
    return this->shine;
  }

  float ModelTexture::getReflectivity() {

    return this->reflectivity;
  }

  bool ModelTexture::getHasTransparency() {

    return this->hasTransparency;
  }

  bool ModelTexture::getUseFakeLightning() {

    return this->useFakeLightning;
  }

  void ModelTexture::setShine(float shine) {

    this->shine = shine;
  }

  void ModelTexture::setReflectivity(float reflectivity) {
    
    this->reflectivity = reflectivity;
  }

  void ModelTexture::setHasTransparency(bool transparency) {

    this->hasTransparency = transparency;
  }

  void ModelTexture::setUseFakeLightning(bool lightning) {

    this->useFakeLightning = lightning;
  }

} // texture
