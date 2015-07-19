//
// Created by mhl on 19.07.15.
//

#include "Game.h"
#include <iostream>


bool Game::init(const std::string &title) {

    m_sdlWindow = m_sdlContext.createWindow(100, 100, 800, 600, title); // TODO: add parameters to init
    if(m_sdlWindow == nullptr) {
        std::cerr << "Error, can't create sdl window" << std::endl;
        return false;
    }

    m_sdlRenderer = m_sdlContext.createRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(m_sdlRenderer == nullptr) {
        std::cerr << "Error, can't create renderer in window " << m_sdlWindow << std::endl;
        return false;
    }
    m_running = true;
    return true;
}

void Game::mainLoop() {

}

void Game::cleanup() {

}

void Game::render() {

}
