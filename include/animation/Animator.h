////////////////////////////////////////////////////////////////////////////////
/// @file Animator.h
/// @brief Deklaracija klase Animator.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/AnimatedModel.h"
#include "../animation/Animation.h"
#include "../utility/FpsData.h"

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace model;
using namespace utility;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena animation.
/// Sadrzi sve klase, funkcije i promenljive za rad sa animacajima modela.
////////////////////////////////////////////////////////////////////////////////
namespace animation {

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Klasa Animator kontrolise animaciju modela.
  /// Pomocu klase Animator kontrolisemo ponasanje animacije i racunamo
  /// neophodne podatke za pravilno renderovanje animiranog modela.
  //////////////////////////////////////////////////////////////////////////////
  class Animator {

  // Privatne promenljive klase.
  private:
    /// Pokazivac na instancu klase AnimatedModel.
    AnimatedModel *model;

    /// Pokazivac na instancu klase Animation.
    Animation *currentAnimation;

    /// Trenutno vreme animacije.
    float animationTime;

    /// Pokazivac na instancu klase FpsData.
    FpsData *fpsData;

  // Javne funkcije klase
  public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Konstruktor klase.
    /// @param model  Pokazivac na instancu klase AnimatedModel.
    /// @param fpsData Pokazivac na instancu klase FpsData.
    ////////////////////////////////////////////////////////////////////////////
    Animator(AnimatedModel *model, FpsData *fpsData);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destruktor klase.
    /// @param void
    ////////////////////////////////////////////////////////////////////////////
    ~Animator();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija inicijalizuje podatke o animaciji.
    /// @param animation Pokazivac na instancu klase Animation.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void doAnimation(Animation *animation);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija azurira podatke o animaciji.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void update();

  // Privatne funkcije klase
  private:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija povecava trenutno vreme animacije.
    /// @param void
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void increaseAnimationTime();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna matrice transformacije za trenutno pozu modela.
    /// @param void
    /// @return map<string, mat4> Mapa imena kostiju i njihovih matrica transformacije.
    ////////////////////////////////////////////////////////////////////////////
    map<string, mat4> calculateCurrentAnimationPose();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija ucitava matrice transformacije
    /// U funkciji se racunaju matrice transformacije na osnovu hijerarhije
    /// kostiju i ucitavju se u instance klase Bone.
    /// @param currentPose Mapa imena kostiju i njihovih matrica transformacije.
    /// @param parentTransform Matrica transformacije roditeljske koske.
    /// @return void
    ////////////////////////////////////////////////////////////////////////////
    void applyPoseToBones(map<string, mat4> currentPose, Bone *bone, mat4 parentTransform);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija vraca dva kljucna frejma.
    /// U funkciji se pronalaze dva kljucna frejma izmedju cijih vremena
    /// izvrsavanja je trenutno vreme animacije.
    /// @param void
    /// @return vector<KeyFrame *> Vektor pokazivaca na instance klase KeyFrame.
    ////////////////////////////////////////////////////////////////////////////
    vector<KeyFrame *> getPreviousAndNextFrames();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna progresiju izmedju dva kljucna vrejma.
    /// @param void
    /// @return float Procenat progresije ka sledecem frejmu u intervalu [0,1].
    ////////////////////////////////////////////////////////////////////////////
    float calculateProgression(KeyFrame *previous, KeyFrame *next);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Funkcija racuna interpolisane matrice transformacije.
    /// U funkciji se racunaju matrice transformacije koje su interpolacija
    /// matrica transformacije dva kljucna frejma sa zadatim faktorom progresije.
    /// @param previous Vektor pokazivaca na instance klase KeyFrame.
    /// @param next Vektor pokazivaca na instance klase KeyFrame.
    /// @param progression Procenat progresije ka sledecem frejmu u intervalu [0,1].
    /// @return map<string, mat4> Mapa imena kostiju i njihovih matrica transformacije.
    ////////////////////////////////////////////////////////////////////////////
    map<string, mat4> interpolatePoses(KeyFrame *previous, KeyFrame *next, float progression);
  };

} // animation

#endif
