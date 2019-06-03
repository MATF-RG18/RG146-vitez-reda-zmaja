////////////////////////////////////////////////////////////////////////////////
/// @file WeatherSystem.h
/// @brief Deklaracija klase WeatherSystem.
/// @author Dusan Pantelic
/// @date Jun 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _WEATHER_SYSTEM_H_
#define _WEATHER_SYSTEM_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../particle/ParticleHandler.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena particle.
/// Sadrzi sve klase, funkcije i promenljive koje su vezane za sistem cestica.
////////////////////////////////////////////////////////////////////////////////
namespace particle {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa WeatherSystem kontrolise stvaranje cestica i njihovo ponasanje.
  /// Pomocu klase WeatherSystem simuliramo padavine kreiranjem cestica u
  /// prostoru definisanom dimenzijama i centrom oblaka.
  //////////////////////////////////////////////////////////////////////////////
  class WeatherSystem {

  // Privatne promenljive klase
  private:
    /// Broj cestica koje se generisu po sekundi.
    float particlesPerSecond;

    /// Intenzitet padavina.
    float fallIntensity;

    /// Duzina zivotnog veka cestice.
    float lifeLength;

    /// Velicina oblaka.
    float cloudSize;

    /// Pokazivac na instancu klase ParticleHandler.
    ParticleHandler *particleHandler;

    /// Pokazivac na instancu klase FpsData.
    FpsData *fpsData;

    /// Pokazivac na instancu klase Texture.
    Texture *texture;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param particlesPerSecond Broj cestica koje se generisu po sekundi.
    /// @param fallIntensity Intenzitet padavina.
    /// @param lifeLength Duzina zivotnog veka.
    /// @param cloudSize Velicina oblaka.
    /// @param fpsData Pokazivac na instancu klase FpsData.
    /// @param texture Pokazivac na instancu klase Texture.
    ////////////////////////////////////////////////////////////////////////////
    WeatherSystem(float particlesPerSecond, float fallIntensity, float lifeLength, float cloudSize, FpsData *fpsData, Texture *texture);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~WeatherSystem();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija generise nove cestice i dodaje ih u listu cestica.
    /// @param particleHandler Pokazivac na instancu klase ParticleHandler.
    /// @param cloudCenter Centar oblaka.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void generateParticles(ParticleHandler *particleHandler, vec3 cloudCenter);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja teksturu cestica.
    /// @param texture Pokazivac na instancu klase Texture.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setTexture(Texture *texture);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca teksturu cestica.
    /// @param void
    /// @return Texture * Pokazivac na instancu klase Texture.
    ////////////////////////////////////////////////////////////////////////////
    Texture *getTexture();
  };

} // particle

#endif
