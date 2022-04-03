/*
* @fichier: Dresseur.cpp
* @auteurs:
* @date:
* @description: Implementation de la classe Dresseur
*/
#include "Dresseur.h"

Dresseur::Dresseur(const string& nom, const string& nomObjetMagique, int bonus) :
	nom_(nom), objetMagique_(nomObjetMagique, bonus) {}


string Dresseur::obtenirNom() const {
	return nom_;
}

void Dresseur::modifierNom(const string& nom) {
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique() const {
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique& objetMagique) {
	objetMagique_ = objetMagique;
}

//   cette méthode ne change pas pour la classe de base
void Dresseur::utiliserObjetMagique(shared_ptr<Creature> creature) {

	std::cout << this->obtenirNom() << " utilise son objet magique de dresseur" << std::endl;

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

unsigned int Dresseur::obtenirNombreCreatures() const {
	return static_cast<unsigned int>(creatures_.size());
}

std::vector<shared_ptr<Creature>>Dresseur::obtenirCreatures() const {
	return creatures_;
}

void Dresseur::modifierCreature(vector<shared_ptr<Creature>>& creatures) {
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(const shared_ptr<Creature>& creature) {
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i].get() == creature.get()) {
			return false;
		}
	}
	creatures_.push_back(creature);
	return true;
}

bool Dresseur::supprimerCreature(const string& nom) {
	for (unsigned int i = 0; i < creatures_.size(); i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] = creatures_.back();
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const Dresseur& dresseur) {
	os << '\t' << MAUVE << dresseur.nom_ << FIN << " possede " << dresseur.creatures_.size() << " creature(s)" << endl;

	for (shared_ptr<Creature> c : dresseur.creatures_) {
		if (dynamic_cast<CreatureMagique*>(c.get())) {
			os << "Creature magique:" << std::endl;
		}
		os << *c << endl;
		os << dresseur.nom_ << " possede l'objet suivant: " << endl;
		os << dresseur.objetMagique_;
	}

	return os;
}

bool Dresseur::operator==(const Dresseur& dresseur) const {
	if (creatures_.size() == 0 && dresseur.creatures_.size() == 0) {
		return true;
	}
	else if (creatures_.size() == dresseur.creatures_.size()) {
		for (unsigned int j = 0; j < dresseur.creatures_.size(); j++) {
			if ((creatures_[j]).get() != (dresseur.creatures_[j].get())) {
				return false;
			}
		}
	}
	return true;
}

bool Dresseur::operator==(const std::string& nom) const {
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur) {
	return dresseur == nom;
}
