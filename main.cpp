#include <iostream>
#include <SDL2/SDL.h>
#include "util.h"
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *mainWindow = SDL_CreateWindow("Hello World", 100, 100, 640,480, SDL_WINDOW_SHOWN);
    if(mainWindow == nullptr) {
        std::cerr << "Error while creating SDL window"  << std::endl;
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr) {
        std::cerr << "Failed to create sdl renederer" << std::endl;
        SDL_DestroyWindow(mainWindow);
        SDL_Quit();
        return -1;
    }

    std::string helloWorldResource = "assets/hello.bmp";
    SDL_Surface *helloBmp = SDL_LoadBMP(helloWorldResource.c_str());
    if(helloBmp == nullptr) {
        std::cerr << "Unable to load BMP " << helloWorldResource << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, helloBmp);
    SDL_FreeSurface(helloBmp);

    for(int i = 0; i < 3; ++i) {
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, texture, nullptr, nullptr);
        SDL_RenderPresent(ren);
        SDL_Delay(1000);
    }

    SDL_cleanup(texture);
    SDL_cleanup(ren);
    SDL_cleanup(mainWindow);
    SDL_Quit();
    return 0;
}