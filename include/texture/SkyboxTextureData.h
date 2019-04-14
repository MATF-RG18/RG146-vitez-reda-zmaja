////////////////////////////////////////////////////////////////////////////////
/// @file ModelTexture.h
/// @brief Deklaracija klase ModelTexture.
/// @author Dusan Pantelic
/// @date Avgust 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _SKYBOX_TEXTURE_DATA_H_
#define _SKYBOX_TEXTURE_DATA_H_

// Ukljucivanje biblioteka.
#include <vector>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena texture.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju teksturu objekta.
////////////////////////////////////////////////////////////////////////////////
namespace texture {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa SkyboxTextureData opisuje teksturu neba.
    /// Klasa cuva podatke bitne za teksturisanje kocke neba.
    //////////////////////////////////////////////////////////////////////////////
    class SkyboxTextureData {

        // Privatne promenljive klase
        private:
            /// Sirina.
            int width;

            /// Visina.
            int height;

            /// Bafer podataka o bojama neba ucitan sa teksture.
            unsigned char *buffer;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param width Sirina.
            /// @param height Visina.
            /// @param buffer Bafer podataka o bojama neba ucitan sa teksture.
            ////////////////////////////////////////////////////////////////////////////
            SkyboxTextureData(int width, int height, unsigned char *buffer);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~SkyboxTextureData();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive width.
            /// @param void
            /// @return int Sirina.
            ////////////////////////////////////////////////////////////////////////////
            int getWidth();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive height.
            /// @param void
            /// @return int Visina.
            ////////////////////////////////////////////////////////////////////////////
            int getHeight();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive buffer.
            /// @param void
            /// @return char * Bafer podataka o bojama neba ucitan sa teksture.
            ////////////////////////////////////////////////////////////////////////////
            unsigned char *getBuffer();
    };
} // texture

#endif
