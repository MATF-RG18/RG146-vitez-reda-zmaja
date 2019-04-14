////////////////////////////////////////////////////////////////////////////////
/// @file Math.h
/// @author Dusan Pantelic
/// @date Februar 2017
////////////////////////////////////////////////////////////////////////////////
#ifndef _MATH_H_
#define _MATH_H_

// Ukljucivanje biblioteka
#include <math.h>
#include <stdio.h>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Makro za definisanje broja PI.
#define PI 3.14159265

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;

  ////////////////////////////////////////////////////////////////////////////
  /// @brief Funkcija kreira matricu transformacije za 2D objekte.
  /// @param translation Translacija objekta.
  /// @param scaleFactor Faktor skaliranja.
  /// @param rotation Rotacija objekta.
  /// @return mat4 Matrica transformacije.
  ////////////////////////////////////////////////////////////////////////////
  mat4 createTransformationMatrix(vec2 translation, vec2 scaleFactor, float rotation);

  ////////////////////////////////////////////////////////////////////////////
  /// @brief Funkcija kreira matricu transformacije.
  /// @param translation Translacija objekta.
  /// @param rotation Rotacija objekta.
  /// @param scaleFactor Faktor skaliranja.
  /// @return mat4 Matrica transformacije.
  ////////////////////////////////////////////////////////////////////////////
  mat4 createTransformationMatrix(vec3 translation, vec3 rotation, float scaleFactor);

  ////////////////////////////////////////////////////////////////////////////
  /// @brief Funkcija kreira matricu pogleda.
  /// @param position Pozicija kamere.
  /// @param pitch Rotacija oko X ose.
  /// @param yaw Rotacija oko Y ose.
  /// @return mat4 Matrica pogleda.
  ////////////////////////////////////////////////////////////////////////////
  mat4 createViewMatrix(vec3 position, float pich, float yaw);

  ////////////////////////////////////////////////////////////////////////////
  /// @brief Funkcija interpolacijom racuna visinu unutat trougla.
  /// @param p1 Koordinate prve tacke trougla.
  /// @param p2 Koordinate druge tacke trougla.
  /// @param p3 Koordinate trece tacke trougla.
  /// @param position Koordinate tacke na trouglu za koju trazimo Y koordinatu.
  /// @return float Visina.
  ////////////////////////////////////////////////////////////////////////////
  float barryCentric(vec3 p1, vec3 p2, vec3 p3, vec2 position);


#endif
