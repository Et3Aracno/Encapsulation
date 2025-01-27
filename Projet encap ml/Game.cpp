#include"Game.h"
void Game::initP(){
	
	txtJm.loadFromFile("Walk knight.png");
	texture_Jm.setTexture(txtJm);
	
}
void Game::initC() {
	
	txtC.loadFromFile("idle chaser.png");
	texture_C.setTexture(txtC);
	
}
void Game::initPa() {
	
	txtP.loadFromFile("walk.png");
	texture_P.setTexture(txtP);
	
}
void Game::initK() {
	txtK.loadFromFile("Iron Key.png");
	texture_K.setTexture(txtK);
	
}
void Game::initPP() {
	txtPP.loadFromFile("green PP.png");
	texture_PP.setTexture(txtPP);
	

}
void Game::initMu(){
	txtMu.loadFromFile("mur.png");
	texture_Mu.setTexture(txtPP);
}
void Game::initS(){
	txtS.loadFromFile("sol.png");
	texture_S.setTexture(txtPP);
}
void Game::initD(){
	txtD.loadFromFile("porte.png");
	texture_D.setTexture(txtPP);
}
void Game::initTxt() {

}

void Game::initAll() {
	initP();
	initM("fichier_txt.txt");
	initMu();
	initS();
	initD();
	initC();
	initPa();
	initK();
	initPP();
}
void Game::victory(){
	Font Gagner;
	Gagner.loadFromFile("huggo\\Huggo.otf");
	Text gagner;
	gagner.setFont(Gagner);
	gagner.setString("GAGNER");
	gagner.setStyle(Text::Bold);
	gagner.setCharacterSize(50);
	gagner.setPosition(960, 540);
	window->draw(gagner);
	window->display();
	this_thread::sleep_for(std::chrono::seconds(5));
	window->close();
}
void Game::coliPP() {
	int i = 0;
	for (auto& j : Joueur) {
		auto obj = popo.begin();
		while (obj != popo.end())
			if (j.getSprite().getGlobalBounds().intersects(obj->getSprite().getGlobalBounds())) {
				pp_speed.push_back(popo[i]);
				obj = popo.erase(obj);
				PPrecup = true;
			}
			else {
				obj++;
				PPrecup = false;
			}
		}
	i++;
}
void Game::coliKey() {
	for (auto& j : Joueur) {
		auto key = clef.begin();
		while(key!= clef.end()){
			if (j.getSprite().getGlobalBounds().intersects(key->getSprite().getGlobalBounds())) {
				key = clef.erase(key);
				Keyrecup = true;
			}
			else {
				Keyrecup = false;
				key++;
			}
		}
	}
}
void Game::coli() {
	for (auto& mob : Mobs) {
		for (auto& J : Joueur) {
			if (mob.getSprite().getGlobalBounds().intersects(J.getSprite().getGlobalBounds())) {
				cout << "colision";
				Font perdu;
				perdu.loadFromFile("huggo\\Huggo.otf");
				Text pperdu;
				pperdu.setFont(perdu);
				pperdu.setString("Perdu");
				pperdu.setStyle(Text::Bold);
				pperdu.setCharacterSize(50);
				pperdu.setPosition(960, 540);
				window->draw(pperdu);
				window->display();
				this_thread::sleep_for(std::chrono::seconds(5));
				window->close();
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
	if (PPrecup == true and Keyboard::isKeyPressed(Keyboard::P)) {
		auto pp = pp_speed.begin();
		while (pp != pp_speed.end()) {
			for (auto& j : Joueur) {
				j.movement(4);
				pp = pp_speed.erase(pp);
				PPut = true;
			}
		}
	}
}
void Game::initM(string fileN) {
	ifstream file(fileN);
	if (!file.is_open()) {
		cout << endl << "impossible de lire" << fileN << endl;
	}
	string line;
	while (getline(file, line)) {
		vectM.push_back(line);
	}
}
void Game::drawM() {

	float Width = static_cast<float>(window->getSize().x) / vectM[0].size();
	float Height = static_cast<float>(window->getSize().y) / vectM.size();
	for (size_t i = 0; i < vectM.size(); i++) {
		for (size_t j = 0; j < vectM[0].size(); j++) {
			switch (vectM[i][j])
			{
			case '#':
			{
				RectangleShape mur(Vector2f(80, 99));
				mur.setPosition(Vector2f(80 * j, 99 * i));
				mur.setTexture(&txtMu);
				mur.setPosition(j * Width, i * Height);
				murv.push_back(mur);
				break;
			}

			case'.':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				break;
			}
			
			case 'P':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				Player joueur(texture_Jm, Vector2f(80 * j, 99 * i));
				joueur.getSprite().setPosition(j * Width, i * Height);
				Joueur.push_back(joueur);
				break;
			}
			case 'R':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				PatrollingEnemy patrouilleur(texture_P, Vector2f(80 * j, 99 * i));
				patrouilleur.getSprite().setPosition(j * Width, i * Height);
				Mob1.push_back(patrouilleur);
				break;
			}
			case'C':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				ChaserEnemy chasseur(texture_C, Vector2f(80 * j, 99 * i));
				chasseur.getSprite().setPosition(j * Width, i * Height);
				Mobs.push_back(chasseur);
				break;
			}

			case'D':
			{
				RectangleShape porte(Vector2f(80, 99));
				porte.setPosition(Vector2f(80 * j, 99 * i));
				porte.setTexture(&txtD);
				porte.setPosition(j * Width, i * Height);
				doorv.push_back(porte);
				break;
			}
				
			case 'K':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				Key cle(texture_K, Vector2f(80 * j+200, 99 * i-300));
				cle.getSprite().setPosition(j * Width, i * Height);
				clef.push_back(cle);
				break;
			}
			case'E':
			{
				RectangleShape sol(Vector2f(80, 99));
				sol.setPosition(Vector2f(80 * j, 99 * i));
				sol.setTexture(&txtS);
				sol.setPosition(j * Width, i * Height);
				solv.push_back(sol);
				Popo potion(texture_PP, Vector2f(80 * j, 99 * i));
				potion.getSprite().setPosition(j * Width, i * Height);
				popo.push_back(potion);
				break;
			}
			default:
				break;
			}
		}
	}
}
void Game::gg() {
	for (auto player : Joueur) {
		for (auto porte : doorv) {
			if (Keyrecup == true and player.getSprite().getGlobalBounds().intersects(porte.getGlobalBounds())) {
				victory();
			}
		}
	}
	
}
void Game::Gamerun() {
	window = new RenderWindow(VideoMode(1920, 1080), "Steam Purgator");
	window->setFramerateLimit(120);

	initAll();
	drawM();
	while (window) {
		Event gameEvent;
		while (window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				window->close();
			}
		}
		window->clear();

		for (auto& mur : murv) {
			window->draw(mur);
		}
		for (auto& sol : solv) {
			window->draw(sol);
		}
		for (auto& door : doorv) {
			window->draw(door);
		}

		for (auto& joueur : Joueur) {
			if (PPut == true) {
				joueur.movement(2);
			}
			else
			{
			joueur.movement(1);
			}
			window->draw(joueur.getSprite());
		}
		for (auto& ennemie : Mobs) {
			window->draw(ennemie.getSprite());
		}
		for (auto& ennemie : Mob1) {
			window->draw(ennemie.getSprite());
		}
		for (auto& popo : popo) {
			coliPP();
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
		gg();
		PPeffect();
		chase();
		coli();

		window->display();
	}
}