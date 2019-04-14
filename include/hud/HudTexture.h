////////////////////////////////////////////////////////////////////////////////
/// @file HudTexture.h
/// @brief Deklaracija klase HudTexture.
/// @author Dusan Pantelic
/// @date Mart 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _HUD_TEXTURE_
#define _HUD_TEXTURE_

// Ukljucivanje biblioteka
#include <glm/vec2.hpp>

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena hud.
/// Sadrzi sve klase, funkcije i promenljive za rad sa 2D grafikom.
////////////////////////////////////////////////////////////////////////////////
namespace hud {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa HudTexture odredjuje teksture 2D grafike.
  /// Pomocu klase Font cuvamo podatke o teksturi i pozicioniranju 2D grafike
  /// u igri.
  //////////////////////////////////////////////////////////////////////////////
    class HudTexture {
        // Privatne promenljive klase
        private:

        /// Identifikator teksture.
        GLint textureID;

        /// Pozicija.
        vec2 position;

        /// Vrednost skaliranja po X i Y osi.
        vec2 scale;

        /// Vrednost rotacije po Z osi.
        float rotation;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param textureID Identifikator teksture.
            /// @param position Pozicija.
            /// @param scale Vrednost skaliranja po X i Y osi.
            /// @param rotation Vrednost rotacije po Z osi.
            ////////////////////////////////////////////////////////////////////////////
            HudTexture(int textureID, vec2 position, vec2 scale, float rotation);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~HudTexture();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive textureID.
            /// @param void
            /// @return int Identifikator teksture.
            ////////////////////////////////////////////////////////////////////////////
            int getTextureID();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive position.
            /// @param void
            /// @return vec2 Pozicija.
            ////////////////////////////////////////////////////////////////////////////
            vec2 getPosition();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive scale.
            /// @param void
            /// @return vec2 Vrednost skaliranja po X i Y osi.
            ////////////////////////////////////////////////////////////////////////////
            vec2 getScale();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive rotation.
            /// @param void
            /// @return vec2 Vrednost rotacije po Z osi.
            ////////////////////////////////////////////////////////////////////////////
            float getRotation();
    };
} // hud

#endif
