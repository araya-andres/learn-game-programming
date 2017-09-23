#include "asset_manager.h"
#include "game_entity.h"
#include "helper.h"

GameEntity::GameEntity(sf::RenderWindow& w, const std::string& fname)
    : window_(w)
    , texture_(AssetManager::getTexture(fname))
{
    sprite_.setTexture(texture_);
    sprite_.setOrigin(vector2u_to_f(texture_.getSize() / 2u));
}

GameEntity::~GameEntity()
{
}

void GameEntity::draw()
{
    sprite_.setRotation(angle_);
    sprite_.setPosition(position_);
    window_.draw(sprite_);
}

void GameEntity::move()
{
    velocity_ += acceleration_;
    position_ += velocity_;
}

const sf::Vector2f& GameEntity::position() const
{
    return position_;
}

const sf::Vector2f& GameEntity::velocity() const
{
    return velocity_;
}
float GameEntity::angle() const
{
    return angle_;
}
