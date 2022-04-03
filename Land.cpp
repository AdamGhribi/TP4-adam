/*
* @fichier: Land.h
* @auteurs:
* @date:
* @description: Le template Land represente le pays que l'on va explorer, il va contenir les differents elements de jeu
*/
#include "Land.h"

template<typename T, typename S>
Land<T,S>::Land(string nomFichier) {
	ifstream fichier(nomFichier);
	if (!fichier.is_open()) {
		cout << "Error opening file";
		exit(-1);
	}

	// Dresseur
	string nomDresseur;

	// Objet magique
	string nomObjet, bonus;

	// Creature
	string nomCreature, attaque, defense, pointDeVie, energie;

	// Pouvoir
	string nomPouvoir, nombreDeDegat, manaNecessaire;

	string type;
	while (!fichier.eof()) {

		getline(fichier, type, '\t');

		switch (stoi(type)) {
		case DRESSEUR:
			getline(fichier, nomDresseur, '\t');
			getline(fichier, nomObjet, '\t');
			getline(fichier, bonus);
			// if est pour lire le fichier sous Mac et retire le \r à la fin de la ligne
			if (bonus[bonus.size() - 1] == '\r') {
				bonus.resize(bonus.size() - 1);
			}
			*this += make_shared<T>(nomDresseur, nomObjet, stoi(bonus));
			cout << "Le dresseur " << nomDresseur << " a bien ete ajoute!\n";
			break;

		case CREATURE:
			getline(fichier, nomCreature, '\t');
			getline(fichier, attaque, '\t');
			getline(fichier, defense, '\t');
			getline(fichier, pointDeVie, '\t');
			getline(fichier, energie, '\t');
			getline(fichier, nomPouvoir, '\t');
			getline(fichier, nombreDeDegat, '\t');
			getline(fichier, manaNecessaire);
			// if est pour lire le fichier sous Mac et retire le \r à la fin de la ligne
			if (manaNecessaire[manaNecessaire.size() - 1] == '\r')
				manaNecessaire.resize(manaNecessaire.size() - 1);
			*this += make_shared<S>(nomCreature, stoi(attaque), stoi(defense), stoi(pointDeVie), stoi(energie),
				Pouvoir(nomPouvoir, stoi(nombreDeDegat), stoi(manaNecessaire)));
			cout << "La creature " << nomCreature << " a bien ete ajoute!\n";
			break;

		default:
			break;
		}
	}
}

//TODO: Utiliser le foncteur FoncteurGenerateurNombresAlea
template<typename T, typename S>
shared_ptr<T> Land<T,S>::choisirDresseurAleatoire() {
	if (dresseurs_.size() > 0) {
		FoncteurGenerateurNombreAlea generateur = FoncteurGenerateurNombreAlea(0, dresseurs_.size());
		return dresseurs_[generateur()];
	}
	else {
		return nullptr;
	}
}

//TODO: Utiliser le foncteur FoncteurGenerateurNombresAlea
template<typename T, typename S>
shared_ptr<S> Land<T,S>::choisirCreatureAleatoire() {
	if (creatures_.size() > 0) {
		FoncteurGenerateurNombreAlea generateur = FoncteurGenerateurNombreAlea(0, creatures_.size());
		return creatures_[generateur()];
	}
	else {
		return nullptr;
	}
}

//TODO: Utiliser le foncteur FoncteurGenerateurNombresAlea
template<typename T, typename S>
shared_ptr<T> Land<T,S>::choisirDresseurAleatoire(unsigned int min, unsigned int max) {
	if (dresseurs_.size() > 0) {
		FoncteurGenerateurNombreAlea generateur = FoncteurGenerateurNombreAlea(min, max);
		return dresseurs_[generateur()];
	}
	else {
		return nullptr;
	}
}

//TODO: Utiliser le foncteur FoncteurGenerateurNombresAlea
template<typename T, typename S>
shared_ptr<S> Land<T,S>::choisirCreatureAleatoire(unsigned int min, unsigned int max) {
	if (creatures_.size() > 0) {
		FoncteurGenerateurNombreAlea generateur = FoncteurGenerateurNombreAlea(min, max);
		return creatures_[generateur()];
	}
	else {
		return nullptr;
	}
}

// TODO: Utiliser un algorithme pour chercher le dresseur
//		 Aucune boucle for ou while
template<typename T, typename S>
shared_ptr<T> Land<T,S>::choisirDresseur(string nom) {
	auto dresseur = find_if(dresseurs_.begin(), dresseurs_.end(), [](shared_ptr<T> dresseur) { return dresseur->obtenirNom() == nom; });
	return dresseur;
}

// TODO: Utiliser polydex pour retourner la creature
template<typename T, typename S>
shared_ptr<S> Land<T,S>::choisirCreature(string nom) {
	auto creature = find_if(creatures_.begin(), creatures_.end(), [](shared_ptr<S> creature) { return creature->obtenirNom() == nom; });
		return creature;
}

template<typename T, typename S>
list<shared_ptr<T>>& Land<T,S>::obtenirDresseurs() {
	return dresseurs_;
}

template<typename T, typename S>
list<shared_ptr<S>>& Land<T,S>::obtenirCreatures() {
	return creatures_;
}

template<typename T, typename S>
bool Land<T,S>::attraperCreature(const shared_ptr<T>& dresseur, const shared_ptr <S>& creature) {
	return dresseur->ajouterCreature(creature);
}

template<typename T, typename S>
bool Land<T,S>::relacherCreature(shared_ptr<T>& dresseur, const  shared_ptr<S>& creature) {
	return dresseur->supprimerCreature(creature->obtenirNom());
}

// TODO: A implementer
template<typename T, typename S>
Land<T,S>& Land<T,S>::operator=(Land& land) {
	if (this != &land) {
		dresseurs_ = land.dresseurs_;
		creatures_ = land.creatures_;
		polydex_ = land.polydex_;
	}
	return *this;
}

template<typename T, typename S>
Land<T,S>& Land<T,S>::operator+=(const shared_ptr<T>& dresseur) {
	dresseurs_.push_back(dresseur);
	return *this;
}

template<typename T, typename S>
Land<T,S>& Land<T,S>::operator-=(const shared_ptr<T>& dresseur) {
	dresseurs_.erase(std::remove(dresseurs_.begin(), dresseurs_.end(), dresseur), dresseurs_.end());
	return *this;
}

template<typename T, typename S>
S Land<T, S>::trouver()
{
	return S();
}


// TODO: Ajouter la creature a la map polydex
template<typename T, typename S>
Land<T,S>& Land<T,S>::operator+=(const shared_ptr<S>& creature) {
	creatures_.push_back(creature);
	polydex_.insert(creature->obtenirNom(), creature);
	return *this;
}

// TODO: Utiliser un algorithme pour retirer la creature
//		 Aucune boucle for ou while
template<typename T, typename S>
Land<T,S>& Land<T,S>::operator-=(const shared_ptr<S>& creature) {
	creatures_.erase(std::remove(creatures_.begin(), creatures_.end(), creature), creatures_.end());
	polydex_.erase(creature->obtenirNom());
	return *this;
}
