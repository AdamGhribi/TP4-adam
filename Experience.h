/*
* @fichier: Experience.h
* @auteurs:
* @date:
* @description: classe interface d'experience
*/
#pragma once
#include <string>

class Experience {
public:
	virtual void afficher() const = 0;
	virtual ~Experience() = default;
};
