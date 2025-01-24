#pragma once
#include "Entiter.h"

class Ennemie :public Entity {
protected:
	Vector2f position;
public:
	Ennemie(Sprite textureE,Vector2f positionE);

};
