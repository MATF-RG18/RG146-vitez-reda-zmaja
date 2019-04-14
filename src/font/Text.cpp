#include "../../include/font/Text.h"

namespace font {

  Text::Text(Font *font, string text, vec2 position, vec2 scale, float rotation, vec3 color) {

    this->font = font;
    this->text = text;
    this->position = position;
    this->scale = scale;
    this->rotation = rotation;
    this->color = color;
  }

  Text::~Text() {

  }

  void Text::setFont(Font *font) {

    this->font = font;
  }

  void Text::setText(string text) {

    this->text = text;
  }

  void Text::setPosition(vec2 position) {

    this->position = position;
  }

  void Text::setScale(vec2 scale) {

    this->scale = scale;
  }

  void Text::setRotation(float rotation) {

    this->rotation = rotation;
  }

  void Text::setColor(vec3 color) {

    this->color = color;
  }

  Font *Text::getFont() {

    return this->font;
  }

  string Text::getText() {

    return this->text;
  }

  vec2 Text::getPosition() {

    return this->position;
  }

  vec2 Text::getScale() {

    return this->scale;
  }

  float Text::getRotation() {

    return this->rotation;
  }

  vec3 Text::getColor() {

    return this->color;
  }

}
