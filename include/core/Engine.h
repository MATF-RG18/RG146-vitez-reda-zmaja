////////////////////////////////////////////////////////////////////////////////
/// @file Engine.h
/// @brief Deklaracija klase Engine i deklaracija callback funkcija.
/// @author Dusan Pantelic
/// @date Decembar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _ENGINE_H_
#define _ENGINE_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/TexturedModel.h"
#include "../model/AnimatedModel.h"
#include "../core/Loader.h"
#include "../model/RawModel.h"
#include "../core/VaoLoader.h"
#include "../core/Render.h"
#include "../core/MainRenderer.h"
#include "../shader/Shader.h"
#include "../texture/Texture.h"
#include "../texture/TerrainTexturePack.h"
#include "../entity/Entity.h"
#include "../entity/Player.h"
#include "../entity/Camera.h"
#include "../utility/Math.h"
#include "../utility/FpsData.h"
#include "../hud/HudTexture.h"
#include "../hud/HudRenderer.h"
#include "../font/FontRenderer.h"
#include "../font/Text.h"
#include "../animation/Animator.h"
#include "../particle/WeatherSystem.h"

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

#define ESC 27


// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace shader;
using namespace model;
using namespace texture;
using namespace entity;
using namespace utility;
using namespace hud;
using namespace font;
using namespace animation;
using namespace particle;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Callback funkcija.
  /// Pokazivac funkcije prosledjuje se funkciji glutDisplayFunc().
  /// Funkcija koja kontrolise sta ce biti iscrtano na ekranu.
  /// @param void
  /// @return void
  //////////////////////////////////////////////////////////////////////////////
  void renderScene(void);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Callback funkcija.
  /// Pokazivac funkcije prosledjuje se funkciji glutKeyboardFunc().
  /// Funkcija koja proverava ulaz sa tastature.
  /// @param key Karakter koji je pritisnut na tastaturi
  /// @param x X koordinata pozicije kursora
  /// @param y Y koordinata pozicije kursora
  /// @return void
  //////////////////////////////////////////////////////////////////////////////
  void onKeyboard(unsigned char key, int x, int y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Callback funkcija.
  /// Pokazivac funkcije prosledjuje se funkciji glutMouseFunc().
  /// Funkcija koja proverava ulaz sa misa.
  /// @param button Taster koji je pritisnut na misu
  /// @param state Stanje tastera(pritisnut ili otpusten)
  /// @param x X koordinata pozicije kursora
  /// @param y Y koordinata pozicije kursora
  /// @return void
  //////////////////////////////////////////////////////////////////////////////
  void onMouse(int button, int state, int x, int y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Callback funkcija.
  /// Pokazivac funkcije prosledjuje se funkciji glutSpecialFunc().
  /// Funkcija koja proverava pritisnuti specijalni karakter.
  /// @param key Specijalni karakter koji je pritisnut na tastaturi
  /// @param x X koordinata pozicije kursora
  /// @param y Y koordinata pozicije kursora
  /// @return void
  //////////////////////////////////////////////////////////////////////////////
  void onSpecialDown(int key, int x, int y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Callback funkcija.
  /// Pokazivac funkcije prosledjuje se funkciji glutSpecialUpFunc().
  /// Funkcija koja proverava otpusteni specijalni karakter.
  /// @param key Specijalni karakter koji je otpusten na tastaturi
  /// @param x X koordinata pozicije kursora
  /// @param y Y koordinata pozicije kursora
  /// @return void
  //////////////////////////////////////////////////////////////////////////////
  void onSpecialUp(int key, int x, int y);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Engine je jezgro i kontroler programa.
  /// Sva bitnija podesavanja i inicijalizacije desavaju se u ovoj klasi.
  /// Klasa je zaduzena za inicijalizaciju GLUT-a , OpenGL-a, i kontrolisanje
  /// i kreiranje ostalih korisnicki definisanih klasa i funkcija.
  //////////////////////////////////////////////////////////////////////////////
  class Engine {

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    Engine();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Engine();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija startuje bitne procese za funkcionisanje.
    /// U funkciji se pozivaju funkcije za inicijalizaciju GLUT-a, OpnenGL-a,
    /// funkcija za kreiranje prozora i registraciju callback funkcija.
    /// Takodje funkcija pokrece glavnu petlju programa.
    /// @param argcp Pokazivac na broj argumenata programa
    /// @param argv Niz niski koje su argumenti programa
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void start(int *argcp, char **argv);

  // Privatne funkcije klase
  private:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija inicijalizuje GLUT.
    /// U funkciji se postavljalju parametri osnovnih funkcija za
    /// inicijalizaciju GLUT-a.
    /// @param argcp Pokazivac na broj argumenata programa
    /// @param argv Niz niski koje su argumenti programa
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void initGlut(int *argcp, char **argv);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira prozor na racunaru.
    /// U funkciji se postavljalju parametri prozora kao sto su ime prozora,
    /// sirini i visina , i pozicija. Parametri su definisani kao lokalne
    /// promenljive klase.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void createWindow(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija inicijalizuje OpenGL.
    /// U funkciji se postavjalju parametri osnovnih OpenGL funkcija,
    /// takodje se unutar funkcije ucitavaju modeli i informacije koje je
    /// potrebno ucitati pre glavne petlje programa.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void initGl(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija registruje callback funkcije.
    /// U funkciji se pomocu GLUT funkcija prosledjuju pokazivaci callback
    /// funkcija
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void registerCallbackFunctions(void);

  };

} // core

#endif
