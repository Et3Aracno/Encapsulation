#pragma once
#include "Ennemie.h"

class ChaserEnemy :public Ennemie {
public:
	ChaserEnemy(Sprite textureC, string nom_C, Vector2f positionC);
	void followP() {};


};
