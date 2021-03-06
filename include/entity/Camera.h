////////////////////////////////////////////////////////////////////////////////
/// @file Camera.h
/// @brief Deklaracija klase Camera.
/// @author Dusan Pantelic
/// @date Jun 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _CAMERA_H_
#define _CAMERA_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../entity/Player.h"

// Makro za definisanje broja PI.
#define PI 3.14159265

// Ukljucivanje biblioteka.
#include <vector>
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/matrix_transform.hpp> 

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena entity.
/// Sadrzi sve klase, funkcije i promenljive koje odredjuju jedan entitet.
////////////////////////////////////////////////////////////////////////////////
namespace entity {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Camera kontrolise pogled na igru.
  /// Pomocu klase Camera mozemo menjati pogled na entitete u igri kao sto je
  /// rotiranje oko objekta i uvelicavanje ili umanjivanje.
  //////////////////////////////////////////////////////////////////////////////
  class Camera {
  
  // Privatne promenljive klase.
  private:
    /// Koordinate pozicije kamere.
    vec3 position;

    /// Udaljenost kamere od igraca.
    float distanceFromPlayer;

    /// Ugao oko igraca
    float angleAroundPlayer;

    /// Rotacija kamere po X osi.
    float pich;

    /// Rotacija kamere po Y osi.
    float yaw;

    /// Rotacija kamere po Z osi.
    float roll;

    /// Osetljivost kamere na promene polozaja i rotacije.
    float sensitivity;

    /// Pokazivac na instancu klase Player
    Player *player;

  // Javne funkcije klase.
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param player Pokazivac na instancu klase Player.
    ////////////////////////////////////////////////////////////////////////////
    Camera (Player *player);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Camera ();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca poziciju kamere.
    /// @param void
    /// @return vec3 Vektor koji sadrzi polozaj kamere.
    ////////////////////////////////////////////////////////////////////////////
    vec3 getPosition();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija pomera kameru.
    /// @param void
    /// @return void.
    ////////////////////////////////////////////////////////////////////////////
    void move();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija obradjuje ulaz sa misa.
    /// @param button Taster koji je pritisnut na misu
    /// @param state Stanje tastera(pritisnut ili otpusten)
    /// @param x X koordinata pozicije kursora  
    /// @param y Y koordinata pozicije kursora
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void handleMouseInput(int button, int state, int x, int y);

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija obradjuje ulaz sa tastature.
    /// Funkcija koja proverava ulaz sa tastature.
    /// @param key Karakter koji je pritisnut na tastaturi
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    void handleKeyboardInput(unsigned char key);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca rotaciju oko X ose.
    /// @param void
    /// @return float Ugao u stepenima.
    ////////////////////////////////////////////////////////////////////////////
    float getPich();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca rotaciju oko Y ose.
    /// @param void
    /// @return float Ugao u stepenima.
    ////////////////////////////////////////////////////////////////////////////
    float getYaw();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca rotaciju oko Z ose.
    /// @param void
    /// @return float Ugao u stepenima.
    ////////////////////////////////////////////////////////////////////////////
    float getRoll();

  // Privatne funkcije klase.
  private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna uvelicavanje pogleda.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void calculateZoom(int button, int state);

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna rotaciju kamere oko X ose.
    /// @param key Karakter koji je pritisnut na tastaturi
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    void calculatePich(unsigned char key);

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna ugao kamere oko igraca.
    /// @param key Karakter koji je pritisnut na tastaturi
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    void calculateAngleAroundPlayer(unsigned char key);

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna horizontalnu udaljenost od igraca.
    /// @param void
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    float calculateHorizontalDistance();

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna vertikalnu udaljenost od igraca.
    /// @param void
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    float calculateVerticalDistance();

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna poziciju kamere.
    /// @param horizontalDistance Horizontalna udaljenost od igraca
    /// @param verticalDistance Vertikalna udaljenost od igraca
    /// @return void
    //////////////////////////////////////////////////////////////////////////////
    void calculateCameraPosition(float horizontalDistance, float verticalDistance);
  };
} // entity

#endif
