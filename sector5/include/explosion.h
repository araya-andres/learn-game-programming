#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animation.h"
#include <SFML/System.hpp>

struct Explosion : public Animation {
    Explosion(sf::RenderWindow&, const sf::Vector2f&);
};

#endif
