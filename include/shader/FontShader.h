////////////////////////////////////////////////////////////////////////////////
/// @file FontShader.h
/// @brief Deklaracija klase FontShader.
/// @author Dusan Pantelic
/// @date April 2019
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONT_SHADER_H_
#define _FONT_SHADER_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../utility/Math.h"

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>

// Ukljucivanje biblioteka.
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena shader.
/// Sadrzi sejder programe.
////////////////////////////////////////////////////////////////////////////////
namespace shader {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa FontShader ucitava i izvrsava programe na OpenGL Shading jeziku.
  /// Ucitavaju se sejder fajlovi koji se zatim kompajliraju i po potrebi se
  /// izvrsavaju i zaustavljaju.
  //////////////////////////////////////////////////////////////////////////////
  class FontShader {

  // Privatne promenljive klase
  private:

    /// Identifikator programa koji izvrsava sejder fajlove.
    int programID;

    /// Identifikator ucitanog sejder fajla.
    int vertexShaderID;

    /// Identifikator ucitanog sejder fajla.
    int fragmentShaderID;

    /// Lokacija unformne promenljive.
    int locationTransformationMatrix;

    /// Lokacija unformne promenljive.
    int locationTextColor;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// U konstruktoru se ucitavaju sejder fajlovi i povezuju sa programom.
    /// @param vertexShaderFile Ime sejder fajla.
    /// @param fragmentShaderFile Ime sejder fajla.
    ////////////////////////////////////////////////////////////////////////////
    FontShader(const char *vertexShaderFile, const char *fragmentShaderFile);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~FontShader();

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
    /// @brief Funkcija ucitava boju teksta u uniformnu varijablu.
    /// @param textColor Boja u RGB formatu.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadTextColor(vec3 textColor);

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
