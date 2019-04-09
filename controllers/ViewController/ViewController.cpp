//
// Created by trocchi on 3/31/19.
//

#include "ViewController.h"
#include <SDL2/SDL.h>

ViewController::ViewController(SDL_Renderer* renderer_) {

    this->renderer= renderer_;
    this->view = new View(renderer_);
}

ViewController::~ViewController() = default;


void ViewController::addBackground(ControllerBackground* controller) {

    backgrounds.push_back(controller);
}

void ViewController::addTeamManager(TeamManager* teamManager) {
    teams.push_back(teamManager);
}


void ViewController::handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        throw -1;
    }
// MODIFICAR EL HANDLEEVENT!
    for (std::list<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground){
            //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
            (*controllerBackground)->handleEvent(event);
    }

    for (std::list<TeamManager*>::iterator team = teams.begin(); team != teams.end(); ++team){
        (*team)->handleEvent(event);
    }
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();

    // Luego renderizo los elementos que la componen

    for (std::list<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {
        //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
        (*controllerBackground)->render();
    }

    for (std::list<TeamManager*>::iterator team = teams.begin(); team != teams.end(); ++team) {
        (*team)->render();
    }
    //Actualizo los datos
    SDL_RenderPresent(renderer);

}

