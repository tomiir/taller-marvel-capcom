//
// Created by trocchi on 3/31/19.
//

#include "ViewController.h"
#include <SDL2/SDL.h>

ViewController::ViewController(SDL_Renderer* renderer_) {

    this->renderer= renderer_;
    this->view = new View(renderer_);
    this->team1 = NULL;
    this->team2 = NULL;

    // ¿HAY QUE INICIALIZAR LA LISTA?
    //this->controllers = new std::list<Controller*>();
}

ViewController::~ViewController() = default;


void ViewController::addTeamsManager(TeamManager* team1, TeamManager* team2){
    this->team1 = team1;
    this->team2 = team2;

}

void ViewController::handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        throw -1;
    }

    team1->handleEvent(event);
    team2->handleEvent(event);
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();

    // Luego renderizo los elementos que la componen

    team1->render();
    team2->render();



    //Actualizo los datos
    SDL_RenderPresent(renderer);

}



