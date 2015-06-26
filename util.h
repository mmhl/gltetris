#ifndef __UTIL_H__
#define __UTIL_H__

#include <SDL2/SDL.h>

template<typename T>
void SDL_cleanup(T *t) {
    cleanup(t);
}

/*
 * Template specialization for SDL structures
 */

template<>
void SDL_cleanup<SDL_Window>(SDL_Window *win) {
    if(win)
        SDL_DestroyWindow(win);
}

template<>
void SDL_cleanup<SDL_Renderer>(SDL_Renderer *renderer) {
    if(renderer)
        SDL_DestroyRenderer(renderer);
}

template<>
void SDL_cleanup<SDL_Texture>(SDL_Texture *tex) {
    if(tex) {
        SDL_DestroyTexture(tex);
    }
}

template<>
void SDL_cleanup<SDL_Surface>(SDL_Surface *surf) {
    if(surf) {
        SDL_FreeSurface(surf);
    }
}
#endif