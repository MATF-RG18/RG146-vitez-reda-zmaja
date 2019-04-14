////////////////////////////////////////////////////////////////////////////////
/// @file Font.h
/// @brief Deklaracija klase Font.
/// @author Dusan Pantelic
/// @date April 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONT_H_
#define _FONT_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../font/FontData.h"

// Ukljucivanje biblioteka
#include<map>
#include <iostream>

// Ukljucivanje FreeType biblioteke.
#include <ft2build.h>
#include FT_FREETYPE_H

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena font.
/// Sadrzi sve klase, funkcije i promenljive za rad sa tekstom.
////////////////////////////////////////////////////////////////////////////////
namespace font {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa Font odredjuje font.
    /// Pomocu klase Font ucitavamo font fajl u ttf formatu.
    //////////////////////////////////////////////////////////////////////////////
    class Font {

    // Privatne promenljive klase.
    private:
        /// Mapa karaktera sa svim njegovim osobinama unutar FontData klase.
        map<GLchar, FontData*> fontCharacters;

        /// Promenljiva biblioteke FreeType za inicijalizaciju biblioteke.
        FT_Library ft;

        /// Promenljiva biblioteke FreeType za ucitavanje informacija o fontu.
        FT_Face face;

    // Javne funkcije klase
    public:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// @param fontName Ime fonta.
        /// @param fontSize Velicina fonta.
        ////////////////////////////////////////////////////////////////////////////
        Font(const char *fontName, int fontSize);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~Font();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca podatke o karakteru iz mape karaktera.
        /// @param c Karakter koji se cita iz mape karaktera.
        /// @return FontData * Pokazivac na instancu klase FontData.
        ////////////////////////////////////////////////////////////////////////////
        FontData *getCharData(GLchar c);

    // Privatne funkcije klase
    private:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija ucitava u mapu karaktera informacije za ASCII karaktere.
        /// @param void
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void loadFontData();

    };
} // font

#endif
