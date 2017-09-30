#ifndef DRAWABLE_H
#define DRAWABLE_H

struct Drawable
{
    virtual ~Drawable() {}
    virtual void draw() = 0;
};

#endif
