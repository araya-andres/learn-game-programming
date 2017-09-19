#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "animation.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <map>

struct Animator
{
    Animator(sf::Sprite& sprite)
        : sprite_{sprite}
        , animations_{}
        , it_{animations_.end()}
    {}

    Animation& createAnimation(
            const std::string& name,
            const std::string& texture,
            const sf::Time& duration,
            bool loop = true
            );

    void update(const sf::Time&);

    bool switchAnimation(const std::string& name);

    std::string getCurrentAnimationName() const;

private:
    using AnimationMap = std::map<std::string, Animation>;
    void switchAnimation(AnimationMap::iterator&);
    sf::Sprite& sprite_;
    sf::Time current_time_;
    AnimationMap animations_;
    AnimationMap::iterator it_;
};


#endif
