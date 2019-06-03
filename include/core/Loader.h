////////////////////////////////////////////////////////////////////////////////
/// @file Loader.h
/// @brief Deklaracija klase Loader.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _LOADER_H_
#define _LOADER_H_

// Maksimalan broj kostiju koje uticu na tacku.
#define MAX_BONES_PER_VERTEX 4

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/AnimatedModel.h"
#include "../animation/Animation.h"
#include "../core/VaoLoader.h"

// Ukljucivanje Assimp biblioteke.
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// Ukljucivanje biblioteka.
#include <iostream>
#include <map>
#include <glm/mat4x4.hpp>
#include "glm/ext.hpp"

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace Assimp;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena core.
/// Sadrzi sve klase, funkcije i promenljive koje su od
/// sustinskog znacaja za funkcionisanje programa.
////////////////////////////////////////////////////////////////////////////////
namespace core {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Loader je zaduzena za ucitavanje modela.
  /// Klasa sadrzi funkcije za ucitavanje raznih vrsta modela iz sirokog spektra
  /// fajlova za cuvanje podataka o modelu
  //////////////////////////////////////////////////////////////////////////////
  class Loader {

  // Privatne promenljive klase
  private:
    /// Mapa imena kostiju sa njihovim indeksima.
    vector<map<string, int> *>bonesMap;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    Loader();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Loader();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava podatke o animiranom modelu
    /// Funkcija pomocu biblioteke Assimp ucitva u VAO pomocu VaoLoader-a
    /// pozicije, normale, koordinate tekstura, indekse kostiju i tezine modela.
    /// Takodje se ucitavaju teksture i hijerarhija kostiju.
    /// @param fileName Ime fajla sa podacima o modelu.
    /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
    /// @return AnimatedModel * Pokazivac na instancu klase AnimatedModel.
    ////////////////////////////////////////////////////////////////////////////
    AnimatedModel *loadAnimatedModel(const char *fileName, VaoLoader *vaoLoader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava podatke o teksturisanom modelu
    /// Funkcija pomocu biblioteke Assimp ucitva u VAO pomocu VaoLoader-a
    /// pozicije, normale, koordinate tekstura modela.
    /// Takodje se ucitavaju teksture.
    /// @param fileName Ime fajla sa podacima o modelu.
    /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
    /// @return TexturedModel * Pokazivac na instancu klase TexturedModel.
    ////////////////////////////////////////////////////////////////////////////
    TexturedModel *loadTexturedModel(const char *fileName, VaoLoader *vaoLoader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava podatke o sirovom modelu
    /// Funkcija pomocu biblioteke Assimp ucitva u VAO pomocu VaoLoader-a
    /// pozicije, normale, koordinate tekstura modela.
    /// @param fileName Ime fajla sa podacima o modelu.
    /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
    /// @return RawModel * Pokazivac na instancu klase RawModel.
    ////////////////////////////////////////////////////////////////////////////
    RawModel *loadRawModel(const char *fileName, VaoLoader *vaoLoader);

  // Privatne funkcije klase
  private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava teksture
    /// Funkcija pomocu biblioteke Assimp ucitva u VAO pomocu VaoLoader-a
    /// difuzne teksture, sa predodredjenim faktorom sjaja i reflekcije.
    /// @param material Assimp struktura sa informacijama o materijalu.
    /// @param fileName Ime fajla sa podacima o modelu.
    /// @param vaoLoader Pokazivac na instancu klase VaoLoader.
    /// @return Texture * Pokazivac na instancu klase Texture.
    ////////////////////////////////////////////////////////////////////////////
    Texture *loadMaterial(aiMaterial *material, const char *fileName, VaoLoader *vaoLoader);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava podatke o kostima(indekse i tezine za svaku tacku).
    /// @param mesh Assimp struktura sa informacijama o delu modela.
    /// @param meshID Identifikator dela modela.
    /// @param boneIndices Vektor indeksa kostiju.
    /// @param weights Vektor tezina kostiju.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadBoneData(aiMesh *mesh, int  meshID, vector<int> &boneIndices, vector<float> &weights);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava hijerarhiju kostiju i vraca glavnu kost.
    /// @param mesh Assimp struktura sa informacijama o delu modela.
    /// @param meshID Identifikator dela modela.
    /// @return Bone * Pokazivac na instancu klase Bone.
    ////////////////////////////////////////////////////////////////////////////
    Bone *loadBoneHierarchy(aiNode *rootBone, aiMesh *mesh, int  meshID);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija pronalazi glavnu kost.
    /// @param node Assimp struktura sa informacijama o cvorovima modela.
    /// @param rootBone Assimp za cvor u koji se upisuje glavna kost.
    /// @param meshID Identifikator dela modela.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void findRootBone(aiNode *node, aiNode *&rootBone, int meshID);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava informacije o animacijama modela.
    /// Informacije se skladiste u mapi imena i instanci klase Animation unutar
    /// klase AnimatedModel.
    /// @param animatedModel Pokazivac na instancu klase AnimatedModel.
    /// @param scene  Assimp struktura sa informacijama o sceni.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void loadAnimation(AnimatedModel *animatedModel, const aiScene *scene);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija konvertuje Assimp matricu u glm format.
    /// @param aiMatrix Assimp struktura za matricu.
    /// @return mat4 Konvertovana matrica.
    ////////////////////////////////////////////////////////////////////////////
    mat4 convertAiMatrix(aiMatrix4x4 aiMatrix);

  };

} // core

#endif
