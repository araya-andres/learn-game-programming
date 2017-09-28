#include <cstdlib>
#include <game.h>

int main()
{
    srand(time(nullptr));
    Game::instance().run();
}
