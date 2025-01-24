#pragma once
#include "Entiter.h"
class Player :public Entity {
protected:
	Vector2f position;
	string nom;
public:
	Player(Sprite textureP, Vector2f positionJ);
	void movement(int a);

};