#include "asset_manager.h"
#include "game_entity.h"
#include "helper.h"

GameEntity::GameEntity(sf::RenderWindow& w, const std::string& fname)
    : window_{w}
    , texture_{AssetManager::get<sf::Texture>(fname)}
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

void GameEntity::update()
{
    velocity_ += acceleration_;
    position_ += velocity_;
    if (!mark_for_deletion_) {
        const sf::FloatRect boundary{{}, vector2u_to_f(window_.getSize())};
        mark_for_deletion_ = !boundary.contains(position_);
    }
}

void GameEntity::mark_for_deletion()
{
    mark_for_deletion_ = true;
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

bool GameEntity::is_marked_for_deletion() const
{
    return mark_for_deletion_;
}
