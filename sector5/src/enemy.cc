#include "asset_manager.h"
#include "enemy.h"
#include "helper.h"

const float SPEED = 4.0f;

Enemy::Enemy(sf::RenderWindow& w)
    : GameEntity(w, "images/enemy.png")
{
    const auto origin = sprite_.getOrigin();
    position_ = sf::Vector2f(random(origin.x, window_.getSize().x - origin.x), origin.y);
    velocity_ = sf::Vector2f{.0f, SPEED};
    angle_ = 90.0f;
}
