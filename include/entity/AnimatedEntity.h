#ifndef _ANIMATED_ENTITY_H_
#define _ANIMATED_ENTITY_H_

// Ukljucivanje biblioteka.
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/AnimatedModel.h"

// Makro za definisanje broja PI.
#define PI 3.14159265

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace model;
using namespace std;
using namespace glm;

namespace entity {

  class AnimatedEntity {
    // Privatne promenljive klase.
    private:

      AnimatedModel *model;

      /// Pozicija entiteta.
      vec3 position;

      /// Rotacija entiteta.
      vec3 rotation;

      /// Skaliranje entiteta.
      float scale;

    // Javne funkcije klase.
    public:


      AnimatedEntity (AnimatedModel *model, vec3 position, vec3 rotation, float scale);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Destruktor klase.
      /// @param void
      ////////////////////////////////////////////////////////////////////////////
      ~AnimatedEntity ();


      AnimatedModel *getModel();

      void setModel(AnimatedModel *model);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija vraca poziciju entiteta.
      /// @param void
      /// @return vec3 Pozicija entiteta.
      ////////////////////////////////////////////////////////////////////////////
      vec3 getPosition();

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija postavlja poziciju entiteta.
      /// @param position Pozicija entiteta.
      /// @return void
      ////////////////////////////////////////////////////////////////////////////
      void setPosition(vec3 position);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija vraca rotaciju entiteta.
      /// @param void
      /// @return vec3 Rotacija entiteta.
      ////////////////////////////////////////////////////////////////////////////
      vec3 getRotation();

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija postavlja rotaciju entiteta.
      /// @param rotation Rotacija entiteta.
      /// @return void
      ////////////////////////////////////////////////////////////////////////////
      void setRotation(vec3 rotation);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija vraca skaliranje entiteta.
      /// @param void
      /// @return float Skaliranje entiteta.
      ////////////////////////////////////////////////////////////////////////////
      float getScale();

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija postavlja skaliranje entiteta.
      /// @param scale Skaliranje entiteta.
      /// @return void
      ////////////////////////////////////////////////////////////////////////////
      void setScale(float scale);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija povecava poziciju entiteta.
      /// @param deltaPosition Pozicija entiteta.
      /// @return void
      ////////////////////////////////////////////////////////////////////////////
      void increasePosition(vec3 deltaPosition);

      ////////////////////////////////////////////////////////////////////////////
      /// @brief Funkcija povecava rotaciju entiteta.
      /// @param deltaRotation Rotacija entiteta.
      /// @return void
      ////////////////////////////////////////////////////////////////////////////
      void increaseRotation(vec3 deltaRotation);
  };

}

#endif
