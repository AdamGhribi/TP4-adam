/*
* @fichier: ObjetMagique.h
* @auteurs:
* @date:
* @description: La classe ObjetMagique correspond aux differents objets utilisable par le dresseur sur ses creatures
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class ObjetMagique {
public:

	ObjetMagique(const string& nom = "", int bonus = 0);
	std::string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	//void afficher() const;
	friend ostream& operator<<(ostream& os, const ObjetMagique& objet);

private:
	string nom_;
	int bonus_;
};


