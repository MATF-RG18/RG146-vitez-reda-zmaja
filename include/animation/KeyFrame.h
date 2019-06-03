////////////////////////////////////////////////////////////////////////////////
/// @file KeyFrame.h
/// @brief Deklaracija klase KeyFrame.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _KEY_FRAME_H_
#define _KEY_FRAME_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../animation/BoneTransform.h"

// Ukljucivanje biblioteka
#include <map>
#include <vector>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena animation.
/// Sadrzi sve klase, funkcije i promenljive za rad sa animacajima modela.
////////////////////////////////////////////////////////////////////////////////
namespace animation {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa KeyFrame sadrzi podatke o animaciji u odredjenom trenutku.
  /// Pomocu klase KeyFrame cuvamo mapu imena kostiju sa njihovim
  /// transformacijama koje se vezuju za odredjeni trenutak animacije.
  //////////////////////////////////////////////////////////////////////////////
  class KeyFrame {

  // Privatne promenljive klase.
  private:
    /// Trenutak animacije kljucnog frejma.
    float timeStamp;

    /// Mapa imena kostiju sa njihovim transformacijama.
    map<string, BoneTransform *>  positions;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param timeStamp Trenutak animacije kljucnog frejma.
    /// @param positions Mapa imena kostiju sa njihovim transformacijama.
    ////////////////////////////////////////////////////////////////////////////
    KeyFrame(float timeStamp, map<string, BoneTransform *>  positions);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~KeyFrame();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive timeStamp.
    /// @param void
    /// @return float Trenutak animacije kljucnog frejma.
    ////////////////////////////////////////////////////////////////////////////
    float getTimeStamp();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca vrednost privatne promenljive positions.
    /// @param void
    /// @return map<string, BoneTransform *> Mapa kostiju sa njihovim transformacijama.
    ////////////////////////////////////////////////////////////////////////////
    map<string, BoneTransform *> getPositions();
  };

} // animation

#endif
