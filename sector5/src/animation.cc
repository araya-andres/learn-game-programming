#include "animation.h"

Animation& Animation::addFrames(
        const sf::Vector2i& startFrom,
        const sf::Vector2i& frameSize,
        unsigned frames)
{
    auto current = startFrom;
    while (--frames > 0) {
        frames_.emplace_back(current.x, current.y, frameSize.x, frameSize.y);
        current.x += frameSize.x;
    }
    return *this;
}
