////////////////////////////////////////////////////////////////////////////////
/// @file RawModel.h
/// @brief Deklaracija klase RawModel.
/// @author Dusan Pantelic
/// @date Decembar 2017
////////////////////////////////////////////////////////////////////////////////

#ifndef _RAWMODEL_H_
#define _RAWMODEL_H_

// Omogucuje korsicenje novijih verzija OpenGL-a
#define GL_GLEXT_PROTOTYPES

// Ukljucivanje OpenGL biblioteke.
#include <GL/glut.h>
#include <GL/freeglut.h>

// Ukljucivanje biblioteka
#include <vector>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena model.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju model objekta.
////////////////////////////////////////////////////////////////////////////////
namespace model {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa RawModel opisuje model objekta.
  /// Model je opisan brojem tacaka i pridruzenom nizu atributa.
  //////////////////////////////////////////////////////////////////////////////
  class RawModel {

  // Privatne promenljive klase.
  private:

    /// Identifikatori niza atributa.
    vector<GLint> meshesVaoID;

    /// Broj tacaka objekta
    vector<GLint> meshesVertexCount;

  // Javne funkcije klase.
  public:

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// U konstruktoru se modelu pridruzuju broj tacaka objekta i identifikator
    /// niza atributa.
    /// @param meshesVaoID Lista identifikatora niza atributa.
    /// @param meshesVertexCount Lista broja tacaka objekta.
    ////////////////////////////////////////////////////////////////////////////
    RawModel(vector<GLint> meshesVaoID, vector<GLint> meshesVertexCount);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~RawModel();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca listu identifikatora niza atributa objekta.
    /// @param void
    /// @return vector<GLint> Lista identifikatora niza atributa.
    ////////////////////////////////////////////////////////////////////////////
    vector<GLint> getMeshesVaoID(void);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca listu broja tacaka objekta.
    /// @param void
    /// @return vector<GLint> Lista broja tacaka objekta.
    ////////////////////////////////////////////////////////////////////////////
    vector<GLint> getMeshesVertexCount(void);

  };

} // model

#endif
