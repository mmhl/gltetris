//
// Created by mhl on 08.07.15.
//

#include "SDLContext.h"


SDL_Window *SDLContext::createWindow(int pos_x, int pos_y, int width, int height, const std::string title) {
    return SDL_CreateWindow(title.c_str(), pos_x, pos_y, width, height, SDL_WINDOW_SHOWN);
}

SDL_Renderer *SDLContext::createRenderer(SDL_Window *win, int index, uint32_t flags) {
    return SDL_CreateRenderer(win, index, flags);
}

SDL_Texture *SDLContext::loadTexture(const std::string &filePath, SDL_Renderer *renderer) {
    SDL_Texture *texture = nullptr;
    SDL_Surface *surf = SDL_LoadBMP(filePath.c_str());
    if(surf != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, surf);
        SDL_FreeSurface(surf);
        if(texture == nullptr) {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
    return texture;
}

void SDLContext::renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int scale) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = dst.x / scale;
    dst.y = dst.y / scale;
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}
