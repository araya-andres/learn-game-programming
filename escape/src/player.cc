#include "helper.h"
#include "player.h"

const float Player::RADIUS = 20.0f;

Player::Player(sf::RenderWindow& w)
    : GameEntity{w, "images/chip.png"}
{
    position_ = vector2u_to_f(window_.getSize() / 2u);
    angle_ = 270.0f;
    radius_ = Player::RADIUS;
}

void Player::update()
{
}