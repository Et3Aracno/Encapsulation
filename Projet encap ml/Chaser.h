#pragma once
#include "Ennemie.h"

class ChaserEnemy :public Ennemie {
public:
	ChaserEnemy(Sprite textureC, Vector2f positionC);
	void followP() {};


};
