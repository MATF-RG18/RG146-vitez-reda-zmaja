#include "../../include/texture/Texture.h"

// Klasa je implementirana po uzoru na video tutorijal
// https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP

namespace texture {

  Texture::Texture(int id) {

    this->textureID = id;
    this->shine = 1;
    this->reflectivity = 0;
    this->hasTransparency = false;
    this->useFakeLightning = false;
  }

  Texture::~Texture() {

  }

  int Texture::getID() {

    return this->textureID;
  }

  float Texture::getShine() {

    return this->shine;
  }

  float Texture::getReflectivity() {

    return this->reflectivity;
  }

  bool Texture::getHasTransparency() {

    return this->hasTransparency;
  }

  bool Texture::getUseFakeLightning() {

    return this->useFakeLightning;
  }

  void Texture::setShine(float shine) {

    this->shine = shine;
  }

  void Texture::setReflectivity(float reflectivity) {

    this->reflectivity = reflectivity;
  }

  void Texture::setHasTransparency(bool transparency) {

    this->hasTransparency = transparency;
  }

  void Texture::setUseFakeLightning(bool lightning) {

    this->useFakeLightning = lightning;
  }

} // texture
