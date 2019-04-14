////////////////////////////////////////////////////////////////////////////////
/// @file FontData.h
/// @brief Deklaracija klase FontData.
/// @author Dusan Pantelic
/// @date April 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONT_DATA_H_
#define _FONT_DATA_H_

// Ukljucivanje biblioteka
#include <glm/vec2.hpp>

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena font.
/// Sadrzi sve klase, funkcije i promenljive za rad sa tekstom.
////////////////////////////////////////////////////////////////////////////////
namespace font {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa FontData odredjuje karakter.
    /// Klasa FontData cuva informacije o grafickoj reprezentaciji karaktera.
    //////////////////////////////////////////////////////////////////////////////
    class FontData {

    // Javne promenljive klase.
    public:
        /// Identifikator teksture.
        GLuint textureID;

        /// Vektor velcine karaktera.
        vec2 size;

        /// Vektor pozicija bitmape u odnosu na kvadrat u kome se karakter iscrtava.
        vec2 bearing;

        /// Horizontalna razdaljina do mesta gde se sledeci karakter iscrtava.
        GLuint advance;

    // Javne funkcije klase.
    public:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// @param textureID Identifikator teksture.
        /// @param size Vektor velcine karaktera.
        /// @oaram bearing Vektor pozicija bitmape.
        /// @param advance Razdaljina do mesta gde se sledeci karakter iscrtava.
        ////////////////////////////////////////////////////////////////////////////
        FontData(GLuint textureID, vec2 size, vec2 bearing, GLuint advance);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~FontData();
    };
} // font

#endif
