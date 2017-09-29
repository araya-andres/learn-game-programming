#include "ball.h"

Ball::Ball(cp::Space& space, const cp::Position& position, cpFloat radius, cp::Mass m)
    : position_{position}
    , body_{m, cp::momentForCircle(m, radius)}
    , shape_{cp::Shape::makeCircle(body_, radius)}
    , sprite_{static_cast<float>(radius)}
{
    body_.setPosition(position);
    shape_.setElasticity(.9);
    space.add(body_);
    space.add(shape_);
    sprite_.setOrigin(sf::Vector2f(radius, radius));
    sprite_.setFillColor(color_);
}

void Ball::update()
{
    position_ = body_.getPosition();
}

void Ball::draw(sf::RenderWindow& window)
{
    sprite_.setPosition(sf::Vector2f(position_.x, position_.y));
    window.draw(sprite_);
}
