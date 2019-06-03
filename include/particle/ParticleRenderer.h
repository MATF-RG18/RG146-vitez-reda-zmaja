////////////////////////////////////////////////////////////////////////////////
/// @file ParticleRender.h
/// @brief Deklaracija klase ParticleRender.
/// @author Dusan Pantelic
/// @date Jul 2019
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
/// @brief Prostor imena particle.
/// Sadrzi sve klase, funkcije i promenljive koje su vezane za sistem cestica.
////////////////////////////////////////////////////////////////////////////////
namespace particle {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa ParticleRender je zaduzena za iscrtavanje cestica na ekran.
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

    /// Pokazivac na instancu klase ParticleShader.
    ParticleShader *particleShader;

    /// Pokazivac na instancu klase RawModel.
    RawModel *rawModel;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
    ////////////////////////////////////////////////////////////////////////////
    ParticleRenderer(VaoLoader *vaoLoader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~ParticleRenderer();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija iscrtava sve cestice i teksture koje im odgovaraju.
    /// @param particles Lista cestica.
    /// @param camera Pokazivac na instancu klase Camera.
    /// @param texture Pokazivac na instancu klase Texture
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void render(list<Particle *> particles, Camera *camera, Texture *texture);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija pokrece cistace sejdera.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void cleanUp();

  // Privatne funkcije klase
  private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vrsi pripreme za iscrtavanje sadrzaja na ekran.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void prepare();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija otklanja efekte funkcije prepare.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void finishRendering();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira matricu projekcije.
    /// @param void
    /// @return mat4 Matrica projekcije.
    ////////////////////////////////////////////////////////////////////////////
    mat4 createProjectionMatrix();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira proizvod matrica transformacije i pogleda.
    /// Kreira se matria transformacije pomucu zadatih paramtara ali tako
    /// da je 3x3 podmatrica transponovana 3x3 podmatrici matrice modela
    /// cime postizemo 3D efekat 2D cestice koja je uvek okrenuta ka nama.
    /// Dobijenu matricu transformacije mnozimo sa matricom pogleda.
    /// @param position Pozicija cestice.
    /// @param rotation Rotacija cestice.
    /// @param scaleFactor Faktor skaliranja
    /// viewMatrix Matrica pogleda.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void updateModelViewMatrix(vec3 position, float rotation, float scaleFactor, mat4 viewMatrix);
  };

} // particle

#endif
