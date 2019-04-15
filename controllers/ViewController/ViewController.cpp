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


void ViewController::handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        throw -1;
    }
// MODIFICAR EL HANDLEEVENT!

    team1->handleEvent(event, backgrounds);
    team2->handleEvent(event, backgrounds);
    flipManager->update();
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();
    std::vector<Renderable*> renderables;

    // Luego renderizo los elementos que la componen

    for (std::vector<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {
        //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
        renderables.push_back((*controllerBackground));
    }

    renderables.push_back(team1);
    renderables.push_back(team2);


    SDL_RenderPresent(renderer);

}

void ViewController::addTeams(TeamManager* teamManager1, TeamManager* teamManager2) {

    team1 = teamManager1;
    team2 = teamManager2;
}

void ViewController::addFlipManager(FlipManager *flipManager_) {

    flipManager = flipManager_;

}

