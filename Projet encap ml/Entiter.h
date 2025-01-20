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

	Entity(Sprite texture, string nom, int HP, int DMG, int VTS,float x,float y ):sprt(texture){};
	virtual ~Entity() {};

	Sprite& getSprite() {
		return sprt;
	}
	
	/*virtual void update() = 0;
	virtual void draw() = 0;*/
};
class Player:public Entity{
protected:
	float xpx;
	float ypy;
public:
	Player(Sprite textureP, string nom_P, int HP_P, int DMG_P, int VTS_P,float Xp,float Yp):xpx(Xp), ypy(Yp), Entity(textureP, nom_P, HP_P, DMG_P, VTS_P, Xp, Yp) {};
	void move();

};


class Objet :public Entity {
public:
	Objet(Sprite textureO, string nom_O, int DMG_O, int HP_O, int VTS_O, float Xo, float Yo):Entity(textureO, nom_O, HP_O, DMG_O, VTS_O, Xo,Yo){};
};
class Ennemie :public Entity {
public:
	Ennemie(Sprite textureE, string nom_E, int DMG_E, int HP_E, int VTS_E, float Xe, float Ye) :Entity(textureE, nom_E, HP_E, DMG_E, VTS_E ,Xe,Ye) {};

};
class ChaserEnemy :public Ennemie {
public:
	ChaserEnemy(Sprite textureC, string nom_C, int DMG_C, int HP_C, int VTS_C, float Xc, float Yc) :Ennemie(textureC, nom_C, HP_C, DMG_C, VTS_C, Xc, Yc) {};
	void followP() {};


};
class PatrollingEnemy :public Ennemie {
	public:
	PatrollingEnemy(Sprite textureP, string nom_P, int DMG_P, int HP_P, int VTS_P, float Xp, float Yp) :Ennemie(textureP, nom_P, HP_P, DMG_P, VTS_P, Xp, Yp) {};
	void followA() {};


};

#endif