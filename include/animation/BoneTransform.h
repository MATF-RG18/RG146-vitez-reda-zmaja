////////////////////////////////////////////////////////////////////////////////
/// @file BoneTransform.h
/// @brief Deklaracija klase BoneTransform.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _BONE_TRANSFORM_H_
#define _BONE_TRANSFORM_H_

// Ukljucivanje biblioteka
#include <glm/gtc/quaternion.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <stdio.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena animation.
/// Sadrzi sve klase, funkcije i promenljive za rad sa animacajima modela.
////////////////////////////////////////////////////////////////////////////////
namespace animation {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa BoneTransform sadrzi informacije o transformaciji koske.
  /// Pomocu klase BoneTransform cuvamo podatke o translaciji i rotaciji
  /// koje treba primeniti na kosku u vidu matrice transformacije.
  //////////////////////////////////////////////////////////////////////////////
  class BoneTransform {

  // Privatne promenljive klase.
  private:
    /// Pozicija koske u trenutnoj pozi.
    vec3 position;

    /// Rotacija koske u trenutnoj pozi izrazena pomocu kvaterniona.
    quat rotation;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param position  Pozicija koske u trenutnoj pozi.
    /// @param rotation Rotacija koske izrazena pomocu kvaterniona.
    ////////////////////////////////////////////////////////////////////////////
    BoneTransform(vec3 position, quat rotation);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~BoneTransform();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira matricu transformacije.
    /// U funkciji se pomocu trenutne pozicije i rotacije koske racuna matrica
    /// transformacije koja je definisana u odnosu na koordinatni sistem koske.
    /// @param void
    /// @return mat4 Matrica transformacije.
    ////////////////////////////////////////////////////////////////////////////
    mat4 getLocalTransform();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna interpolisanu poziciju i rotaciju.
    /// U funkciji se racunaju interpolisana pozicija i rotacija sa zadatim
    /// faktorom progresije.
    /// @param frameA Pokazivaca na instancu klase BoneTransform.
    /// @param frameB Pokazivaca na instancu klase BoneTransform.
    /// @param progression Procenat progresije u intervalu [0,1].
    /// @return BoneTransform * Pokazivaca na instancu klase BoneTransform.
    ////////////////////////////////////////////////////////////////////////////
    BoneTransform *interpolate(BoneTransform *frameA, BoneTransform *frameB, float progression);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna interpolisanu poziciju.
    /// U funkciji se racunaja interpolisana pozicija sa zadatim faktorom
    /// progresije.
    /// @param start Pocetna pozicija koske.
    /// @param end Krajnja pozicija koske.
    /// @param progression Procenat progresije u intervalu [0,1].
    /// @return vec3 Interpolisana pozicija.
    ////////////////////////////////////////////////////////////////////////////
    vec3 interpolate(vec3 start, vec3 end, float progression);
  };

} // animation

#endif
