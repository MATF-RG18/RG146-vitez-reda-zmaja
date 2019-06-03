////////////////////////////////////////////////////////////////////////////////
/// @file VaoLoader.h
/// @brief Deklaracija klase VaoLoader.
/// @author Dusan Pantelic
/// @date Decembar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _VAOLOADER_H_
#define _VAOLOADER_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/RawModel.h"
#include "../texture/SkyboxTextureData.h"

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>

// Ukljucivanje biblioteka
#include <png.h>
#include <vector>
#include <algorithm>
#include <Magick++.h>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace model;
using namespace Magick;
using namespace texture;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa VaoLoader je zaduzena za ucitavanje atributa u memoriju.
  /// Zadatak ove klase je ucitavanje i definisanje objekta pomocu niza atributa
  /// gde se svaki atribut ucitava u baffer koji je niz promenljivih. Ovo dovodi
  /// do komplikovanijeg koda ali kod je genericki i pomocu njega mozemo
  /// ucitavati veoma slozene objekte i texture sto bi bilo vrlo tesko kada bi
  /// smo svaki objekat sami crtali osnovnim OpenGL funkcijama.
  //////////////////////////////////////////////////////////////////////////////
  class VaoLoader {

  // Privatne promenljive klase
  private:

    /// Identifikator niza atributa.
    GLuint vaoID;

    /// Identifikator bafera koji postaje clan niza atributa.
    GLuint vboID;

    /// Niz svih identifikatora niza atributa.
    vector<GLuint> vaos;

    /// Niz svih identifikatora bafera.
    vector<GLuint> vbos;

    /// Niz svih identifikatora tekstura.
    vector<GLint> textures;

  // Javne funkcije klase
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    VaoLoader();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~VaoLoader();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira niz atributa(VAO).
    /// U funkciji se prvo kreira vao i dodeljuje mu se identifikator nakon cega
    /// se parametri funkcije ucitavaju u bafere koji se pridruzuju ranije
    /// kreiranom vao-u.
    /// @param positions[] Niz koordinata objekta
    /// @param positionsSize Broj koordinata koje se nalaze u nizu pozicija
    /// @param indices[] Niz indeksa tacaka radi efikasnijeg kreiranja
    /// modela
    /// @param indicesSize Broj indeksa koji se nalaze u nizu indeka
    /// @param textureCoords Niz koordinata koje oznacavaju na koji
    /// ce nacin objekat biti prektiven teksturom(Npr. da se cela tekstura
    /// razvuce preko objekta ili da se objekat prekrije sa vise istih tekstura
    /// koje se nadovezuju)
    /// @param textureSize Broj koordinata koje se nalaze u nizu koordinata
    /// teksture
    /// @return GLint Identifikator VAO-a
    ////////////////////////////////////////////////////////////////////////////
    GLint loadToVao(GLfloat positions[], GLint positionsSize,
                    GLint indices[], GLint indicesSize,
                    GLfloat textureCoords[], GLint textureSize,
                    GLfloat normals[], GLint normalsSize);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira niz atributa(VAO).
    /// U funkciji se prvo kreira vao i dodeljuje mu se identifikator nakon cega
    /// se parametri funkcije ucitavaju u bafere koji se pridruzuju ranije
    /// kreiranom vao-u.
    /// @param positions[] Niz koordinata objekta
    /// @param positionsSize Broj koordinata koje se nalaze u nizu pozicija
    /// @param indices[] Niz indeksa tacaka radi efikasnijeg kreiranja
    /// modela
    /// @param indicesSize Broj indeksa koji se nalaze u nizu indeka
    /// @param textureCoords Niz koordinata koje oznacavaju na koji
    /// ce nacin objekat biti prektiven teksturom(Npr. da se cela tekstura
    /// razvuce preko objekta ili da se objekat prekrije sa vise istih tekstura
    /// koje se nadovezuju)
    /// @param textureSize Broj koordinata koje se nalaze u nizu koordinata
    /// teksture
    /// @param boneIndices Niz indeksa kostiju
    /// @param boneIndicesSize Borj indeksa kostiju
    /// @param weights Niz tezina kostiju
    /// @param weightsSize Broj tezina kostiju
    /// @return GLint Identifikator VAO-a
    ////////////////////////////////////////////////////////////////////////////
    GLint loadToVao(GLfloat positions[], GLint positionsSize, GLint indices[], GLint indicesSize,
                    GLfloat textureCoords[], GLint textureSize,
                    GLfloat normals[], GLint normalsSize,
                    GLint boneIndices[], GLint boneIndicesSize,
                    GLfloat weights[], GLint weightsSize);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira niz atributa(VAO).
    /// U funkciji se prvo kreira vao i dodeljuje mu se identifikator nakon cega
    /// se parametri funkcije ucitavaju u bafere koji se pridruzuju ranije
    /// kreiranom vao-u.
    /// @param positions[] Niz koordinata objekta.
    /// @param positionsSize Broj koordinata koje se nalaze u nizu pozicija.
    /// @param dimensions Dimenzija prostora.
    /// @return GLint Identifikator VAO-a
    ////////////////////////////////////////////////////////////////////////////
    GLint loadToVao(GLfloat positions[], GLint positionsSize, int dimensions);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava texturu iz png fajla.
    /// U funkciji se pomocu png biblioteke citaju informacije iz fajla koje
    /// se zatim upisuju u OpenGL teksturu sa kreiranim identifikatorom.
    /// @param fileName Ime png fajla.
    /// @return GLint Identifikator teksture.
    ////////////////////////////////////////////////////////////////////////////
    GLint loadTexture(const char *fileName);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava texture u kubnu mapu.
    /// @param textureFiles Niz imena tekstura;
    /// @return GLuint Identifikarot kubne mape tekstura.
    ////////////////////////////////////////////////////////////////////////////
    GLuint loadCubeMap(vector<const char *> textureFiles);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija brise podatke iz memorije.
    /// U funkciji se prethodno kreirani identifikatori brisu zajedno sa
    /// informacijama koje identifikuju.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void cleanUp(void);

  // Privatne funkcije klase.
  private:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija kreira niz atributa(VAO).
    /// @param void
    /// @return int Identifikator kreiranog niza atributa.
    ////////////////////////////////////////////////////////////////////////////
    int createVao(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija startuje bitne procese za funkcionisanje.
    /// U funkciji se kreira bafer u koji se smestaju informacije vazane za
    /// objekat.
    /// @param attributeNumber Indeks niza atributa kojem se pridruzuje bafer.
    /// @param coordinateSize Broj koordinata kojim je tacka definisana,
    /// validne vrednosti su 1,2,3,4.
    /// @param data Niz podataka koji se upisuju u bafer.
    /// @param dataSize Broj podataka koji se nalaze u nizu data.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void storeDataInVertexBuffer(GLint attributeNumber, int coordinateSize, GLfloat data[], GLint dataSize);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija startuje bitne procese za funkcionisanje.
    /// U funkciji se kreira bafer u koji se smestaju informacije vazane za
    /// objekat.
    /// @param attributeNumber Indeks niza atributa kojem se pridruzuje bafer.
    /// @param coordinateSize Broj koordinata kojim je tacka definisana,
    /// validne vrednosti su 1,2,3,4.
    /// @param data Niz podataka koji se upisuju u bafer.
    /// @param dataSize Broj podataka koji se nalaze u nizu data.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void storeDataInVertexBuffer(GLint attributeNumber, int coordinateSize, GLint data[], GLint dataSize);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava indekse tacaka.
    /// U funkciji se kreira bafer u koji se smestaju indeksi tacaka objekta.
    /// @param attributeNumber Indeks niza atributa kojem se pridruzuje bafer.
    /// @param data Niz podataka koji se upisuju u bafer.
    /// @param dataSize Broj podataka koji se nalaze u nizu data.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void storeDataInIndicesBuffer(GLint data[], GLint dataSize);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija prekida vezu sa nizom atributa.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void unbindVao(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava niz u bafer podataka.
    /// U funkciji se podaci iz niza ucitavaju u bafer realnih brojeva zbog
    /// kasnijeg ucitavanja pomocu OpenGL funkcija.
    /// @param data Niz podataka koji se upisuju u bafer.
    /// @param dataSize Broj podataka koji se nalaze u nizu data.
    /// @return vector<float> Bafer prestavljen vektorom realnih podataka.
    ////////////////////////////////////////////////////////////////////////////
    vector<float> storeDataInFloatBuffer(GLfloat data[], GLint dataSize);

    ///////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava niz u bafer podataka.
    /// U funkciji se podaci iz niza ucitavaju u bafer celih brojeva zbog
    /// kasnijeg ucitavanja pomocu OpenGL funkcija.
    /// @param data Niz podataka koji se upisuju u bafer.
    /// @param dataSize Broj podataka koji se nalaze u nizu data.
    /// @return vector<int> Bafer prestavljen celobrojnim vektorom podataka.
    ////////////////////////////////////////////////////////////////////////////
    vector<int> storeDataInIntBuffer(GLint data[], GLint dataSize);

    ///////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija cita podatke iz fajla teksture.
    /// @param fileName Naziv fajla teksture.
    /// @return SkyboxTextureData* Pokazivac na instancu klase SkyboxTextureData
    ////////////////////////////////////////////////////////////////////////////
    SkyboxTextureData *decodeTextureFile(const char *fileName);

  };

} // core

#endif
