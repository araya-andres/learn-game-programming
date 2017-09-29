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

void GameEntity::mark_for_deletion()
{
    mark_for_deletion_ = true;
}

bool GameEntity::is_marked_for_deletion() const
{
    if (mark_for_deletion_) {
        return true;
    }
    const sf::FloatRect boundary{{}, vector2u_to_f(window_.getSize())};
    return !boundary.contains(position_);
}
