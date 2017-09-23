#include "helper.h"
#include "player.h"
#include <cmath>

const float ACCELERATION = 2.0f;
const float FRICTION = 0.99f;
const float ROTATION_SPEED = 3.0f;

Player::Player(sf::RenderWindow& w)
    : GameEntity(w, "images/ship.png")
{
    position_ = vector2u_to_f(window_.getSize() / 2u);
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
    const auto boundary = window_.getSize();
    if (position_.x < radius_) {
        position_.x = radius_;
        velocity_ = rotate_90_degrees(velocity_);
        angle_ += 270;
    } else if (position_.x > boundary.x - radius_) {
        position_.x = boundary.x - radius_;
        velocity_ = rotate_90_degrees(velocity_);
        angle_ += 270;
    } else if (position_.y < radius_) {
        position_.y = radius_;
        velocity_ = rotate_90_degrees(velocity_);
        angle_ += 270;
    } else if (position_.y > boundary.y - radius_) {
        position_.y = boundary.y - radius_;
        velocity_ = rotate_90_degrees(velocity_);
        angle_ += 270;
    }
}

void Player::accelerate()
{
    const auto radians = M_PI * angle_ / 180;
    velocity_ += ACCELERATION * sf::Vector2f(sin(radians), -cos(radians));
}
