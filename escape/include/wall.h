#ifndef WALL_H
#define WALL_H

#include "chipmunk.hpp"
#include <SFML/Graphics.hpp>

struct Wall
{
    Wall(cp::Space&, float top, float left, float width, float height);
    sf::FloatRect get_bounds();

private:
    cp::Body body_;
    cp::Shape shape_;
    sf::FloatRect rect_;
};

#endif
