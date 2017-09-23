#include "bullet.h"
#include "helper.h"

const float SPEED = 5.0f;
const float Bullet::RADIUS = 3.0f;

Bullet::Bullet(sf::RenderWindow& w, const GameEntity& shooter)
    : GameEntity{w, "images/bullet.png"}
{
    angle_ = shooter.angle();
    position_ = shooter.position();
    velocity_ = shooter.velocity() + SPEED * unit_vector(angle_);
    radius_ = Bullet::RADIUS;
}
