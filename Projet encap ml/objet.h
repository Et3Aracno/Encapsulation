#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entiter.h"
using namespace std;
using namespace sf;

class Objet :public Entity {
protected:
	string nom;
	Vector2f position;
public:
	Objet(Sprite textureO,Vector2f positionO);
};
