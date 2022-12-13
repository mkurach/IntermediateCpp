#include "script.hpp"
#include "piec.hpp"
#include <ncurses.h>

int main(int argc, char *argv[]) {

    Piec *piec = new Piec(0);
    Script script(argv[1],*piec);
    script.readScript();
    
    return 0;
}