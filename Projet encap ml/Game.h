#include <iostream>
#include <SFML/Graphics.hpp>
#include"Entiter.h"
#include "Player.h"
#include "Ennemie.h"
#include "objet.h"
#include "patrole.h"
#include "Chaser.h"
#include "Key.h"
#include "Popo.h"
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
	vector<Objet>pp_aq;
	vector<Objet>key_aq;
	vector<Objet>popo;
	vector<Objet>clef;
	Texture txtJm, txtC, txtP, txtK, txtPP;
	Sprite texture_Jm, texture_C, texture_P,texture_PP,texture_K;
	Clock timerchase;
	RenderWindow* window;
	bool PPrecup, Keyrecup = false;

	void Gamerun();
	void initAll();
	void initP();
	void initC();
	void initPa();
	void initPP();
	void initK();
	void coli();
	void coliPP();
	void coliKey();
	void chase();
	void PPeffect();
	

};
















#endif