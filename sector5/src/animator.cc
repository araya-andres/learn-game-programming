#include "animator.h"
#include "asset_manager.h"
#include <cassert>
#include <tuple>
#include <utility>

Animation& Animator::createAnimation(
        const std::string& name,
        const std::string& texture,
        const sf::Time& duration,
        bool loop
        )
{
    AnimationMap::iterator it;
    std::tie(it, std::ignore) = animations_.try_emplace(name, texture, duration, loop);
    if (animations_.size() == 1) switchAnimation(it);
    return it->second;
}

void Animator::update(const sf::Time& dt)
{
    if (it_ == animations_.end()) return;
    current_time_ += dt;
    const auto& animation = it_->second;
    const auto scaled_time = current_time_.asSeconds() / animation.duration_.asSeconds();
    const auto frames = animation.frames_.size();
    assert(frames > 0);
    auto current_frame = static_cast<unsigned>(scaled_time * frames);
    if (animation.looping_)
        current_frame %= frames;
    else if (current_frame >= frames)
        current_frame = frames - 1;
    sprite_.setTextureRect(animation.frames_[current_frame]);
}

bool Animator::switchAnimation(const std::string& name)
{
    auto it = animations_.find(name);
    if (it == animations_.end()) return false;
    switchAnimation(it);
    return true;
}

void Animator::switchAnimation(AnimationMap::iterator& it)
{
    auto& animation = it->second;
    sprite_.setTexture(AssetManager::getTexture(animation.texture_));
    it_ = it;
    current_time_ = sf::Time::Zero;
}

std::string Animator::getCurrentAnimationName() const
{
    return it_ != animations_.end()
        ? it_->first
        : "";
}
