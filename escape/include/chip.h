#ifndef CHIP_H
#define CHIP_H

#include <list>
#include <map>

#include "chipmunk.hpp"

#include "drawable.h"
#include "updateable.h"

#include "animation.h"

class Chip: public Drawable, public Updateable
{
    enum Action
    {
        JUMP,
        RUN,
        STAND,
    };

public:
    Chip(sf::RenderWindow&, cp::Space&, double x, double y);
    void set_action(Action);
    void update() override;
    void draw() override;
    sf::FloatRect get_bounds() override;
    void move_right();
    void move_left();
    void jump();
    void check_footing(const std::vector<sf::FloatRect>&);

private:
    void initialize_animations();

    sf::RenderWindow& window_;
    cp::Body body_;
    cp::Shape shape_;
    std::map<Action, Animation> animation_;
    Action current_action_{Action::STAND};
    bool off_ground_{true};
};

#endif
