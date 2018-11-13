////////////////////////////////////////////////////////////////////////////////
/// @file MainRenderer.h
/// @brief Deklaracija klase Render.
/// @author Dusan Pantelic
/// @date  Avgvust 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _MAIN_RENDERER_H_
#define _MAIN_RENDERER_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../core/Render.h"
#include "../shader/Shader.h"
#include "../core/TerrainRenderer.h"
#include "../shader/TerrainShader.h"
#include "../entity/Entity.h"
#include "../core/SkyboxRenderer.h"
#include "../core/VaoLoader.h"

// Ukljucivanje biblioteka
#include <map>
#include <list>

// Makroi definisani nazivima sejder fajlova.
#define VERTEX_FILE "src/shader/VertexShader.txt"
#define FRAGMENT_FILE "src/shader/FragmentShader.txt"
#define TERRAIN_VERTEX_FILE "src/shader/TerrainVertexShader.txt"
#define TERRAIN_FRAGMENT_FILE "src/shader/TerrainFragmentShader.txt"

// Makroi za definisanje RGB boje
#define R 0.6
#define G 0.6
#define B 0.6

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa MainRenderer je zaduzena za iscrtavanje sadrzaja na ekran.
    /// Tokom pokretanja prvo se vrsi priprema za iscrtavanje, a zatim se
    /// iscrtavaju teren igrac i ostali entiteti
    ///////////////////////////////////////////////////////////////////////////////
    class MainRenderer {

        // Privatne promenljive klase.
        private:
            /// Pokazivac na instancu klase Shader. 
            Shader *shader;

            /// Pokazivac na instancu klase Render.
            Render *renderer;

            /// Pokazivac na instancu klase TerrainRenderer.
            TerrainRenderer *terrainRenderer;

            /// Pokazivac na instancu klase TerrainShader.
            TerrainShader *terrainShader;

            /// Hes mapa koja sadrzi teksturisane modele i liste entiteta.
            map<TexturedModel *, list<Entity *>> entities;

            /// Lista terena
            list<Terrain *> terrains;

            SkyboxRenderer *skyboxRenderer;

            FpsData *fpsData;
        // Javne funkcije klase.
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param vaoLoader Pokazivac na instancu klase VaoLoader
            ////////////////////////////////////////////////////////////////////////////
            MainRenderer(VaoLoader * vaoLoader, FpsData *fpsData);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~MainRenderer();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija iscrtava teren i ostale entitete igre.
            /// @param light Pokazivac na instancu klase Light
            /// @param camera Pokazivac na instancu klase Camera
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void render(Light *light, Camera *camera);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija obradjuje entitete i ubacuje ih u mapu entiteta.
            /// @param entity Pokazivac na instancu klase Entity
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void processEntity(Entity *entity);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija obradjuje terene i ubacuje ih u listu terena.
            /// @param terrain Pokazivac na instancu klase Terrain
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void processTerrain(Terrain *terrain);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija poziva funkcije cleanUp za sejdere entiteta i terena.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void cleanUp(void);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija vrsi pripreme za iscrtavanje sadrzaja na ekran.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void prepare(void);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija onemogucava iscrtavanje zadnje strane objekata.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void enableCulling();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija omogucava iscrtavanje zadnje strane objekata.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void disableCulling();
    };
} // core

#endif