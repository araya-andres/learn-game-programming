#ifndef PLATFORM_H
#define PLATFORM_H

#include "chipmunk.hpp"
#include <SFML/Graphics.hpp>

struct Platform
{
    Platform(cp::Space&, const cp::Vect&, const cp::Vect&);
    void draw(sf::RenderWindow&);
private:
    cp::Segment segment_;
    sf::Vertex vertices_[2];
};

#endif
