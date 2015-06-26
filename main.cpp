#include <iostream>
#include <SDL2/SDL.h>
int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "SDL initialized" << std::endl;
    SDL_Quit();
    return 0;
}