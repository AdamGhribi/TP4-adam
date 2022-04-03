/*
* @fichier: DresseurMaitre.cpp
* @auteurs:
* @date:
* @description: Implementation de la classe DresseurMaitre
*/
#include "DresseurMaitre.h"

DresseurMaitre::DresseurMaitre(const string& nom, const string& nomObjetMagique,
	int bonus, int anneeExperience) :
	Dresseur(nom, nomObjetMagique, bonus), anneeExperience_(anneeExperience)
{}

// Méthode de la classe dérivée
void DresseurMaitre::afficher()const {
	cout << nom_ << " est un Maitre Dresseur" << endl;
	cout << "et a commes annees experience: " << anneeExperience_ << endl;

}

// Méthode de la classe dérivée on ajoute les années d'expérience au  bonus de l'objet magique 
void DresseurMaitre::utiliserObjetMagique(shared_ptr<Creature> creature) {
	std::cout << this->obtenirNom() << " utilise son objet magique de dresseur maitre" << std::endl;

	int  superBonus = this->obtenirObjetMagique().obtenirBonus() * anneeExperience_;
	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= superBonus) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + superBonus);
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > superBonus) {
		creature->modifierEnergie(creature->obtenirEnergie() + superBonus);
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

// Fonction globale pour la  classe  DresseurMaitre
ostream& operator<<(ostream& os, const DresseurMaitre& dresseur) {
	os << static_cast<Dresseur>(dresseur) << endl;
	dresseur.afficher();
	return os;
}


