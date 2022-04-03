/*
* @fichier: Land.h
* @auteurs:
* @date:
* @description: Le template Land represente le pays que l'on va explorer, il va contenir les differents elements de jeu
*/
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <list>
#include "Dresseur.h"
#include "Creature.h"
#include "Pouvoir.h"
#include "Foncteur.h"
#include <map>
using namespace std;

const int DRESSEUR = 0, CREATURE = 1;

template<typename T, typename S>
class Land {
public:
	Land() = default;
	Land(string fichier);

	shared_ptr<T> choisirDresseur(string nom);
	shared_ptr<S> choisirCreature(string nom);

	shared_ptr<T> choisirDresseurAleatoire();
	shared_ptr<S> choisirCreatureAleatoire();

	shared_ptr<T> choisirDresseurAleatoire(unsigned int min, unsigned int max);
	shared_ptr<S> choisirCreatureAleatoire(unsigned int min, unsigned int max);

	list<shared_ptr<T>>& obtenirDresseurs();
	list<shared_ptr<S>>& obtenirCreatures();

	bool attraperCreature(const shared_ptr<T>& dresseur, const shared_ptr <S>& creature);
	bool relacherCreature(shared_ptr<T>& dresseur, const  shared_ptr<S>& creature);

	Land& operator=(Land& land);
	Land& operator+=(const shared_ptr<T>& dresseur);
	Land& operator-=(const shared_ptr<T>& dresseur);
	Land& operator+=(const shared_ptr<S>& creature);
	Land& operator-=(const shared_ptr<S>& creature);

	S trouver();

	friend ostream& operator<<(ostream& os, const Land& land) {
		os << "Voici la liste des dresseurs: " << endl;
		for (auto&& i : land.dresseurs_) {
			os << *i;
		}
		os << endl;
		os << "Voici la liste des creatures: " << endl;
		for (auto&& i : land.creatures_) {
			os << *i;
		}
		return os;
	};

private:
	// TODO: Modifier les types de dresseurs_ et creatures_ de vector a List 
	// !!!!! Cette modification impactera le retour et l'implementation de certaines fonctions!
	list<shared_ptr<T>> dresseurs_;
	list<shared_ptr<S>> creatures_;
	// TODO: ajouter polydex une map de shared_ptr<Creature>
	map<string, shared_ptr<S>> polydex_;
};