#include "objet.h"
Objet::Objet(Sprite textureO, string nom_O, Vector2f positionO) :nom(nom_O),position(positionO), Entity(textureO){}