/*
* @fichier: DresseurMaitre.h
* @auteurs:
* @date:
* @description: Les dresseurs experimentes
*/
#pragma once
#include "Dresseur.h"
#include "Experience.h"

using namespace std;

class DresseurMaitre : public Dresseur, public Experience {
public:
	DresseurMaitre(const string& nom = "", const string& nomObjetMagique = "", int bonus = 0, int anneeExperience = 0);

	~DresseurMaitre() = default;

	// méthodes override
	void utiliserObjetMagique(shared_ptr<Creature> creature) override;
	void afficher() const override;

	friend std::ostream& operator<<(std::ostream& os, const DresseurMaitre& dresseur);

private:
	unsigned int  anneeExperience_;
};
