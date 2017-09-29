#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "asset_manager.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct GameEntity
{
    GameEntity(sf::RenderWindow&, const std::string&);
    virtual ~GameEntity();
    virtual void draw();
    virtual void update() = 0;
    void mark_for_deletion();
    virtual bool is_marked_for_deletion() const;

protected:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    float angle_ = 0;
    bool mark_for_deletion_ = false;
};

#endif
