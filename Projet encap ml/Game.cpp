#include"Game.h";
void Game::initP(){
	
	Texture txtJ;
	Sprite texture_j;
	txtJ.loadFromFile("C:/Users/mluhat/Pictures/Screenshots/Capture d'écran 2024-12-09 155909.png");
	texture_j.setTexture(txtJ);
	textureJ.emplace_back(texture_j);
	Joueur.emplace_back(new Player(txtJ,"bonjour", 12, 15, 75, 41, 42));
}


void Game::initAll() {
	initP();
}
void Game::Gamerun() {
	this->window = new RenderWindow(VideoMode(1920, 1080), "Steam Purgator");
	while (window) {
		Event gameEvent;
		while (this->window->pollEvent(gameEvent)) {
			if (gameEvent.type == Event::Closed) {
				this->window->close();
			}
			initP();

		}
	}
}