#include "platform.h"

Platform::Platform(cp::Space& space, const cp::Vect& a, const cp::Vect& b)
    : shape_{cp::Shape::makeSegment(space.getStaticBody(), a, b)}
{
    shape_.setFriction(1);
    space.add(shape_);
    vertices_[0] = sf::Vector2f(a.x, a.y);
    vertices_[1] = sf::Vector2f(b.x, b.y);
}

void Platform::draw(sf::RenderWindow& window)
{
    window.draw(vertices_, 2, sf::Lines);
}
