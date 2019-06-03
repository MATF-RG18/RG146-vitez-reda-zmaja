////////////////////////////////////////////////////////////////////////////////
/// @file Bone.h
/// @brief Deklaracija klase Bone.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _BONE_H_
#define _BONE_H_

// Ukljucivanje biblioteka
#include <string>
#include <vector>
#include <glm/matrix.hpp>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace glm;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena model.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju model objekta.
////////////////////////////////////////////////////////////////////////////////
namespace model {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa Bone opisuje kost modela.
    /// Kost je opisana indeksom, imenom, listom dece, matricom transformacije
    /// animacije i matricom transformacije koordinatnog sistema koske u
    /// koordinatni sistem modela.
    //////////////////////////////////////////////////////////////////////////////
    class Bone {

    // Privatne promenljive klase.
    private:
        /// Identifikator koske.
        int ID;

        /// Ime koske.
        string name;

        /// Lista dece koske.
        vector<Bone*> childrens;

        /// Matrica transformacije animacije.
        mat4 animatedTransform;

        /// Matrica transformacije koordinatnog sistema koske u sistem modela.
        mat4 inverseBindTransform;

    // Javne funkcije klase
    public:

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// U konstruktoru se koski dodeljuje indeks, ime i matrica transformacije
        /// koordinatnog sistema koske u koordinatni sistem modela.
        /// @param ID Identifikator koske.
        /// @param name Ime koske.
        /// @param inverseBindTransform Matrica transformacije koordinatnog sistema koske u sistem modela.
        ////////////////////////////////////////////////////////////////////////////
        Bone(int ID, string name, mat4 inverseBindTransform);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~Bone();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija dodaje kosku u listu dece.
        /// @param Bone * Pokazivac na instancu klase Bone.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void addChild(Bone *child);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca identifikator koske.
        /// @param void
        /// @return int Identifikator koske.
        ////////////////////////////////////////////////////////////////////////////
        int getID();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca listu dece koske.
        /// @param void
        /// @return vector<Bone*> Lista dece koske.
        ////////////////////////////////////////////////////////////////////////////
        vector<Bone*> getChildrens();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca ime koske.
        /// @param void
        /// @return string Ime koske.
        ////////////////////////////////////////////////////////////////////////////
        string getName();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca matricu transformacije animacije.
        /// @param void
        /// @return mat4 Matrica transformacije animacije.
        ////////////////////////////////////////////////////////////////////////////
        mat4 getAnimatedTransform();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija postavlja matricu transformacije animacije.
        /// @param animatedTransform Matrica transformacije animacije.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void setAnimatedTransform(mat4 animatedTransform);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca matricu transformacije koordinatnog sistema koske.
        /// @param void
        /// @return mat4 Matrica transformacije koordinatnog sistema koske.
        ////////////////////////////////////////////////////////////////////////////
        mat4 getInverseBindTransform();
    };

} // model



#endif
