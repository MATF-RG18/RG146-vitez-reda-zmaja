////////////////////////////////////////////////////////////////////////////////
/// @file TerrainTexturePack.h
/// @brief Deklaracija klase TerrainTexturePack.
/// @author Dusan Pantelic
/// @date Septembar 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAIN_TEXTURE_PACK_H_
#define _TERRAIN_TEXTURE_PACK_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../texture/TerrainTexture.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena texture.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju teksturu objekta.
////////////////////////////////////////////////////////////////////////////////
namespace texture {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa TerrainTexture opisuje sve teksture terena.
    //////////////////////////////////////////////////////////////////////////////
    class TerrainTexturePack {

        // Privatne promenljive klase
        private:
            /// Textura pozadine terena
            TerrainTexture *backgroundTexture;

            /// Textura odredjena pozicijom crvene boje
            TerrainTexture *rTexture;

            /// Textura odredjena pozicijom zelene boje
            TerrainTexture *gTexture;

            /// Textura odredjena pozicijom plave boje
            TerrainTexture *bTexture;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param backgroundTexture Textura pozadine terena.
            /// @param rTexture Textura odredjena pozicijom crvene boje.
            /// @param gTexture Textura odredjena pozicijom zelene boje.
            /// @param bTexture Textura odredjena pozicijom plave boje.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexturePack(TerrainTexture *backgroundTexture, TerrainTexture *rTexture, TerrainTexture *gTexture, TerrainTexture *bTexture);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~TerrainTexturePack();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca teksturu pozadine.
            /// @param void
            /// @return TerrainTexture * Pokazivac na instancu klase TerrainTexture.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexture *getBackgroundTexture();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca teksturu odredjenu crvenom bojom.
            /// @param void
            /// @return TerrainTexture * Pokazivac na instancu klase TerrainTexture.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexture *getRTexture();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca teksturu odredjenu zelenom bojom.
            /// @param void
            /// @return TerrainTexture * Pokazivac na instancu klase TerrainTexture.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexture *getGTexture();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca teksturu odredjenu plavom bojom.
            /// @param void
            /// @return TerrainTexture * Pokazivac na instancu klase TerrainTexture.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexture *getBTexture();
    };
    
} // texture

#endif
