////////////////////////////////////////////////////////////////////////////////
/// @file TerrainShader.h
/// @brief Deklaracija klase TerrainShader.
/// @author Dusan Pantelic
/// @date Januar 2017
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAIN_SHADER_H_
#define _TERRAIN_SHADER_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../utility/Math.h"
#include "../entity/Camera.h"
#include "../entity/Light.h"


// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace entity;
using namespace glm;

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>

// Ukljucivanje C++ biblioteka.
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena TerrainShader.
/// Sadrzi sejder programe.
////////////////////////////////////////////////////////////////////////////////
namespace shader {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa TerrainShader ucitava i izvrsava programe na OpenGL Shading jeziku.
  /// Ucitavaju se sejder fajlovi koji se zatim kompajliraju i po potrebi se
  /// izvrsavaju i zaustavljaju.
  //////////////////////////////////////////////////////////////////////////////
  class TerrainShader {

  // Privatne promenljive klase
  private:
    /// Identifikator programa koji izvrsava sejder fajlove.
    int programID;

    /// Identifikator ucitanog sejder fajla.
    int vertexShaderID;

    /// Identifikator ucitanog sejder fajla.
    int fragmentShaderID;

    /// Lokacija unformne promenljive
    int locationTransformationMatrix;

    /// Lokacija unformne promenljive
    int locationProjectionMatrix;

    /// Lokacija unformne promenljive
    int locationViewMatrix;

    /// Lokacija unformne promenljive
    int locationLightPosition;

    /// Lokacija unformne promenljive
    int locationLightColour;

    /// Lokacija unformne promenljive
    int locationShine;

    /// Lokacija unformne promenljive
    int locationReflectivity;

    /// Lokacija unformne promenljive
    int locationSkyColour;

    /// Lokacija unformne promenljive
    int locationBackgroundTexture;

    /// Lokacija unformne promenljive
    int locationRTexture;

    /// Lokacija unformne promenljive
    int locationGTexture;

    /// Lokacija unformne promenljive
    int locationBTexture;

    /// Lokacija unformne promenljive
    int locationBlendMap;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// U konstruktoru se ucitavaju sejder fajlovi i povezuju sa programom.
    /// @param vertexShaderFile Ime sejder fajla.
    /// @param fragmentShaderFile Ime sejder fajla.
    ////////////////////////////////////////////////////////////////////////////
    TerrainShader(const char *vertexShaderFile, const char *fragmentShaderFile);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~TerrainShader();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija povezuje ime sa generickim atributom.
    /// @param index Identifikator generickog atributa.
    /// @param variableName Ime koje pridruzujemo generickom atributu.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void bindAttribute(int index, const char *variableName);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija povezuje sve potrebne atribute.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void bindAttributes(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija pokrece sejder program.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void start(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija zaustavlja sejder program.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void stop(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija zaustavlja sejder program.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void cleanUp(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca lokaciju uniformne promenljive.
    /// @param uniformName Ime uniformne promenljive.
    /// @return int Lokacija uniformne promenljive.
    ////////////////////////////////////////////////////////////////////////////
    int getUniformLocation(const char *uniformName);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija postavlja lokacije svih uniformnih promenljivih.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void getAllUniformLocations(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava broj u uniformnu varijablu.
    /// @param uniformLocation Lokacija uniformne promenljive.
    /// @param value Broj.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadInt(int uniformLocation, int value);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava broj u uniformnu varijablu.
    /// @param uniformLocation Lokacija uniformne promenljive.
    /// @param value Broj pokretnom zarezu.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadFloat(int uniformLocation, float value);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava vektor koordinata u uniformnu varijablu.
    /// @param uniformLocation Lokacija uniformne promenljive.
    /// @param vertex Vektor koordinata.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadFloatVertex(int uniformLocation, vec3 vertex);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava istinitosnu vrednost u uniformnu varijablu.
    /// @param uniformLocation Lokacija uniformne promenljive.
    /// @param value Istinitosna vrednost.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadBoolean(int uniformLocation, bool value);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava matricu u uniformnu varijablu.
    /// @param uniformLocation Lokacija uniformne promenljive.
    /// @param matrix Matrica.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadMatrix(int uniformLocation, mat4 matrix);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava matricu transformacije u uniformnu varijablu.
    /// @param matrix Matrica transformacije.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadTransformationMatrix(mat4 matrix);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava matricu projekcije u uniformnu varijablu.
    /// @param matrix Matrica projekcije.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadProjectionMatrix(mat4 matrix);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava matricu pogleda u uniformnu varijablu.
    /// @param camera Pokazivac na instancu klase Camera.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadViewMatrix(Camera *camera);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava svetlost u uniformnu varijablu.
    /// @param light Pokazivac na instancu klase Light.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadLight(Light *light);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava promenljive u uniformnu varijablu.
    /// @param shine Intenzitet sjaja.
    /// @param reflectivity Intenzitet odbijanja svetlosti.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadShineVariables(float shine, float reflectivity);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava boju neba u uniformnu varijablu.
    /// @param r Kolicina crvene boje.
    /// @param g Kolicina zelene boje.
    /// @param b Kolicina plave boje.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadSkyColour(float r, float g, float b);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija povezuje texture terena.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void connectTextureUnits();

  // Privatne funkcije klase
  private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava sejder fajlove.
    /// @param fileName Naziv sejder fajla.
    /// @param type Vrsta sejdera.
    /// @return int Identifikator sejdera.
    ////////////////////////////////////////////////////////////////////////////
    int loadShader(const char *fileName, GLenum  type);

  };
} // shader

#endif
