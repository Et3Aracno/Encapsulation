#include"Game.h"
void Game::initP(){
	
	txtJm.loadFromFile("Walk knight.png");
	texture_Jm.setTexture(txtJm);
	Joueur.emplace_back(Player(texture_Jm, "J1",Vector2f(500.f,900.f)));
}
void Game::initC() {
	
	txtC.loadFromFile("idle chaser.png");
	texture_C.setTexture(txtC);
	Mobs.emplace_back(ChaserEnemy(texture_C, "méchant", Vector2f(35.f, 41.f)));
}
void Game::initP2() {
	
	txtP.loadFromFile("walk.png");
	texture_P.setTexture(txtP);
	Mob1.emplace_back(PatrollingEnemy(texture_P, "méchant", Vector2f(35.f, 41.f)));
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
void Game::chase() {
	for (auto& chaser : Mobs) {
		for (auto& player : Joueur) {
			if ( timerchase.getElapsedTime().asMilliseconds() >= 2 and player.getSprite().getPosition().x > chaser.getSprite().getPosition().x) {
				chaser.getSprite().move(1.f, 0.f);
				timerchase.restart();
			}
			if (timerchase.getElapsedTime().asMilliseconds() >= 2 and player.getSprite().getPosition().y > chaser.getSprite().getPosition().y) {
				chaser.getSprite().move(0.f, 1.f);
				timerchase.restart();
			}
			if (timerchase.getElapsedTime().asMilliseconds() >= 2 and player.getSprite().getPosition().x < chaser.getSprite().getPosition().x) {
				chaser.getSprite().move(-1.f, 0.f);
				timerchase.restart();
			}
			if (timerchase.getElapsedTime().asMilliseconds() >= 2 and player.getSprite().getPosition().y < chaser.getSprite().getPosition().y) {
				chaser.getSprite().move(0.f, -1.f);
				timerchase.restart();
			}
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
		for (auto& ennemie : Mob1) {
			window->draw(ennemie.getSprite());
		}
		chase();
		coli();

		window->display();
	}
}