//
// Created by mhl on 19.07.15.
//

#ifndef GLTETRIS_GAME_H
#define GLTETRIS_GAME_H

#include <string>
#include "SDLContext.h"

class Game {
public:
    Game() : m_running(false), m_sdlWindow(nullptr), m_sdlRenderer(nullptr) {

    }

    bool init(const std::string &title);
    void mainLoop();
    void cleanup();
    void render();

    Game& Game(const Game& other) = delete;
    Game& Game(Game& other) = delete;
    Game& operator=(Game& other) = delete;
private:
    bool m_running;
    SDLContext m_sdlContext;
    SDL_Window *m_sdlWindow;
    SDL_Renderer *m_sdlRenderer;
};


#endif //GLTETRIS_GAME_H
