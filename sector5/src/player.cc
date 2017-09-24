#include "helper.h"
#include "player.h"

const float ACCELERATION = 2.0f;
const float FRICTION = 0.9f;
const float ROTATION_SPEED = 15.0f;
const float Player::RADIUS = 20.0f;

Player::Player(sf::RenderWindow& w)
    : GameEntity{w, "images/ship.png"}
{
    position_ = vector2u_to_f(window_.getSize() / 2u);
    angle_ = 270.0f;
    radius_ = Player::RADIUS;
}

void Player::turn_right()
{
    angle_ += ROTATION_SPEED;
}

void Player::turn_left()
{
    angle_ -= ROTATION_SPEED;
}

void Player::update()
{
    position_ += velocity_;
    velocity_ *= FRICTION;
    const auto boundary = window_.getSize();
    if (position_.x < radius_) {
        position_.x = radius_;
        bounce();
    } else if (position_.x > boundary.x - radius_) {
        position_.x = boundary.x - radius_;
        bounce();
    } else if (position_.y < radius_) {
        position_.y = radius_;
        bounce();
    } else if (position_.y > boundary.y - radius_) {
        position_.y = boundary.y - radius_;
        bounce();
    }
}

void Player::accelerate()
{
    velocity_ += ACCELERATION * unit_vector(angle_);
}

void Player::bounce()
{
    const auto towards_center = vector2u_to_f(window_.getSize() / 2u) - position_;
    if (cross_product(velocity_, towards_center).z > .0f) {
        velocity_ = rotate_90_degrees_counterclockwise(velocity_);
        angle_ += 90.0f;
    } else {
        velocity_ = rotate_90_degrees_clockwise(velocity_);
        angle_ -= 90.0f;
    }
}
