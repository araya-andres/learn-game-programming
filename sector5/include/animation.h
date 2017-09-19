#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

struct Animation
{
    Animation(
            const std::string& texture,
            const sf::Time& duration,
            bool looping = true)
        : texture_(texture)
        , duration_(duration)
        , looping_(looping)
    {}

    Animation& addFrames(
            const sf::Vector2i& startFrom,
            const sf::Vector2i& frameSize,
            unsigned frames);

    std::string texture_;
    sf::Time duration_;
    bool looping_;
    std::vector<sf::IntRect> frames_;
};

#endif
