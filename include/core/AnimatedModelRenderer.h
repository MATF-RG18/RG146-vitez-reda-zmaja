////////////////////////////////////////////////////////////////////////////////
/// @file AnimatedModelRenderer.h
/// @brief Deklaracija klase AnimatedModelRenderer.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _ANIMATED_MODEL_RENDERER_H_
#define _ANIMATED_MODEL_RENDERER_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/AnimatedModel.h"
#include "../entity/AnimatedEntity.h"
#include "../utility/Math.h"
#include "../shader/AnimatedModelShader.h"

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

#define MAX_BONES 50

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
  class AnimatedModelRenderer {

  // Privatne promenljive klase
  private:
    /// Polje vidika.
    float FOV = 70;

    /// Prednji deo vidljivosti.
    float NEAR_PLANE = 0.1;

    /// Zadnji deo vidljivosti.
    float FAR_PLANE = 1000;

    /// Pokazivac na instancu klase Shader.
    AnimatedModelShader *shader;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param shader Pokazivac na instancu klase Shader.
    ////////////////////////////////////////////////////////////////////////////
    AnimatedModelRenderer(AnimatedModelShader *shader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~AnimatedModelRenderer();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija iscrtava sve entitete i teksturisane modele koje im odgovaraju.
    /// @param entities Hes mapa teksturisanih modela i lista entiteta.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void render(map<AnimatedModel *, list<AnimatedEntity *>> entities);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava teksture entiteta.
    /// @param model Pokazivac na instancu klase TexturedModel.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void drawAnimatedModel(AnimatedModel *model);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija otkacinje vezu izmedju podataka texturisanog modela i programa.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void unbindAnimatedModel();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira matricu transformacije za entitet i ucitava je u sejder program.
    /// @param entity Pokazivac na instancu klase Entity.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void prepareInstance(AnimatedEntity *entity);

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
