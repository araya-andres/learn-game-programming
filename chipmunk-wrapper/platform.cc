#include "platform.h"

Platform::Platform(cp::Space& space, const cp::Vect& a, const cp::Vect& b)
    : segment_{space.GetStaticBody(), a, b}
{
    segment_.SetFriction(1);
    space.Add(segment_);
    vertices_[0] = sf::Vector2f(a.x, a.y);
    vertices_[1] = sf::Vector2f(b.x, b.y);
}

void Platform::draw(sf::RenderWindow& window)
{
    window.draw(vertices_, 2, sf::Lines);
}
