#!/bin/bash

# compiling kerep
cd kerep
make $KEREP_BUILD_TASK
cp bin/kerep.a ../obj/
printf "${GREEN}copied ${CYAN}kerep.a\n"
cd ..

# copying SDL
cp deps/$OS-$ARCH/$SDL_LIB_NAME $OUTDIR/$SDL_LIB_NAME
