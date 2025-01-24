#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include<sstream>
#include"Entiter.h"
#include "Player.h"
#include "Ennemie.h"
#include "objet.h"
#include "patrole.h"
#include "Chaser.h"
#include "Key.h"
#include "Popo.h"
#include "thread"
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
	vector<Objet>pp_speed;
	vector<Objet>key_aq;
	vector<Objet>popo;
	vector<Objet>clef;
	vector<RectangleShape>murv;
	vector<RectangleShape>solv;
	vector<RectangleShape>doorv;
	vector<string> vectM;
	RenderWindow* window;
	Texture txtJm, txtC, txtP, txtK, txtPP,txtMu,txtD,txtS;
	Sprite texture_Jm, texture_C, texture_P,texture_PP,texture_K,texture_Mu,texture_D,texture_S;
	Clock timerchase , timerpopo;
	
	bool PPrecup, Keyrecup,PPut = false;

	void Gamerun();
	void initAll();
	void initP();
	void initC();
	void initPa();
	void initPP();
	void initK();
	void initMu();
	void initS();
	void initD();
	void victory();
	void initTxt();
	void initM(string);
	void coli();
	void coliPP();
	void coliKey();
	void chase();
	void PPeffect();
	void drawM();
	void gg();
	/*void Dmap();*/

	

};
















#endif