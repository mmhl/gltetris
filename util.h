#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include <iostream>
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


class SDL_Context {
public:
	SDL_Context() {
		SDL_Init(SDL_INIT_EVERYTHING);
	}
	~SDL_Context() {

	}
	SDL_Window *createWindow(int pos_x, int pos_y, int width, int height, const std::string title) {
		return SDL_CreateWindow(title.c_str(), pos_x, pos_y, width, height, SDL_WINDOW_SHOWN);	
	}
	SDL_Renderer *createRenderer(SDL_Window *win, int index, uint32_t flags) {
		return SDL_CreateRenderer(win, index, flags);
	}
	SDL_Texture *loadTexture(const std::string &filePath, SDL_Renderer *renderer) {
		SDL_Texture *texture = nullptr;	
		SDL_Surface *surf = SDL_LoadBMP(filePath.c_str());
		if(surf != nullptr) {
			texture = SDL_CreateTextureFromSurface(renderer, surf);	
			SDL_FreeSurface(surf);
			if(texture == nullptr) {
				std::cerr << "Error while loading a texture" << std::endl;
				return nullptr;
			}
		}
		else {
			std::cerr << "cannot load surface: " << filePath << std::endl;
			return nullptr;
		}
		std::cout << "loaded texture: " << filePath << " " << texture << std::endl;
		return texture;
	}
	void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int scale = 1) {
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
		dst.x = dst.x / scale;
		dst.y = dst.y / scale;
		SDL_RenderCopy(renderer, texture, NULL, &dst);
	}
	SDL_Context& operator=(SDL_Context& other) = delete;
	SDL_Context(SDL_Context &other) = delete;	
};


#endif