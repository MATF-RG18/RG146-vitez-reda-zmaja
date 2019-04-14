////////////////////////////////////////////////////////////////////////////////
/// @file FontRenderer.h
/// @brief Deklaracija klase FontRenderer.
/// @author Dusan Pantelic
/// @date April 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONT_RENDERER_H_
#define _FONT_RENDERER_H_

// Imena sejder fajlova.
#define FONT_FRAGMENT_SHADER "src/shader/FontFragmentShader.txt"
#define FONT_VERTEX_SHADER "src/shader/FontVertexShader.txt"

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../font/Text.h"
#include "../shader/FontShader.h"
#include "../utility/Math.h"

// Ukljucivanje biblioteka
#include <glm/vec3.hpp>
#include <string>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;
using namespace shader;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena font.
/// Sadrzi sve klase, funkcije i promenljive za rad sa tekstom.
////////////////////////////////////////////////////////////////////////////////
namespace font {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa FontRenderer zaduzena je za iscrtavanje karaktera.
    /// Pomocu klase FontRenderer iscrtavamo sve karaktere iz niske uz prosledjene
    /// osobine teksta navedene u Text klasi.
    //////////////////////////////////////////////////////////////////////////////
    class FontRenderer {

    // Privatne promenljive klase.
    private:
        /// Pokazivac na instancu klase FontShader.
        FontShader *fontShader;

        /// Identifikator niza atributa.
        GLuint vaoID;

        /// Identifikator bafera koji postaje clan niza atributa.
        GLuint vboID;

        /// Sirina ekrana.
        GLfloat screenWidth;

        /// Duzina ekrana.
        GLfloat screenHeight;

    // Javne funkcije klase
    public:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        FontRenderer();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~FontRenderer();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija iscrtava tekst pomocu podataka iz klase Text.
        /// @param text Pokazivac na instancu klase Text.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void render(Text *text);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija poziva funkciju cleanUp za sejder fonta.
        /// @param void
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void cleanUp();
    };

} // font


#endif
