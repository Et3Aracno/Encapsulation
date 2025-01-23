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
	vector<Ennemie>Mob1;
	vector<Ennemie>Mobs;
	Texture txtJm, txtC, txtP;
	Sprite texture_Jm ,texture_C ,texture_P;
	Clock timermove,timerchase;
	RenderWindow* window;

	void Gamerun();
	void initAll();
	void initP();
	void initC();
	void initP2();
	void coli();
	void Pmove();
	void chase();

};
















#endif