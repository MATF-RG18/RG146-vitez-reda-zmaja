////////////////////////////////////////////////////////////////////////////////
/// @file FpsData.h
/// @brief Deklaracija klase FpsData.
/// @author Dusan Pantelic
/// @date Septembar 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _FPS_DATA_H_
#define _FPS_DATA_H_

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>


////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena utility.
/// Sadrzi sve korisne klase, funkcije i promenljive koje pomazu kreiranju igre.
////////////////////////////////////////////////////////////////////////////////
namespace utility {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa FpsData cuva podatke o broju frejmova po sekundi.
    /// Pomocu klase FpsData racunamo trenutni broj frejmova po sekundi
    /// pomocu kojeg sinhronizujemo igru.
    //////////////////////////////////////////////////////////////////////////////
    class FpsData {

        // Privatne promenljive klase.
        private:
          /// Vreme iscrtavanja poslednjeg frejma.
          float lastFrameTime;

          /// Vreme iscrtavanja trenutnog frejma.
          float currentFrameTime;

          /// Trenutni broj frejmova po sekundi.
          int fpsCount;

          /// Broj frejmova.
          int numOfFrames;

          /// Vreme proteklo od kreiranja poslednja dva frejma.
          float frameDeltaTime;

        // Javne funkcije klase.
        public:
          ////////////////////////////////////////////////////////////////////////////
          /// @brief Konstruktor klase.
          /// @param void
          ////////////////////////////////////////////////////////////////////////////
          FpsData();

          ////////////////////////////////////////////////////////////////////////////
          /// @brief Destruktor klase.
          /// @param void
          ////////////////////////////////////////////////////////////////////////////
          ~FpsData();

          ////////////////////////////////////////////////////////////////////////////
          /// @brief Funkcija azurira trenutni broj frejmova po sekundi.
          /// @param void
          /// return void
          ////////////////////////////////////////////////////////////////////////////
          void update();

          ////////////////////////////////////////////////////////////////////////////
          /// @brief Funkcija vraca vrednost privatne promenljive fpsCount.
          /// @param void
          /// return int Trenutni broj frejmova po sekundi.
          ////////////////////////////////////////////////////////////////////////////
          int getFpsCount();

          ////////////////////////////////////////////////////////////////////////////
          /// @brief Funkcija vraca vreme proteklo od izmedju poslednja dva frejma.
          /// @param void
          /// return float Vreme proteklo od kreiranja poslednja dva frejma.
          ////////////////////////////////////////////////////////////////////////////
          float getFrameDeltaTime();

    };
} // utility

#endif
