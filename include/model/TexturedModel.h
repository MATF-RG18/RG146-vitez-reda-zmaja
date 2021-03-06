////////////////////////////////////////////////////////////////////////////////
/// @file TexturedModel.h
/// @brief Deklaracija klase TexturedModel.
/// @author Dusan Pantelic
/// @date Januar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _TEXTURED_MODEL_H_
#define _TEXTURED_MODEL_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/RawModel.h"
#include "../texture/Texture.h"

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace texture;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena model.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju model objekta.
////////////////////////////////////////////////////////////////////////////////
namespace model {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa TexturedModel opisuje model objekta zajedno sa teksturom.
  /// Model je opisan instancom klase RawModel i odgovarajucom teksturom objekta
  /// pomocu instance klase Texture.
  //////////////////////////////////////////////////////////////////////////////
  class TexturedModel {

  // Privatne promenljive klase.
  private:

    /// Pokazivac na model objekta bez pridruzene strukture.
    RawModel *rawModel;

    /// Lista pokazivaca na teksture delova objekta.
    vector<Texture *> textures;

  // Javne funkcije klase.
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// U konstruktoru se modelu pridruzuju neteksturisani objekat i njegova
    /// tekstura.
    /// @param model Pokazivac na model objekta bez pridruzene strukture.
    /// @param textures Lista pokazivaca na teksture delova objekta.
    ////////////////////////////////////////////////////////////////////////////
    TexturedModel(RawModel *model, vector<Texture *> textures);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~TexturedModel();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca osnovni model objekta.
    /// @param void
    /// @return RawModel Osnovni model objekta.
    ////////////////////////////////////////////////////////////////////////////
    RawModel *getRawModel(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca listu tekstura modela.
    /// @param void
    /// @return vector<Texture *> lista tekstura modela.
    ////////////////////////////////////////////////////////////////////////////
    vector<Texture *> getTextures(void);
  };
  
} // model

#endif
