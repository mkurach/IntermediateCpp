#include "game.hpp"
#include "bird.hpp"

int main() {

    Game game;

    while(game.isRunning() && !game.getEndGame()) {
        game.update();
        game.render();
    }


    return 0;
}