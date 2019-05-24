////////////////////////////////////////////////////////////////////////////////
/// @file Terrain.h
/// @brief Deklaracija klase Terrain.
/// @author Dusan Pantelic
/// @date Septembar 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAIN_H_
#define _TERRAIN_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/RawModel.h"
#include "../texture/Texture.h"
#include "../texture/TerrainTexturePack.h"
#include "../core/VaoLoader.h"
#include "../utility/Math.h"

// Ukljucivanje biblioteka
#include <Magick++.h>
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

// Velicina terena
#define SIZE  1000
// Vrednost boje predstavljene kao broj
#define MAX_PIXEL_COLOUR 256*256*256
// Maksimalna visina terena
#define MAX_HEIGHT 60

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace model;
using namespace texture;
using namespace core;
using namespace glm;
using namespace Magick;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena terain.
/// Sadrzi sve klase, funkcije i promenljive za kreiranje i rad sa terenom.
////////////////////////////////////////////////////////////////////////////////
namespace terrain {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa Terrain zaduzena je za kreiranje terena.
    /// Pomocu klase Terrain generisemo teren na osnovu visinske mape.
    //////////////////////////////////////////////////////////////////////////////
    class Terrain {

        // Privatne promenljive klase.
        private:
            /// Pozicija terena na X osi.
            float x;

            /// Pozicija terena na Z osi.
            float z;

            /// Pokazivac na instancu klase RawModel.
            RawModel *model;

            /// Pokazivac na instancu klase TerrainTexturePack.
            TerrainTexturePack *texturePack;

            /// Pokazivac na instancu klase TerrainTexture.
            TerrainTexture *blendMap;

            /// Matrica visina terena.
            float **heights;

            /// Velicina matrica visina.
            int heightsLength;

            /// Broj cvorova terena.
            int VERTEX_COUNT;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param gridX Pozicija terena na X osi.
            /// @param gridZ Pozicija terena na Z osi.
            /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
            /// @param texturePack Pokazivac na instancu klase TerrainTexture.
            /// @param blendMap Pokazivac na instancu klase TerrainTexture.
            /// @param heightMap Ime fajla sa visinskom mapom.
            ////////////////////////////////////////////////////////////////////////////
            Terrain(float gridX, float gridZ, VaoLoader *vaoLoader, TerrainTexturePack *texturePack, TerrainTexture *blendMap,const char *heightMap);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~Terrain();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive model.
            /// @param void
            /// @return RawModel * Pokazivac na instancu klase RawModel.
            ////////////////////////////////////////////////////////////////////////////
            RawModel *getModel();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive texturePack.
            /// @param void
            /// @return TerrainTexturePack * Pokazivac na instancu klase TerrainTexturePack.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexturePack *getTexturePack();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive blendMap.
            /// @param void
            /// @return TerrainTexture * Pokazivac na instancu klase TerrainTexture.
            ////////////////////////////////////////////////////////////////////////////
            TerrainTexture *getBlendMap();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive x.
            /// @param void
            /// @return float Pozicija terena na X osi.
            ////////////////////////////////////////////////////////////////////////////
            float getX();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca vrednost privatne promenljive z.
            /// @param void
            /// @return float Pozicija terena na Z osi.
            ////////////////////////////////////////////////////////////////////////////
            float getZ();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vraca visinu terana u odnosu na koordinate u svetu igre.
            /// @param worldX Pozicija u svetu igre na X osi.
            /// @param worldZ Pozicija u svetu igre na Z osi.
            /// @return float Visina.
            ////////////////////////////////////////////////////////////////////////////
            float getHeightOfTerrain(int worldX, int worldZ);

        // Privatne funkcije klase
        private:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija racuna vektor normale.
            /// @param image Slika visinske mape.
            /// @param x Pozicija cvora terena na X osi.
            /// @param y Pozicija cvora terena na Y osi.
            /// @return vec3 Vektor normale.
            ////////////////////////////////////////////////////////////////////////////
            vec3 calculateNormal(Image image, int x, int y);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija generise visinu terena pomocu visinske mape.
            /// @param image Slika visinske mape.
            /// @param x Pozicija cvora terena na X osi.
            /// @param y Pozicija cvora terena na Y osi.
            /// @return float Visina.
            ////////////////////////////////////////////////////////////////////////////
            float getHeight(Image image, int x, int y);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija generise teren.
            /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
            /// @param image Slika visinske mape.
            /// @return RawModel * Pokazivac na instancu klase RawModel.
            ////////////////////////////////////////////////////////////////////////////
            RawModel *generateTerrain(VaoLoader *vaoLoader,Image image);
    };
} // terrain

#endif
