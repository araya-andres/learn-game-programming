#include "asset_manager.h"
#include "helper.h"
#include "player.h"
#include <cmath>

const float ACCELERATION = 2.0f;
const float FRICTION = 0.99f;
const float ROTATION_SPEED = 3.0f;

Player::Player(sf::RenderWindow& w)
    : window_(w)
    , texture_(AssetManager::getTexture("images/ship.png"))
{
    sprite_.setTexture(texture_);
    sprite_.setOrigin(vector2u_to_f(texture_.getSize() / 2u));
    position_ = vector2u_to_f(window_.getSize() / 2u);
}

void Player::draw()
{
    sprite_.setRotation(angle_);
    sprite_.setPosition(position_);
    window_.draw(sprite_);
}

void Player::turn_right()
{
    angle_ += ROTATION_SPEED;
}

void Player::turn_left()
{
    angle_ -= ROTATION_SPEED;
}

void Player::move()
{
    position_ += velocity_;
    velocity_ *= FRICTION;
}

void Player::accelerate()
{
    const auto radians = M_PI * angle_ / 180;
    velocity_ += ACCELERATION * sf::Vector2f(sin(radians), -cos(radians));
}
