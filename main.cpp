#include <iostream>
#include <SDL2/SDL.h>
#include "util.h"


int main(int argc, char *argv[]) {
    SDL_Context sdl;
    SDL_Window *mainWindow = sdl.createWindow(100,100,1024,768, "Hello SDL");
    SDL_Renderer *renderer = sdl.createRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr)
    	return -1;
    SDL_Texture *texture = sdl.loadTexture("assets/marbles.bmp", renderer);
    if(texture == nullptr) {
    	return -1;
    }
    sdl.renderTexture(renderer, texture, 10, 60, 10);

    for(int i = 0; i < 3; ++i) {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    SDL_cleanup(texture);
    SDL_cleanup(renderer);
    SDL_cleanup(mainWindow);
    SDL_Quit();
    return 0;
}