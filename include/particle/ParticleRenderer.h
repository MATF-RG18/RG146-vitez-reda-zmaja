////////////////////////////////////////////////////////////////////////////////
/// @file ParticleRender.h
/// @brief Deklaracija klase ParticleRender.
/// @author Dusan Pantelic
/// @date Decembar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _PARTICLE_RENDER_H_
#define _PARTICLE_RENDER_H_

// Imena sejder fajlova.
#define PARTICLE_FRAGMENT_SHADER "src/shader/ParticleFragmentShader.txt"
#define PARTICLE_VERTEX_SHADER "src/shader/ParticleVertexShader.txt"


// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../particle/Particle.h"
#include "../utility/Math.h"
#include "../shader/ParticleShader.h"
#include "../model/RawModel.h"
#include "../entity/Camera.h"
#include "../texture/Texture.h"

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace model;
using namespace shader;
using namespace glm;
using namespace entity;
using namespace texture;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace particle {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa ParticleRender je zaduzena za iscrtavanje entiteta na ekran.
  /// Tokom pokretanja prvo se vrsi priprema za iscrtavanje, a zatim se
  /// sadrzaj niza atributa(koordinate, boje, texture ...) iscrtava na ekran
  //////////////////////////////////////////////////////////////////////////////
  class ParticleRenderer {

  // Privatne promenljive klase
  private:
    /// Polje vidika.
    float FOV = 70;

    /// Prednji deo vidljivosti.
    float NEAR_PLANE = 0.1;

    /// Zadnji deo vidljivosti.
    float FAR_PLANE = 1000;

    /// Pokazivac na instancu klase Shader.
    ParticleShader *particleShader;

    RawModel *rawModel;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param shader Pokazivac na instancu klase Shader.
    ////////////////////////////////////////////////////////////////////////////
    ParticleRenderer(VaoLoader *vaoLoader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~ParticleRenderer();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija iscrtava sve entitete i teksturisane modele koje im odgovaraju.
    /// @param entities Hes mapa teksturisanih modela i lista entiteta.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void render(list<Particle *> particles, Camera *camera, Texture *texture);

    void cleanUp();
  // Privatne funkcije klase
  private:
    void prepare();

    void finishRendering();
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira matricu projekcije.
    /// @param void
    /// @return mat4 Matrica projekcije.
    ////////////////////////////////////////////////////////////////////////////
    mat4 createProjectionMatrix();

    void updateModelViewMatrix(vec3 position, float rotation, float scaleFactor, mat4 viewMatrix);

  };

} // core

#endif
