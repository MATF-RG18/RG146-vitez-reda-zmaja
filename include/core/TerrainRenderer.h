////////////////////////////////////////////////////////////////////////////////
/// @file TerrainRenderer.h
/// @brief Deklaracija klase TerrainRenderer.
/// @author Dusan Pantelic
/// @date Decembar 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAIN_RENDERER_H_
#define _TERRAIN_RENDERER_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../shader/TerrainShader.h"
#include "../terrain/Terrain.h"

// Ukljucivanje biblioteka.
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <list>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace terrain;
using namespace shader;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa TerrainRenderer je zaduzena za iscrtavanje terena na ekran.
    /// Tokom pokretanja prvo se vrsi priprema za iscrtavanje, a zatim se
    /// sadrzaj niza atributa(koordinate, boje, texture ...) iscrtava na ekran
    //////////////////////////////////////////////////////////////////////////////
    class TerrainRenderer {

        // Privatne promenljive klase
        private:
            /// Polje vidika.
            float FOV = 70;

            /// Prednji deo vidljivosti.
            float NEAR_PLANE = 0.1;

            /// Zadnji deo vidljivosti.
            float FAR_PLANE = 1000;

            /// Pokazivac na instancu klase TerrainShader.
            TerrainShader *terrainShader;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param terrainShader Pokazivac na instancu klase TerrainShader.
            ////////////////////////////////////////////////////////////////////////////
            TerrainRenderer(TerrainShader *terrainShader);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~TerrainRenderer();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija iscrtava terene na ekran.
            /// @param terrains Lista terena.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void render(list<Terrain *> terrains);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija ucitava teksture terena i iscrtava sve njegove delove..
            /// @param terrain Pokazivac na instancu klase Terrain.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void drawTerrain(Terrain *terrain);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija povezuje teksture terena.
            /// @param terrain Pokazivac na instancu klase Terrain.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void bindTextures(Terrain *terrain);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija otklanja vezu izmedju podataka terena i programa.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void unbindTerrain();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija kreira matricu transformacije za teren i ucitava je u sejder program.
            /// @param terrain Pokazivac na instancu klase Terrain.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void loadModelMatrix(Terrain *terrain);

        // Privatne funkcije klase
        private:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija kreira matricu projekcije.
            /// @param void
            /// @return mat4 Matrica projekcije.
            ////////////////////////////////////////////////////////////////////////////
            mat4 createProjectionMatrix();
    };
} // core

#endif
