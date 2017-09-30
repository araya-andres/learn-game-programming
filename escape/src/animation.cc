#include "animation.h"
#include "asset_manager.h"
#include <cassert>

Animation::Animation(
        sf::RenderWindow& window,
        const std::string fname,
        const std::vector<Frame>& frames,
        bool looping,
        float framerate
        )
    : window_{window}
    , texture_{AssetManager::get<sf::Texture>(fname)}
    , frames_{frames}
    , looping_{looping}
    , framerate_{framerate}
{
    sprite_.setTexture(texture_);
}

std::vector<Animation::Frame> Animation::make_frames(
        const sf::Vector2i& start_from,
        const sf::Vector2i& frame_size,
        int n)
{
    std::vector<Frame> frames;
    auto current = start_from;
    while (--n >= 0) {
        frames.emplace_back(current.x, current.y, frame_size.x, frame_size.y);
        current.x += frame_size.x;
    }
    return frames;
}

void Animation::update()
{
    const auto frames = frames_.size();
    assert(frames > 0);
    elapsed_time_ += clock_.restart();
    if (elapsed_time_.asSeconds() > framerate_) {
        ++frame_index_;
        elapsed_time_ = sf::seconds(.0f);
    }
    if (looping_) {
        frame_index_ %= frames;
    } else if (frame_index_ >= frames) {
        frame_index_ = frames - 1;
    }
    auto& current_frame = frames_[frame_index_];
    sprite_.setTextureRect(current_frame);
    sprite_.setOrigin(.5f * current_frame.width, .5f * current_frame.height);
}

void Animation::draw()
{
    sprite_.setRotation(angle_);
    sprite_.setPosition(position_);
    window_.draw(sprite_);
}

void Animation::set_position(float x, float y)
{
    position_.x = x;
    position_.y = y;
}

void Animation::set_scale(float factor_x, float factor_y)
{
    sprite_.setScale(factor_x, factor_y);
}

void Animation::set_angle(float angle)
{
    angle_ = angle;
}

void Animation::reset()
{
    frame_index_ = 0;
}

bool Animation::done()
{
    return !looping_ && frame_index_ == frames_.size() - 1;
}
