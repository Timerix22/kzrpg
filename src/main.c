#include <GL/gl.h>
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include "../kerep/src/base/base.h"

#define sdlErrCheck(_STATEMENT) if(_STATEMENT) throw(cptr_concat("SDL error:\n" #_STATEMENT "\n", SDL_GetError()))

int main(){
    setlocale(LC_ALL, "en-US.Unicode");
    printf("hello!\n");
    ktDescriptors_beginInit();
    ktDescriptors_initKerepTypes();
    ktDescriptors_endInit();
    ktDescriptor desc=ktDescriptor_get(ktId_Bool);
    printf("name: %s id: %u size: %u\n", desc.name, desc.id, desc.size);
    sdlErrCheck(SDL_Init(SDL_INIT_VIDEO)!=0);
    SDL_Window* win=SDL_CreateWindow("UwU",50,50,666,228, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    sdlErrCheck(win==NULL);
    getc(stdin);
    return 0;
}
