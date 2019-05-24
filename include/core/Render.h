////////////////////////////////////////////////////////////////////////////////
/// @file Render.h
/// @brief Deklaracija klase Render.
/// @author Dusan Pantelic
/// @date Decembar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _RENDER_H_
#define _RENDER_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/TexturedModel.h"
#include "../entity/Entity.h"
#include "../utility/Math.h"
#include "../shader/Shader.h"

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <stdio.h>
#include <map>
#include <list>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace model;
using namespace shader;
using namespace entity;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Render je zaduzena za iscrtavanje entiteta na ekran.
  /// Tokom pokretanja prvo se vrsi priprema za iscrtavanje, a zatim se
  /// sadrzaj niza atributa(koordinate, boje, texture ...) iscrtava na ekran
  //////////////////////////////////////////////////////////////////////////////
  class Render {

  // Privatne promenljive klase
  private:
    /// Polje vidika.
    float FOV = 70;

    /// Prednji deo vidljivosti.
    float NEAR_PLANE = 0.1;

    /// Zadnji deo vidljivosti.
    float FAR_PLANE = 1000;

    /// Pokazivac na instancu klase Shader.
    Shader *shader;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param shader Pokazivac na instancu klase Shader.
    ////////////////////////////////////////////////////////////////////////////
    Render(Shader *shader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Render();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija iscrtava sve entitete i teksturisane modele koje im odgovaraju.
    /// @param entities Hes mapa teksturisanih modela i lista entiteta.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void render(map<TexturedModel *, list<Entity *>> entities);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava teksture entiteta.
    /// @param model Pokazivac na instancu klase TexturedModel.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void drawTexturedModel(TexturedModel *model);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija otkacinje vezu izmedju podataka texturisanog modela i programa.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void unbindTexturedModel();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira matricu transformacije za entitet i ucitava je u sejder program.
    /// @param entity Pokazivac na instancu klase Entity.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void prepareInstance(Entity *entity);

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
