#include"Game.h"
void Game::initP(){
	
	Sprite texture_j;
	txtJ.loadFromFile("C:/Users/mluhat/Downloads/sirène.png");
	texture_j.setTexture(txtJ);
	Player J1(texture_j, "J1", 12, 15, 75, 41., 42.);
	Joueur.emplace_back(J1);
	window->draw(texture_j);
}
void Game::initC() {

	Sprite texture_C;
	txtC.loadFromFile("C:/Users/mluhat/Downloads/sirène.png");
	textureJ.emplace_back(texture_C);
	Mob1.emplace_back(ChaserEnemy(texture_C, "méchant", 15, 25, 85, 32., 31.));
}

void Game::initP2() {
	Sprite texture_P;
	txtP.loadFromFile("C:/Users/mluhat/Downloads/sirène.png");
	textureJ.emplace_back(texture_P);
	Mob2.emplace_back(PatrollingEnemy(texture_P, "méchant", 15, 25, 85, 32., 31.));
}
void Game::initAll() {
	initP();
	initC();
	initP2();
}
void Game::Pmove() {
	for (auto player : Joueur) {
		player.move();
	}
}
void Game::Gamerun() {
	this->window = new RenderWindow(VideoMode(1920, 1080), "Steam Purgator");
	initAll();
	while (window) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
			
			
			Pmove();
			

			window->clear();
			for (auto J1 : Joueur) {
				window->draw(J1.getSprite());
			}
			for (auto pmb : Mob1) {
				window->draw(pmb.getSprite());
			}
			for (auto dmb : Mob2) {
				window->draw(dmb.getSprite());
			}
			window->display();



		}
	}
}