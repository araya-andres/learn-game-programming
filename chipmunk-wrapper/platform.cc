#include "platform.h"

Platform::Platform(cp::Space& space, const cp::Vect& a, const cp::Vect& b)
    : segment_{space.getStaticBody(), a, b}
{
    segment_.setFriction(1);
    space.add(segment_);
    vertices_[0] = sf::Vector2f(a.x, a.y);
    vertices_[1] = sf::Vector2f(b.x, b.y);
}

void Platform::draw(sf::RenderWindow& window)
{
    window.draw(vertices_, 2, sf::Lines);
}
