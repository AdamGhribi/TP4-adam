/*
* @fichier: Dresseur.h
* @auteurs:
* @date:
* @description: Les dresseurs sont les etres capables d'attraper des creatures
*/
#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Creature.h"
#include "ObjetMagique.h"
#include "CreatureMagique.h"

using namespace std;

class Dresseur {
public:
	Dresseur(const string& nom = "", const string& nomObjetMagique = "", int bonus = 0);
	virtual ~Dresseur() = default;

	// getters
	string obtenirNom() const;
	ObjetMagique obtenirObjetMagique() const;
	unsigned int obtenirNombreCreatures() const;
	std::vector<shared_ptr<Creature>>obtenirCreatures() const;

	// setters
	void modifierNom(const string& nom);
	void modifierObjetMagique(const ObjetMagique& objetMagique);
	void modifierCreature(vector<shared_ptr<Creature>>& creatures);

	// methode de la classe de base
	virtual void utiliserObjetMagique(shared_ptr<Creature> creature);

	bool ajouterCreature(const shared_ptr<Creature>& creature);
	bool supprimerCreature(const std::string& nom);

	// operateur
	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Dresseur& dresseur);

	// fonction globale
	friend std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur);

protected:
	string nom_;
	vector<shared_ptr<Creature>> creatures_;
	ObjetMagique objetMagique_;
};
