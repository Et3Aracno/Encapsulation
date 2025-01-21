#include <iostream>
#include <SFML/Graphics.hpp>
#include"Entiter.h"
#include "Player.h"
#include "Ennemie.h"
#include "objet.h"
#include "patrole.h"
#include "Chaser.h"
#ifndef GAME_H
#define	GAME_H
using namespace sf;
using namespace std;


class Game {

public:
	vector<Sprite> textureJ;
	vector<Player> Joueur;
	vector<Ennemie>Mobs;
	Texture txtJ, txtC, txtP;
	Sprite texture_J ,texture_C ,texture_P;
	Clock timermove;
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