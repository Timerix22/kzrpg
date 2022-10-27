#include "graphical_APIs.h" 
#include "../kerep/src/base/base.h"
#include "GameWindow.h"

void testGameLoop(GameWindow* gameWindow,float deltaT){

}

void consoleFpsCallback(uint16 fps){
    kprintf("\e[37mframes: %u\n",fps);
}

int main(){
    setlocale(LC_ALL, "en-US.Unicode");
    kprintf("\e[94mkzrpg is starting...\n");
    // kerep init
    ktDescriptors_beginInit();
    ktDescriptors_initKerepTypes();
    ktDescriptors_endInit();
    // sdl init
    sdlErrCheck(SDL_Init(SDL_INIT_VIDEO)!=0);
    GameWindow* gameWindow=GameWindow_create("kzrpg", (SDL_Rect){600,300,800,600}, false, true, testGameLoop);
    gameWindow->fpsCallback=consoleFpsCallback;
    // start game
    kprintf("\e[92mkzrpg started\n");
    GameWindow_startLoop(gameWindow);
    // exit
    kprintf("\e[94mkzrpg is exiting...\n");
    GameWindow_free(gameWindow);
    SDL_Quit();
    kprintf("\e[92mkzrpg exited\n");
    return 0;
}
