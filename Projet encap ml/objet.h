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
	Objet(Sprite textureO, string nom_O,Vector2f positionO);
};
