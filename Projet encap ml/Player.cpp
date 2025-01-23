#include "Player.h"
void Player::movement(int a) {
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		sprt.move(-1.f - a, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		sprt.move(1.f+a, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		sprt.move(0.f, 1.f+a);
	}
	if (Keyboard::isKeyPressed(Keyboard::Z)) {
		sprt.move(0.f, -1.f-a);
	}
}

Player::Player(Sprite textureP, string nom_P, Vector2f positionJ) : position(positionJ), nom(nom_P), Entity(textureP) {
};
