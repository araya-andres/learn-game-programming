#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "animation.h"

struct Explosion : public Animation {
    Explosion(sf::RenderWindow&, const GameEntity&);
    virtual bool is_marked_for_deletion() const override;

private:
    sf::Sound explosion_;
};

#endif
