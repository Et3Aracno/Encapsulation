#pragma once
#include "Entiter.h"

class Ennemie :public Entity {
protected:
	string nom;
	Vector2f position;
public:
	Ennemie(Sprite textureE, string nom_E,Vector2f positionE);

};
