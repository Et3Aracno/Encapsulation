#include"Game.h"
void Game::initP(){
	
	txtJ.loadFromFile("C:/Users/mluhat/Downloads/sirène.png");
	texture_J.setTexture(txtJ);
	Joueur.emplace_back(Player(texture_J, "J1",Vector2f(500.f,900.f)));
}
void Game::initC() {
	
	txtC.loadFromFile("C:/Users/mluhat/Downloads/nuage.png");
	texture_C.setTexture(txtC);
	Mobs.emplace_back(ChaserEnemy(texture_C, "méchant", Vector2f(35.f, 41.f)));
}
void Game::initP2() {
	
	txtP.loadFromFile("C:/Users/mluhat/Downloads/Bombe.png");
	texture_P.setTexture(txtP);
	Mobs.emplace_back(PatrollingEnemy(texture_P, "méchant", Vector2f(35.f, 41.f)));
}
void Game::initAll() {
	initP();
	initC();
	initP2();
}
void Game::Pmove() {
	for (auto player : Joueur) {
		
		if (Keyboard::isKeyPressed(Keyboard::Q) and timermove.getElapsedTime().asSeconds()>=1) {
			player.getSprite().move(-1.f,0.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) and timermove.getElapsedTime().asSeconds() >= 1) {
			player.getSprite().move(1.f, 0.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Z) and timermove.getElapsedTime().asSeconds() >= 1) {
			player.getSprite().move(0.f, 1.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::S) and timermove.getElapsedTime().asSeconds() >= 1) {
			player.getSprite().move(0.f, -1.f);
		}
	}
}
void Game::coli() {
	for (auto& mob : Mobs) {
		for (auto& J : Joueur) {
			if (mob.getSprite().getGlobalBounds().intersects(J.getSprite().getGlobalBounds())) {
				cout << "colision";
			};
		}
	}
}

void Game::Gamerun() {
	this->window = new RenderWindow(VideoMode(1920, 1080), "Steam Purgator");
	this->window->setFramerateLimit(120);

	initAll();
	while (window) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
		}
		window->clear();
		
		for (auto& joueur : Joueur ) {
			joueur.movement();
			window->draw(joueur.getSprite());
		}
		for (auto& ennemie : Mobs) {
			window->draw(ennemie.getSprite());
		}
		coli();

		window->display();
	}
}