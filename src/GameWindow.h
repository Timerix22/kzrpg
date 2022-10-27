#include "../kerep/src/base/base.h"
#include "graphical_APIs.h"


struct GameWindow;
typedef void (*windowLoop_t)(struct GameWindow* gameWindow, float32 deltaT);
typedef struct GameWindow{
    char* title;
    SDL_Rect defaultSize;
    bool fullscreen;
    bool resizeable;
    uint8 fpsLimit; // 0 means no limit
    void (*fpsCallback)(uint16 fps); // NULL by default
    windowLoop_t loop;
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
} GameWindow;

GameWindow* GameWindow_create(
    char* title,
    SDL_Rect defaultSize,
    bool fullscreen,
    bool resizeable,
    windowLoop_t loop);

void GameWindow_free(GameWindow* gameWindow);

void GameWindow_startLoop(GameWindow* gameWindow);
