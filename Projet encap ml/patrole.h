#pragma once
#include "Ennemie.h"

class PatrollingEnemy :public Ennemie {
	public:
	PatrollingEnemy(Sprite textureP, string nom_P,Vector2f positionP);
	void followA() {};


};




