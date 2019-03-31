//
// Created by trocchi on 3/31/19.
//

#include "ViewController.h"
#include <SDL2/SDL.h>

ViewController::ViewController(char *viewId, SDL_Renderer* renderer) {
    this->view = new View(viewId, renderer);
}

void ViewController::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        throw -1;
    }
    if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        this->view->handleEvent(event);
    }
}

void ViewController::updateView() {
    //Acá debería chequear si debe cambiar de view
    this->view->render();
}