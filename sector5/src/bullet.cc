#include "bullet.h"
#include "helper.h"

const float SPEED = 5.0f;
const float Bullet::RADIUS = 3.0f;

Bullet::Bullet(sf::RenderWindow& w, const GameEntity& shooter)
    : GameEntity{w, "images/bullet.png"}
    , shoot_{AssetManager::get<sf::SoundBuffer>("sounds/shoot.ogg")}
{
    angle_ = shooter.angle();
    position_ = shooter.position();
    velocity_ = shooter.velocity() + SPEED * unit_vector(angle_);
    radius_ = Bullet::RADIUS;
    shoot_.play();
}

bool Bullet::is_marked_for_deletion() const
{
    if (shoot_.getStatus() == sf::SoundSource::Status::Playing) {
        return false;
    }
    return GameEntity::is_marked_for_deletion();
}
