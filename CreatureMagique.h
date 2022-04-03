/*
* @fichier: CreatureMagique.h
* @auteurs:
* @date:
* @description: Les creatures magiques
*/
#pragma once
#include "Creature.h"

class CreatureMagique : public Creature {
public:
	CreatureMagique(const string& nom = "");
	CreatureMagique(const string& nom, unsigned int attaque, unsigned int defense,
		unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, unsigned int potionMagique);
	CreatureMagique(const Creature& creature, unsigned int potionMagique);
	CreatureMagique(const CreatureMagique& creature);

	~CreatureMagique() = default;

	// méthode override
	void attaquer(Creature& creature)override;

	void afficher() const;

	CreatureMagique& operator= (const CreatureMagique& creature);
	friend std::ostream& operator<<(std::ostream& os, const CreatureMagique& creature);

private:
	unsigned int potionMagique_;
};
