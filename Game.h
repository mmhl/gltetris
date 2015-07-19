//
// Created by mhl on 19.07.15.
//

#ifndef GLTETRIS_GAME_H
#define GLTETRIS_GAME_H

#include <string>
#include "SDLContext.h"

class Game {
public:
    Game() : running(false) {

    }

    void init(const std::string &title);
    void mainLoop();
    void cleanup();

    Game& Game(const Game& other) = delete;
    Game& Game(Game& other) = delete;
    Game& operator=(Game& other) = delete;
private:
    bool running;
    SDLContext sdlContext;
};


#endif //GLTETRIS_GAME_H
