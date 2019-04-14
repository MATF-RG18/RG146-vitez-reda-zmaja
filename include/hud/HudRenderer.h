////////////////////////////////////////////////////////////////////////////////
/// @file HudRenderer.h
/// @brief Deklaracija klase HudRenderer.
/// @author Dusan Pantelic
/// @date Mart 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _HUD_RENDERER_
#define _HUD_RENDERER_

// Imena sejder fajlova.
#define HUD_FRAGMENT_SHADER "src/shader/HudFragmentShader.txt"
#define HUD_VERTEX_SHADER "src/shader/HudVertexShader.txt"

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/RawModel.h"
#include "../core/VaoLoader.h"
#include "../hud/HudTexture.h"
#include "../shader/HudShader.h"
#include "../utility/Math.h"

// Ukljucivanje biblioteka
#include <vector>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace core;
using namespace model;
using namespace std;
using namespace shader;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena hud.
/// Sadrzi sve klase, funkcije i promenljive za rad sa 2D grafikom.
////////////////////////////////////////////////////////////////////////////////
namespace hud {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa HudRenderer zaduzena je za iscrtavanje 2D grafike.
    /// Pomocu klase FontRenderer iscrtavamo 2D kvadrat na koji nalepljujemo
    /// zeljenu teksturu i pozicioniramo je u svetu pomocu matrice transformacije.
    //////////////////////////////////////////////////////////////////////////////
    class HudRenderer {

    // Privatne promenljive klase.
    private:
        /// Pokazivac na instancu klase RawModel.
        RawModel *quad;

        /// Pokazivac na instancu klase HudShader.
        HudShader *hudShader;

    // Javne funkcije klase
    public:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
        ////////////////////////////////////////////////////////////////////////////
        HudRenderer(VaoLoader *vaoLoader);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~HudRenderer();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija iscrtava 2D objekte.
        /// @param huds Vektor pokazivaca na instance klase HudTexture.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void render(vector<HudTexture*> huds);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija poziva funkciju cleanUp za sejder hud-a.
        /// @param void
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void cleanUp();
    };
} // hud

#endif
