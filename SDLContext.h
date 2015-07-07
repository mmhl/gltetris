//
// Created by mhl on 08.07.15.
//

#ifndef GLTETRIS_SDLCONTEXT_H
#define GLTETRIS_SDLCONTEXT_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
class SDLContext {

public:
    SDLContext() {
        SDL_Init(SDL_INIT_EVERYTHING);
    }
    ~SDLContext() {
        std::cout << "dtor sdlContext" << std::endl;
        SDL_Quit();
    }

    SDL_Window *createWindow(int pos_x, int pos_y, int width, int height, const std::string title);
    SDL_Renderer *createRenderer(SDL_Window *win, int index, uint32_t flags);
    SDL_Texture *loadTexture(const std::string &filePath, SDL_Renderer *renderer);
    void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int scale = 1);

};


#endif //GLTETRIS_SDLCONTEXT_H
