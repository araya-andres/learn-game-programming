#include "asset_manager.h"
#include "enemy.h"
#include "helper.h"

const float SPEED = 4.0f;

Enemy::Enemy(sf::RenderWindow& w)
    : window_(w)
    , texture_(AssetManager::getTexture("images/enemy.png"))
{
    const auto origin = vector2u_to_f(texture_.getSize() / 2u);
    sprite_.setTexture(texture_);
    sprite_.setOrigin(origin);
    position_ = sf::Vector2f(random(origin.x, window_.getSize().x - origin.x), origin.y);
}

void Enemy::draw()
{
    sprite_.setPosition(position_);
    window_.draw(sprite_);
}

void Enemy::move()
{
    position_.y += SPEED;
}
