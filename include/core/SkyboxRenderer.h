////////////////////////////////////////////////////////////////////////////////
/// @file SkyboxRenderer.h
/// @brief Deklaracija klase SkyboxRenderer.
/// @author Dusan Pantelic
/// @date Avgust 2018
////////////////////////////////////////////////////////////////////////////////
#ifndef _SKYBOX_RENDERER_H_
#define _SKYBOX_RENDERER_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/RawModel.h"
#include "../shader/SkyboxShader.h"
#include "../core/VaoLoader.h"

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Ukljucivanje biblioteka.
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace model;
using namespace shader;
using namespace glm;

// Velicina kutije neba
#define CUBE_SIZE 500

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa SkyboxRenderer je zaduzena za iscrtavanje neba na ekran.
    /// Tokom pokretanja prvo se vrsi priprema za iscrtavanje, a zatim se
    /// iscrtava kutija neba na koju se nalepljuju dnevne i nocne teksture
    /// u zavisnosti od trenutnog dela igri.
    //////////////////////////////////////////////////////////////////////////////
    class SkyboxRenderer {

        // Privatne promenljive klase
        private:
            /// Polje vidika.
            float FOV = 70;

            /// Prednji deo vidljivosti.
            float NEAR_PLANE = 0.1;

            /// Zadnji deo vidljivosti.
            float FAR_PLANE = 1000;

            /// Vektor imena dnevih tekstura neba.
            vector<const char *> dayTextureFiles;

            /// Vektor imena nocnih tekstura neba.
            vector<const char *> nightTextureFiles;

            /// Pokazivac na instancu klase RawModel.
            RawModel *cube;

            /// Identifikator teksture dnevnog neba.
            GLuint dayTextureID;

            /// Identifikator teksture nocnog neba.
            GLuint nightTextureID;

            /// Pokazivac na instancu klase SkyboxShader.
            SkyboxShader *skyboxShader;

            /// Trenutno vreme u igri.
            float time;

        // Javne funkcije klase
        public:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Konstruktor klase.
            /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
            ////////////////////////////////////////////////////////////////////////////
            SkyboxRenderer(VaoLoader *vaoLoader);

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Destruktor klase.
            /// @param void
            ////////////////////////////////////////////////////////////////////////////
            ~SkyboxRenderer();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija iscrtava nebo na ekran.
            /// @param camera Pokazivac na instancu klase Camera.
            /// @param r Kolicina crvene boje u boji magle.
            /// @param g Kolicina zelene boje u boji magle.
            /// @param b Kolicina plave boje u boji magle.
            /// @param fpsData Pokazivac na instancu klase FpsData.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void render(Camera *camera, float r, float g, float b, FpsData *fpsData);

        // Privatne funkcije klase
        private:
            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija kreira matricu projekcije.
            /// @param void
            /// @return mat4 Matrica projekcije.
            ////////////////////////////////////////////////////////////////////////////
            mat4 createProjectionMatrix();

            ////////////////////////////////////////////////////////////////////////////
            /// @brief Funkcija povezuje dnevne i nocne teksture u zavisnosti od vremena.
            /// @param fpsData Pokazivac na instancu klase FpsData.
            /// @return void
            ////////////////////////////////////////////////////////////////////////////
            void bindTextures(FpsData *fpsData);
    };
} //core

#endif
