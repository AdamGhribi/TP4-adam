/*
* @fichier: Creature.cpp
* @auteurs:
* @date:
* @description: Implementation de la classe Creature
*/
#include "Creature.h"

Creature::Creature(const string& nom) :nom_(nom), attaque_(0), defense_(0), pointDeVie_(0),
energie_(0), experience_(0), niveau_(1)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
	pouvoir_ = nullptr;
}

Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir) :
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1), pouvoir_(make_unique<Pouvoir>(pouvoir)), pointDeVieTotal_(pointDeVie)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}
Creature::Creature(const Creature& c) : nom_(c.nom_), energieTotal_(c.energieTotal_), attaque_(c.attaque_), defense_(c.defense_),
pointDeVie_(c.pointDeVie_), energie_(c.energie_), experience_(c.experience_), niveau_(c.niveau_), pointDeVieTotal_(c.pointDeVieTotal_)

{
	if (c.obtenirPouvoir() != nullptr) {
		pouvoir_ = make_unique<Pouvoir>(*c.pouvoir_);
	}
	else {
		pouvoir_ = nullptr;
	}

}

string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

Pouvoir* Creature::obtenirPouvoir() const
{
	return pouvoir_.get();
}

// Methode attaquer de la classe de base
void Creature::attaquer(Creature& creature)
{
	if (energie_ >= pouvoir_->obtenirEnergieNecessaire()) {
		if (creature.obtenirPointDeVie() >= 0) {

			int degat = 0;

			int degatPotentiel = static_cast<int>(pouvoir_->obtenirNombreDeDegat()) * (static_cast<int>(attaque_) / 2);

			// Determiner la defense restante de la creature
			int defenseRestante = static_cast<int>(creature.defense_) - degatPotentiel;

			if (defenseRestante < 0)
			{
				degat = -defenseRestante;
				creature.defense_ = 0;
			}
			else {
				creature.defense_ = defenseRestante;
			}

			// L'attaque rate une fois sur 6
			int tentative = rand() % 6;

			if (tentative != 3) {

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
	else
	{
		cout << this->obtenirNom() << " n'as plus assez d'énergie pour se battre" << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mysterieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else {
			//Sinon elle recupere juste de l'experience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(const string& nouveauNom) {
	nom_ = nouveauNom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int mana)
{
	energie_ = mana;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoir(Pouvoir pouvoir)
{
	pouvoir_ = make_unique<Pouvoir >(pouvoir);
}

Creature& Creature::operator=(const Creature& creature) {
	if (this != &creature)
	{
		nom_ = creature.nom_;
		attaque_ = creature.attaque_;
		defense_ = creature.defense_;
		pointDeVie_ = creature.pointDeVie_;
		energie_ = creature.energie_;
		experience_ = creature.experience_;
		pointDeVieTotal_ = creature.pointDeVieTotal_;
		niveau_ = creature.niveau_;
		pouvoir_ = make_unique<Pouvoir>(*creature.pouvoir_.get());
	}
	return *this;
}

bool Creature::operator==(const Creature& creature) const {
	return (nom_ == creature.nom_ && attaque_ == creature.attaque_ && defense_ == creature.defense_ && pointDeVie_ == creature.pointDeVie_
		&& pointDeVieTotal_ == creature.pointDeVieTotal_ && energie_ == creature.energie_ && energieTotal_ == creature.energieTotal_
		&& experience_ == creature.experience_ && experienceNecessaire_ == creature.experienceNecessaire_ && niveau_ == creature.niveau_);
}

bool Creature::operator==(const std::string& nom) const {
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Creature& creature) {
	return (creature == nom);
}

ostream& operator<<(std::ostream& os, const Creature& creature) {
	os << '\t' << MAUVE << creature.nom_ << FIN << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense, " << endl
		<< '\t' << "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << endl
		<< '\t' << "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << "d'XP" << endl
		<< '\t' << "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau " << endl;
	os << '\t' << "Son pouvoir  est : " << endl;
	if (creature.pouvoir_ != nullptr)
		os <<'\t' << *creature.pouvoir_;
	os << endl;

	return os;
}
