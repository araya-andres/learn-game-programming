#ifndef WALL_H
#define WALL_H

#include "chipmunk.hpp"

struct Wall
{
    Wall(cp::Space&, double top, double left, double width, double height);

private:
    cp::Body body_;
    cp::Shape shape_;
};

#endif
