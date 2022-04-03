/*
* @fichier: main.cpp
* @auteurs:
* @date:
* @description: Tests
*/
#include <iostream>
#include <sstream>
#include <time.h>
#include <clocale>
#include <fstream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

#include "AsciiArt.h"
#include "Foncteur.h"
#include "Land.h"
#include "Creature.h"
#include "Dresseur.h"
#include "DresseurMaitre.h"
#include "CreatureMagique.h"
#include "ObjetMagique.h"
#include "Pouvoir.h"

using namespace std;
const int NB_DRESSEUR = 6, NB_CREATURE = 6;

const string LIGNE = "-------------------------------------------------------------------------------------";

int main() {
	srand(unsigned(time(nullptr)));
	setlocale(LC_ALL, "");
	
	vector<bool> tests;
	AsciiArt art;
	string vous = "Vous";
	cout << BLEU << art.polyland() << FIN << endl;

	/*---------------------------------------------------------------------------------------
	* Debut des TESTS
	----------------------------------------------------------------------------------------*/

	cout << endl << MAUVE << LIGNE << "\n > Debut des tests\n" << LIGNE << FIN << endl;
	cout << MAUVE << "\n > Initialisation de Polyland\n" << LIGNE << FIN << endl;

	// TODO: modifier la declaration de polyLand de type est Land où T => Dresseur et S => Creature
	//!!!!!! VOUS DEVEZ FAIRE APPEL AU CONSTRUCTEUR PAR DEFAUT !!!!!! 
	Land<Dresseur, Creature> polyland;
	
	// Test 1 : constructeurs de classe et operator= de Land
	if (true) {
		try {
			bool success = true;
			// TODO: Créer un attribut land de type Land où T => Dresseur et S => Creature
			Land<Dresseur, Creature> land;
			// TODO: Atribuer land à polyland à l'aide de l'operator=
			land = polyland;
			// TODO: Créer un attribut polymon de type Land où T => DresseurMaitre et S => CreatureMagique
			Land<DresseurMaitre, CreatureMagique> polymon;
			polyland += make_shared<Dresseur>(vous);
			polyland.choisirDresseur(vous)->modifierObjetMagique(ObjetMagique("potion", 200));

			success &= polyland.obtenirDresseurs().size() == NB_DRESSEUR && polyland.obtenirCreatures().size() == NB_CREATURE;

			string result = "Le test 1 ";
			result += success ? VERT + "fonctionne" : ROUGE + "ne fonctionne pas";
			cout << endl << result << FIN << endl << MAUVE << LIGNE << FIN << endl;
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// Test 2 : choisirDresseur, choisirCreature, choisirDresseurAleatoire & choisirCreatureAleatoire
	if (true) {
		try {
			bool success = true;
			string may, psyduck, zoe, charmander;

			may = polyland.choisirDresseur("May")->obtenirNom();
			psyduck = polyland.choisirCreature("Psyduck")->obtenirNom();
			// TODO: Décommenter
			zoe = polyland.choisirDresseurAleatoire(0, 0)->obtenirNom();
			charmander = polyland.choisirCreatureAleatoire(0, 0)->obtenirNom();

			success = may == "May" && psyduck == "Psyduck" && zoe == "Zoe" && charmander == "Charmander";

			string result = "Le test 2 ";
			result += success ? VERT + "fonctionne" : ROUGE + "ne fonctionne pas";
			cout << endl << result << FIN << endl << MAUVE << LIGNE << FIN << endl;
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// Test 3 : Foncteur + algorithme de trie
	if (true) {
		try {
			bool success = true;

			cout << BLEU << "Avant le trie, on obtient l'affichage suivant" << FIN << endl;
			cout << polyland;

			//TODO: Trier dresseurs_ et creatures_ de polyLand par un algorithme et les foncteurs
			// ICI
			polyland.obtenirCreatures().sort();
			polyland.obtenirDresseurs().sort();

			cout << BLEU <<"Apres le trie, on obtient l'affichage suivant: " << FIN << endl;
			cout << polyland;

			// TODO: Décommenter
			success &= polyland.obtenirDresseurs().back()->obtenirNom() == "Zoe" &&
			polyland.obtenirCreatures().back()->obtenirNom() == "Vulpix";
			
			string result = "Le test 3 ";
			result += success ? VERT + "fonctionne" : ROUGE + "ne fonctionne pas";
			cout << result << FIN << endl << MAUVE << LIGNE << FIN << endl;
			tests.push_back(success);

		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}

	// Test 4 : trouver() + Lambda
	if (true) {
		try {
			bool success = true;

			//TODO: Implementer les recherches suivantes
			auto nom = polyland.choisirCreature("Meowth");
			auto attaque = polyland.choisirCreature("Charmander");
			auto energie = polyland.choisirCreature("Bulbasaur");
			
			success &= nom->obtenirNom() == "Meowth" && attaque->obtenirAttaque() == 1 && energie->obtenirEnergie() == 2;

			string result = "Le test 4 ";
			result += success ? VERT + "fonctionne" : ROUGE + "ne fonctionne pas";
			cout << result << FIN << endl << MAUVE << LIGNE << FIN << endl;
			tests.push_back(success);
		}
		catch (...) {
			tests.push_back(false);
		}
	}
	else {
		tests.push_back(false);
	}
	
	cout << MAUVE <<" > Fin des tests\n" << LIGNE << FIN << endl;

	/*---------------------------------------------------------------------------------------
	* Fin des TESTS
	----------------------------------------------------------------------------------------*/
	std::vector<float> ponderationTests = { 2.5, 2.5, 2.5, 2.5};

	// Affichage
	float totalPoints = 0;
	for (size_t i = 0; i < tests.size(); i++) {
		string output = "Test " + to_string(i + 1) + ": ";
		if (tests[i] == true) {
			output += "OK!";
			stringstream stream;
			stream << ponderationTests[i] << '/' << ponderationTests[i];
			cout << left << setw(15) << std::left << output
				<< stream.str() << endl;
			totalPoints += ponderationTests[i];
		}
		else {
			output += "ECHEC!";
			stringstream stream;
			stream << '0' << '/' << ponderationTests[i];
			std::cerr << std::left << std::setw(15) << output << "0/"
				<< ponderationTests[i] << endl;
		}
	}
	std::stringstream stream;
	stream << totalPoints << "/"
		<< accumulate(ponderationTests.begin(), ponderationTests.end(),
			0.0f);
	cout << VERT << left << setw(15) << "TOTAL: " << stream.str() << FIN << endl;

	return 0;
}
