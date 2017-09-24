#ifndef ANIMATION_H
#define ANIMATION_H

#include "game_entity.h"
#include <string>
#include <vector>

struct Animation : public GameEntity
{
    Animation(
            sf::RenderWindow&,
            const std::string& texture,
            bool looping = true);

    void add_frames(
            const sf::Vector2i& start_from,
            const sf::Vector2i& frame_size,
            unsigned frames);

    void update();

private:
    int frame_index_ = 0;
    bool looping_;
    std::vector<sf::IntRect> frames_;
};

#endif
