#include "Entiter.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void Player::move() {
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		xpx -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		xpx += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		ypy += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		ypy -= 1;
	}
}