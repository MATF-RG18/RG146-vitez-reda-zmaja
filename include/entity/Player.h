////////////////////////////////////////////////////////////////////////////////
/// @file Player.h
/// @brief Deklaracija klase Player.
/// @author Dusan Pantelic
/// @date Septembar 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _PLAYER_H_
#define _PLAYER_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../entity/AnimatedEntity.h"
#include "../terrain/Terrain.h"
#include "../utility/FpsData.h"
#include "../animation/Animator.h"

// Makro za definisanje brzine i rotacione brzine.
#define RUN_SPEED 10
#define TURN_SPEED  50

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace glm;
using namespace terrain;
using namespace utility;
using namespace animation;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena entity.
/// Sadrzi sve klase, funkcije i promenljive koje odredjuju jedan entitet.
////////////////////////////////////////////////////////////////////////////////
namespace entity {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa Player odredjuje igraca koji nadogradjuje entitet.
    /// Pomocu klase Player nadogradjujemo klasu Entity dodavajuci jos nove atribute
    /// i funkcije.
    //////////////////////////////////////////////////////////////////////////////
    class Player : public AnimatedEntity {

        // Privatne promenljive klase
        private:
            /// Trenutna brzina igraca.
            float currentSpeed;

            /// Trenutna rotaciona brzina igraca
            float currentTurnSpeed;

            /// Pokazivac na instancu klase Terrain.
            Terrain *terrain;

            /// Niz karaktera koji su pritisnuti a nisu otpusteni.
            bool *keyBuffer;

            FpsData *fpsData;

            Animator *animator;

            bool animationOn;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param model Pokazivac na instancu klase AnimatedModel.
            /// @param position Pozicija entiteta.
            /// @param rotation Rotacija entiteta.
            /// @param scale Skaliranje entiteta.
            /// @param terrain Pokazivac na instancu klase Terrain.
            ////////////////////////////////////////////////////////////////////////////
            Player(AnimatedModel *model, vec3 position, vec3 rotation, float scale, Terrain *terrain, FpsData *fpsData, Animator *animator);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~Player();

            //////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija obradjuje ulaz sa tastature.
            /// @param key Karakter koji je otpusten na tastaturi.
            /// @return void
            //////////////////////////////////////////////////////////////////////////////
            void handleKeyUp(unsigned char key);

            //////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija obradjuje ulaz sa tastature.
            /// @param key Karakter koji je pritisnut na tastaturi.
            /// @return void
            //////////////////////////////////////////////////////////////////////////////
            void handleKeyDown(unsigned char key);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija pomera igraca.
            /// @param void
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void move();
    };
} // entity

#endif
