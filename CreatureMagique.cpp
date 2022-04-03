/*
* @fichier: CreatureMagique.cpp
* @auteurs:
* @date:
* @description:  Implementation de la classe CreatureMagique
*/
#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const string& nom) : Creature(nom), potionMagique_(0) {}

CreatureMagique::CreatureMagique(const string& nom, unsigned int attaque,
    unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir,
    unsigned int potionMagique) : Creature(nom, attaque, defense, pointDeVie, energie, pouvoir), potionMagique_(potionMagique)
{}

CreatureMagique::CreatureMagique(const Creature& creature, unsigned int potionMagique) : potionMagique_(potionMagique), Creature(creature)
{
}

CreatureMagique::CreatureMagique(const CreatureMagique& creature) :
    Creature(creature), potionMagique_(creature.potionMagique_) { }

CreatureMagique& CreatureMagique::operator= (const CreatureMagique& creature) {
    if (this != &creature) {
        Creature::operator= (creature);
        potionMagique_ = creature.potionMagique_;
    }
    return *this;
}
	  
void CreatureMagique::attaquer(Creature& creature) {
    if (obtenirPointDeVie() + potionMagique_ <= obtenirPointDeVieTotal()) {
        modifierPointDeVie(obtenirPointDeVie() + potionMagique_);
    }
    else {
        modifierPointDeVie(obtenirPointDeVieTotal());
    }
    //  dans le cas d'un créature magique  l'attaque réussie une fois sur 4
    if (energie_ >= pouvoir_->obtenirEnergieNecessaire()) {
        if (creature.obtenirPointDeVie() >= 0) {

            int degat = 0;
            int degatPotentiel = static_cast<int>(pouvoir_->obtenirNombreDeDegat()) * (static_cast<int>(attaque_) / 2);

            // Determiner la defense restante de la creature
            int defenseRestante = static_cast<int>(creature.obtenirDefense()) - degatPotentiel;
            if (defenseRestante < 0) {
                degat = -defenseRestante;
                creature.modifierDefense(0);
            }
            else {
                creature.modifierDefense(defenseRestante);
            }
            // L'attaque rate une fois sur 4
            int tentative = rand() % 4;
            if (tentative != 2) {
                std::cout << nom_ << " lance " << pouvoir_->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
                if (degat > creature.obtenirPointDeVie()) {
                    creature.modifierPointDeVie(0);
                    int xp = experienceGagnee(creature);

                    cout << nom_ << " a gagne " << xp << " XP" << endl << endl;
                }
                else {
                    creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
                }

                cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
                energie_ -= pouvoir_->obtenirEnergieNecessaire();
            }
            else {
                std::cout << "Attaque " << pouvoir_->obtenirNom() << " a echouee" << endl;
            }
        }
        else {
            std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
        }
    }
    else {
        cout << this->obtenirNom() << " n'as plus assez d'énergie pour se battre" << endl;
    }
}

void CreatureMagique::afficher() const
{
    cout << nom_ << " est une creature Magique " << endl;
    cout << "et a une potion magique de " << potionMagique_ << endl;
}

std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature)
{
    creature.afficher();
    os << static_cast<Creature>(creature);
    return os;
}