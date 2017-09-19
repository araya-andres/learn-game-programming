#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

struct Player
{
    Player(sf::RenderWindow&);
    void draw();
    void turn_right();
    void turn_left();

private:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    sf::Sprite sprite_;
    float x_ = 200.0f, y_ = 200.0f;
    float angle_ = .0f;
};

#endif
