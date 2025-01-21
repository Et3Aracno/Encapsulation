#include <iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#ifndef ENTITER_H
#define	ENTITER_H
using namespace std;
using namespace sf;

class Entity {
protected:
	Sprite sprt;
public:
	Entity(Sprite _sprt);
	virtual ~Entity() {};
	Sprite& getSprite() {
		return sprt;
	}
	
	//virtual void update() = 0;
	//virtual void draw() = 0;
};








#endif