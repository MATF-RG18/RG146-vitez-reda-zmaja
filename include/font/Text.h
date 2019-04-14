////////////////////////////////////////////////////////////////////////////////
/// @file Text.h
/// @brief Deklaracija klase Text.
/// @author Dusan Pantelic
/// @date April 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXT_H_
#define _TEXT_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../font/Font.h"

// Ukljucivanje biblioteka
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena font.
/// Sadrzi sve klase, funkcije i promenljive za rad sa tekstom.
////////////////////////////////////////////////////////////////////////////////
namespace font {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Text odredjuje tekst sa njegovim osobinama.
  /// Pomocu klase Text cuvamo podatke o tekstu kao i njegove osobine poput
  /// boje i pozicije u svetu koje kasnije koristimo za iscrtavanje teksta.
  //////////////////////////////////////////////////////////////////////////////
  class Text {

  // Privatne promenljive klase.
  private:
    /// Pokazivac na instancu klase Font.
    Font *font;

    /// Niska koju treba iscrtati.
    string text;

    /// Pozicija prvog karaktera niske u svetu.
    vec2 position;

    /// Sklaliranje po X i Y osi.
    vec2 scale;

    /// Rotacija teksta po Z osi.
    float rotation;

    /// Boja teksta u RGB formatu.
    vec3 color;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param font Pokazivac na instancu klase Font.
    /// @param text Niska koju treba iscrtati.
    /// @param position Pozicija prvog karaktera niske u svetu.
    /// @param scale Sklaliranje po X i Y osi.
    /// @param Rotacija teksta po Z osi.
    /// @param color Boja teksta u RGB formatu.
    ////////////////////////////////////////////////////////////////////////////
    Text(Font *font, string text, vec2 position, vec2 scale, float rotation, vec3 color);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Text();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive font.
    /// @param font Pokazivac na instancu klase Font.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setFont(Font *font);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive text.
    /// @param text Niska koju treba iscrtati.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setText(string text);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive position.
    /// @param position Pozicija prvog karaktera niske u svetu.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setPosition(vec2 position);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive scale.
    /// @param scale Sklaliranje po X i Y osi.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setScale(vec2 scale);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive rotation.
    /// @param rotation Rotacija po Z osi.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setRotation(float rotation);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja vrednost privatne promenljive color.
    /// @param color Boja teksta u RGB formatu.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void setColor(vec3 color);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive font.
    /// @param void
    /// @return Font * Pokazivac na instancu klase Font.
    ////////////////////////////////////////////////////////////////////////////
    Font *getFont();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive text.
    /// @param void
    /// @return string Niska koju treba iscrtati.
    ////////////////////////////////////////////////////////////////////////////
    string getText();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive position.
    /// @param void
    /// @return vec2 Pozicija prvog karaktera niske u svetu.
    ////////////////////////////////////////////////////////////////////////////
    vec2 getPosition();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive scale.
    /// @param void
    /// @return vec2 Sklaliranje po X i Y osi.
    ////////////////////////////////////////////////////////////////////////////
    vec2 getScale();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive rotation.
    /// @param void
    /// @return float Rotacija po Z osi.
    ////////////////////////////////////////////////////////////////////////////
    float getRotation();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive color.
    /// @param void
    /// @return vec3 Boja teksta u RGB formatu.
    ////////////////////////////////////////////////////////////////////////////
    vec3 getColor();
  };
} // font

#endif
