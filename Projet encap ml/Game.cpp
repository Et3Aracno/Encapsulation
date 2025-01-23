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
void Game::initPa() {
	
	txtP.loadFromFile("walk.png");
	texture_P.setTexture(txtP);
	Mob1.emplace_back(PatrollingEnemy(texture_P, "méchant", Vector2f(35.f, 41.f)));
}
void Game::initK() {
	txtK.loadFromFile("Iron Key.png");
	texture_K.setTexture(txtK);
	clef.emplace_back(Key(texture_K, "clef", Vector2f(600.f, 500.f)));
}
void Game::initPP() {
	txtPP.loadFromFile("green PP.png");
	texture_PP.setTexture(txtPP);
	popo.emplace_back(Key(texture_PP, "popo", Vector2f(1920.f, 1080.f)));

}
void Game::initAll() {
	initP();
	initC();
	initPa();
	initK();
	initPP();
}
//void Game::coliPP() {
//	for (auto& j : Joueur) {
//		auto obj = popo.begin();
//		while (obj != popo.end())
//			if(j.getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds())) {
//				pp_aq.emplace_back(obj);
//				obj = popo.erase(obj);
//				PPrecup = true;
//			}
//			else {
//				obj++;
//				PPrecup = false;
//			}
//		}
//}
void Game::coliKey() {
	for (auto& j : Joueur) {
		for (auto key : clef) {
			if (j.getSprite().getGlobalBounds().intersects(key.getSprite().getGlobalBounds())) {

				Keyrecup = true;
			}
			else {
				Keyrecup = false;
			}
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
			if (player.getSprite().getPosition().x > chaser.getSprite().getPosition().x and timerchase.getElapsedTime().asMilliseconds() >= 2) {
				
					chaser.getSprite().move(+1.f, 0.f);
					timerchase.restart();
			
			}
			if (player.getSprite().getPosition().y > chaser.getSprite().getPosition().y and timerchase.getElapsedTime().asMilliseconds() >= 2) {
				
					chaser.getSprite().move(0.f, +1.f);
				
			}
			if (player.getSprite().getPosition().x < chaser.getSprite().getPosition().x and timerchase.getElapsedTime().asMilliseconds() >= 2) {
				
					chaser.getSprite().move(-1.f, 0.f);
				
				
			}
			if (player.getSprite().getPosition().y < chaser.getSprite().getPosition().y and timerchase.getElapsedTime().asMilliseconds() >= 2) {
				
				chaser.getSprite().move(0.f, -1.f);
			
			}
		}
	}
}
void Game::PPeffect() {
	if (PPrecup == true and Keyboard::isKeyPressed(Keyboard::Q)) {
		auto pp = pp_aq.begin();
		while (pp != pp_aq.end()) {

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

		for (auto& joueur : Joueur) {
			joueur.movement(1);
			window->draw(joueur.getSprite());
		}
		for (auto& ennemie : Mobs) {
			window->draw(ennemie.getSprite());
		}
		for (auto& ennemie : Mob1) {
			window->draw(ennemie.getSprite());
		}
		for (auto& popo : popo) {
			if (PPrecup == false) {
				window->draw(popo.getSprite());
			}
		}
		for (auto& clef : clef) {
			coliKey();
			if (Keyrecup == false) {
				window->draw(clef.getSprite());
			}
		}

		chase();
		coli();

		window->display();
	}
}