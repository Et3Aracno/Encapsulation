#include <iostream>
#include <SFML/Graphics.hpp>
#include"Entiter.h"
#ifndef GAME_H
#define	GAME_H
using namespace sf;
using namespace std;


class Game {

public:
	vector<Sprite> textureJ;
	vector<Player> Joueur;
	vector<Ennemie> Mob1;
	vector<Ennemie> Mob2;
	Texture txtJ, txtC, txtP;


	RenderWindow* window;
	void Gamerun();
	void initAll();
	void initP();
	void initC();
	void initP2();
	void coli();
	void Pmove();

};
















#endif