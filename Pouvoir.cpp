/*
* @fichier: Pouvoir.h
* @auteurs:
* @date:
* @description: Implementation de la classe Pouvoir
*/
#include "Pouvoir.h"

Pouvoir::Pouvoir(const string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire) :
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::obtenirNom() const
{
	return nom_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}


bool Pouvoir::operator==(const Pouvoir& pouvoir) const
{
	return (nom_ == pouvoir.nom_);
}

void Pouvoir::afficher() const {
	cout << nom_ << ": possede un nombre de degat de " << nombreDeDegat_
		<< " et une energie necessaire de " << energieNecessaire_ << endl;
}
ostream& operator<<(ostream& os, const Pouvoir& pouvoir)
{
	pouvoir.afficher();
	return os;
}
