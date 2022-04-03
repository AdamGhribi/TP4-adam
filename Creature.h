/*
* @fichier: Creature.h
* @auteurs:
* @date:
* @description: Les creatures sont des etres destines au combat
*/
#pragma once
#include <string>
#include<iostream>
#include "Pouvoir.h"
#include <memory>

using namespace std;

const string ROUGE = "\033[1;91m", MAUVE = "\033[1;95m", BLEU = "\033[1;96m", VERT = "\u001b[32;1m", FIN = "\033[0m";

class Creature {
public:
	Creature(const string& nom = "noName");
	Creature(const string& nom, unsigned int attaque, unsigned int defense,
		unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir);
	Creature(const Creature& c);

	virtual ~Creature() = default;

	// getters
	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;
	Pouvoir* obtenirPouvoir() const;

	// setters
	void modifierNom(const string& nouveauNom);
	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierPouvoir(Pouvoir pouvoir);

	// methode attaquer de la classe de base
	virtual void attaquer(Creature& creature);

	int experienceGagnee(const Creature& creature);

	// operateur
	Creature& operator=(const Creature& creature);
	bool operator==(const Creature& creature) const;
	bool operator==(const string& nom) const;
	friend bool operator==(const string& nom, const Creature& creature);

	//fonction globale
	friend ostream& operator<<(ostream& os, const Creature& creature);

protected:
	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	unique_ptr<Pouvoir> pouvoir_;
};
