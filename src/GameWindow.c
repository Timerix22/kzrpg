#include "GameWindow.h"

GameWindow* GameWindow_create(
    char* title,
    SDL_Rect defaultSize,
    bool fullscreen,
    bool resizeable,
    windowLoop_t loop) 
{
    GameWindow* gameWindow=malloc(sizeof(GameWindow));
    // copying properties
    gameWindow->title=title;
    gameWindow->defaultSize=defaultSize;
    gameWindow->fullscreen=fullscreen;
    gameWindow->resizeable=resizeable;
    gameWindow->fpsLimit=60;
    gameWindow->fpsCallback=NULL;
    gameWindow->loop=loop;
    // creating sdl window
    Uint32 windowFlags=SDL_WINDOW_OPENGL;
    if(fullscreen)
        windowFlags|=SDL_WINDOW_FULLSCREEN;
    if(resizeable)
        windowFlags|=SDL_WINDOW_RESIZABLE;
    gameWindow->sdlWindow=SDL_CreateWindow(title,
        defaultSize.x, defaultSize.y, defaultSize.w, defaultSize.h, 
        windowFlags);
    sdlErrCheck(gameWindow->sdlWindow==NULL);
    // creating sdl renderer
    gameWindow->sdlRenderer=SDL_CreateRenderer(gameWindow->sdlWindow,1,SDL_RENDERER_ACCELERATED);
    sdlErrCheck(gameWindow->sdlRenderer==NULL);
    return gameWindow;
}

void GameWindow_free(GameWindow* gameWindow){
    SDL_DestroyWindow(gameWindow->sdlWindow);
    SDL_DestroyRenderer(gameWindow->sdlRenderer);
    free(gameWindow);
}

void GameWindow_startLoop(GameWindow* gameWindow){
    uint16 fps=0;
    Uint64 lastSecondTick=SDL_GetTicks64();
    Uint64 minTickDelta;
    if(gameWindow->fpsLimit==0)
        minTickDelta=0;
    // 1000 sdl ticks = 1 s
    else minTickDelta=1000/gameWindow->fpsLimit;
    Uint64 prevTick=SDL_GetTicks64();
    while(true){
        Uint64 tickNow=SDL_GetTicks64();
        Uint64 tickDelta=tickNow-prevTick;
        if(tickDelta < minTickDelta){
            SDL_Delay(minTickDelta-tickDelta);
            tickNow=SDL_GetTicks64();
            tickDelta=tickNow-prevTick;
        }
        prevTick=tickNow;
        if(tickNow-lastSecondTick>=999){
            if(gameWindow->fpsCallback)
                gameWindow->fpsCallback(fps);
            lastSecondTick=tickNow;
            fps=0;
        }
        float32 deltaTime=tickDelta/1000;
        gameWindow->loop(gameWindow, deltaTime);
        SDL_RenderPresent(gameWindow->sdlRenderer);
        fps++;
    }
}
