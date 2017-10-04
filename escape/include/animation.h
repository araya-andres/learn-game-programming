#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

struct Animation
{
    using Frame = sf::IntRect;

    Animation(
            sf::RenderWindow&,
            const std::string fname,
            const std::vector<Frame>&,
            bool looping = true,
            float framerate = 1.0f / 24
            );
    static std::vector<Frame> make_frames(
            const sf::Vector2i& start_from,
            const sf::Vector2i& frame_size,
            int frames);
    void update();
    void draw();
    void set_position(float x, float y);
    void set_angle(float angle);
    void set_scale(float factor_x, float factor_y);
    void reset();
    bool done();

private:
    sf::RenderWindow& window_;
    sf::Texture& texture_;
    std::vector<Frame> frames_;
    bool looping_;
    float framerate_;

    sf::Sprite sprite_;
    sf::Vector2f position_;
    float angle_;
    sf::Clock clock_;
    sf::Time elapsed_time_;
    unsigned frame_index_{0};
};

#endif
