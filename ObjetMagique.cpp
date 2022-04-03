/*
* @fichier: ObjetMagique.cpp
* @auteurs:
* @date:
* @description: Implementation de la classe ObjetMagique
*/
#include "ObjetMagique.h"

ObjetMagique::ObjetMagique(const string& nom, int bonus) :
	nom_(nom), bonus_(bonus) {}

string ObjetMagique::obtenirNom() const {
	return nom_;
}

int ObjetMagique::obtenirBonus() const {
	return bonus_;
}

void ObjetMagique::modifierNom(const string& nom) {
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus) {
	bonus_ = bonus;
}

ostream& operator<<(ostream& os, const ObjetMagique& objet) {
	return os << "Un " << objet.nom_ << " qui fournit un bonus de " << objet.bonus_ << endl;
}
