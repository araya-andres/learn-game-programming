#include "animation.h"
#include <cassert>

Animation::Animation(
        sf::RenderWindow& w,
        const std::string& texture,
        bool looping)
    : GameEntity{w, texture}
    , looping_{looping}
{}

void Animation::add_frames(
        const sf::Vector2i& start_from,
        const sf::Vector2i& frame_size,
        unsigned frames)
{
    auto current = start_from;
    while (--frames > 0) {
        frames_.emplace_back(current.x, current.y, frame_size.x, frame_size.y);
        current.x += frame_size.x;
    }
}

void Animation::update()
{
    GameEntity::update();
    const auto frames = frames_.size();
    assert(frames > 0);
    if (looping_) {
        frame_index_ %= frames;
    } else if (frame_index_ >= frames) {
        frame_index_ = frames - 1;
        mark_for_deletion_ = true;
    }
    auto& current_frame = frames_[frame_index_++];
    sprite_.setTextureRect(current_frame);
    sprite_.setOrigin(.5f * current_frame.width, .5f * current_frame.height);
}
