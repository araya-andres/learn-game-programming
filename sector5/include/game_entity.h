#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <SFML/Graphics.hpp>

struct GameEntity
{
    GameEntity(sf::RenderWindow&, const std::string&);
    virtual ~GameEntity();
    virtual void draw();
    virtual void move();
    const sf::Vector2f& position() const;
    const sf::Vector2f& velocity() const;
    float angle() const;
    void mark_for_deletion();
    bool is_marked_for_deletion() const;

protected:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_;
    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;
    float angle_ = 0;
    float radius_ = 0;
    bool mark_for_deletion_ = false;
};

#endif
