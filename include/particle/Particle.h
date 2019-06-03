////////////////////////////////////////////////////////////////////////////////
/// @file Particle.h
/// @brief Deklaracija klase Particle.
/// @author Dusan Pantelic
/// @date Jun 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../utility/FpsData.h"

// Ukljucivanje biblioteka.
#include <glm/vec3.hpp>
#include <stdio.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;
using namespace utility;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena particle.
/// Sadrzi sve klase, funkcije i promenljive koje su vezane za sistem cestica.
////////////////////////////////////////////////////////////////////////////////
namespace particle {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Particle opisuje jednu cesticu.
  /// Cestica je opisana pozicijom, brzinom, efektom gravitacije, duzinom zivotnog
  /// veka, rotacijom i faktorom skaliranja.
  //////////////////////////////////////////////////////////////////////////////
  class Particle {

  // Privatne promenljive klase.
  private:
    /// Pozicija cestice.
    vec3 position;

    /// Brzina cestice.
    vec3 speed;

    /// Efekat gravitacije.
    float gravity;

    /// Duzina zivotnog veka.
    float lifeLength;

    /// Trenutno vreme zivota.
    float currentLifeTime;

    /// Rotacija cestice.
    float rotation;

    /// Faktor skaliranja cestice.
    float scale;

    /// Pokazivac na instancu klase FpsData.
    FpsData *fpsData;

  // Javne funkcije klase.
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// U konstruktoru se cestici pridruzuje pozicija, brzi na, efektgravitacije,
    /// duzina zivotnog veka, rotacija i faktor skaliranja.
    /// @param position Pozicija cestice.
    /// @param speed Brzina cestice.
    /// @param gravity Efekat gravitacije.
    /// @param lifeLength Duzina zivotnog veka.
    /// @param rotation Rotacija cestice.
    /// @param scale Faktor skaliranja cestice.
    /// @param fpsData Pokazivac na instancu klase FpsData.
    ////////////////////////////////////////////////////////////////////////////
    Particle(vec3 position, vec3 speed, float gravity, float lifeLength, float rotation, float scale, FpsData *fpsData);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Particle();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca poziciju cestice
    /// @param void
    /// @return vec3 Pozicija cestice.
    ////////////////////////////////////////////////////////////////////////////
    vec3 getPosition();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca rotaciju cestice
    /// @param void
    /// @return float Rotacija cestice.
    ////////////////////////////////////////////////////////////////////////////
    float getRotation();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca faktor skaliranja cestice
    /// @param void
    /// @return float Faktor skaliranja cestice.
    ////////////////////////////////////////////////////////////////////////////
    float getScale();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija azurira poziciju cestice i trenutno vreme zivotnog veka
    /// @param void
    /// @return bool Da li je zivotni vek cestice zavrsen.
    ////////////////////////////////////////////////////////////////////////////
    bool update();
  };

} // particle

#endif
