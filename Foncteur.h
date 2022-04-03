/*
* @fichier: Foncteur.h
* @auteurs:
* @date:
* @description: Les foncteurs
*/
#pragma once

#include <string>
#include <stdlib.h>

#include "Dresseur.h"
#include "Creature.h"

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 5

// TODO

class FoncteurComparerDresseur {
public:
	FoncteurComparerDresseur(shared_ptr<Dresseur> d1, shared_ptr<Dresseur> d2) :
		d1_(d1), d2_(d2) {}
	bool operator() (shared_ptr<Dresseur> d1, shared_ptr<Dresseur> d2) {
		return (d1->obtenirNom() < d2->obtenirNom());
	}
private:
	shared_ptr<Dresseur> d1_;
	shared_ptr<Dresseur> d2_;
};

class FoncteurComparerCreature {
public:
	FoncteurComparerCreature(shared_ptr<Creature> c1, shared_ptr<Creature> c2) :
		c1_(c1), c2_(c2) {}
	bool operator() (shared_ptr<Creature> c1, shared_ptr<Creature> c2) {
		return (c1->obtenirNom() < c2->obtenirNom());
	}
private:
	shared_ptr<Creature> c1_;
	shared_ptr<Creature> c2_;
};

class FoncteurGenerateurNombreAlea {
public:
	FoncteurGenerateurNombreAlea(int borneInf=0, int borneSup=6): 
		borneInf_(borneInf), borneSup_(borneSup) {}
	int operator()() {
		return rand() % borneSup_ + borneInf_;
	};
private:
	int borneInf_;
	int borneSup_;
};