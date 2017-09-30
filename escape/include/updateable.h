#ifndef UPDATEABLE_H
#define UPDATEABLE_H

struct Updateable
{
    virtual ~Updateable() {}
    virtual void update() = 0;
};

#endif
