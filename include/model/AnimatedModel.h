////////////////////////////////////////////////////////////////////////////////
/// @file AnimatedModel.h
/// @brief Deklaracija klase AnimatedModel.
/// @author Dusan Pantelic
/// @date Maj 2019
////////////////////////////////////////////////////////////////////////////////

#ifndef _ANIMATED_MODEL_H_
#define _ANIMATED_MODEL_H_

// Ukljucivanje korsnicki defininisanih biblioteka.
#include "../model/TexturedModel.h"
#include "../model/Bone.h"
#include "../animation/Animation.h"

// Ukljucivanje biblioteka
#include <map>

// Koriscenje prostora imena za jednostavniji i pregledniji kod.
using namespace std;
using namespace animation;

////////////////////////////////////////////////////////////////////////////////
/// @brief Prostor imena model.
/// Sadrzi sve klase, funkcije i promenljive koje opisuju model objekta.
////////////////////////////////////////////////////////////////////////////////
namespace model {

    //////////////////////////////////////////////////////////////////////////////
    /// @brief Klasa AnimatedModel opisuje model objekta zajedno sa teksturom i animacijom.
    /// Model je opisan instancom klase TexturedModel, nizom glavnih kostiju i
    /// mapom animacija.
    //////////////////////////////////////////////////////////////////////////////
    class AnimatedModel {

    // Privatne promenljive klase.
    private:
        /// Pokazivac na instancu klase TexturedModel.
        TexturedModel *model;

        /// Vektor pokazivaca na instance klase Bone.
        vector<Bone *> rootNodes;

        /// Vektor broja kostiju.
        vector<int> bonesCount;

        /// Mapa imena animacija sa pokazivacima na instance klase Animation.
        map<string, Animation*> animations;

        /// Broj glavnih kostiju.
        int numRootNodes;

    // Javne funkcije klase.
    public:
        ////////////////////////////////////////////////////////////////////////////
        /// @brief Konstruktor klase.
        /// U konstruktoru se modelu pridruzuju teksturisan model, lista glavnih
        /// kostiju i brojem kostiju u svakom delu modela.
        /// @param model Pokazivac na instancu klase TexturedModel.
        /// @param rootNodes Vektor pokazivaca na instance klase Bone.
        /// @param bonesCount Vektor broja kostiju.
        ////////////////////////////////////////////////////////////////////////////
        AnimatedModel(TexturedModel *model, vector<Bone *> rootNodes, vector<int> bonesCount);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Destruktor klase.
        /// @param void
        ////////////////////////////////////////////////////////////////////////////
        ~AnimatedModel();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca teksturisan model objekta.
        /// @param void
        /// @return TexturedModel Pokazivac na instancu klase TexturedModel.
        ////////////////////////////////////////////////////////////////////////////
        TexturedModel *getModel();

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca glavnu kost za deo modela.
        /// @param rootBoneID Identifikator dela modela za koji se trazi glavna kost.
        /// @return Bone * Pokazivac na instancu klase Bone.
        ////////////////////////////////////////////////////////////////////////////
        Bone *getRootNode(int rootBoneID);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca matrice transformacija kostiju dela modela.
        /// @param rootBoneID Identifikator dela modela za koji se traze matrice.
        /// @return mat4 * Niz matrica transformacija kostiju.
        ////////////////////////////////////////////////////////////////////////////
        mat4 *getBoneTransforms(int rootBoneID);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija dodaje matricu transformacije koske u niz matrica.
        /// @param headBone Roditeljska kost.
        /// @param boneMatrices Niz matrica transformacija kostiju.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void addBones(Bone *headBone, mat4 *boneMatrices);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca animaciju iz mape animacija.
        /// @param animationName Ime animacije koje je kljuc mape animacija.
        /// @return Animation * Pokazivac na instancu klase Animation.
        ////////////////////////////////////////////////////////////////////////////
        Animation *getAnimation(string animationName);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija dodaje animaciju u mapu animacija.
        /// @param animationName Ime animacije koje je kljuc mape animacija.
        /// @param animation Pokazivac na instancu klase Animation.
        /// @return void
        ////////////////////////////////////////////////////////////////////////////
        void addAnimation(string animationName, Animation *animation);

        ////////////////////////////////////////////////////////////////////////////
        /// @brief Funkcija vraca vrednost privatne promenljive numRootNodes.
        /// @param void
        /// @return int Broj glavnih kostiju.
        ////////////////////////////////////////////////////////////////////////////
        int getNumRootNodes();
    };

} // model


#endif
