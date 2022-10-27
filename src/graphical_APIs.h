#include <GL/gl.h>
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"

#define sdlErrCheck(_STATEMENT) if(_STATEMENT) throw(cptr_concat("SDL error:\n" #_STATEMENT "\n", SDL_GetError()))
