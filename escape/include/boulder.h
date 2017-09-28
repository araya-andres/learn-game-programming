#ifndef BOULDER_H
#define BOULDER_H

#include "chipmunk.hpp"
#include "game_entity.h"

struct Boulder : public GameEntity
{
    Boulder(sf::RenderWindow&, cp::Space&, double x, double y);
    void update() override;

private:
    cp::Body body_;
};

#endif
