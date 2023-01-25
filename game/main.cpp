#include "game.hpp"
#include "bird.hpp"
#include <time.h>

int main() {

    srand(time(0));
    Game game;

    while(game.isRunning() && !game.getEndGame()) {
        game.update();
        game.render();
    }

    game.printResults();

    return 0;
}
