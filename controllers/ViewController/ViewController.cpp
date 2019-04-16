//
// Created by trocchi on 3/31/19.
//

#include "ViewController.h"

#include <SDL2/SDL.h>

#include "../../utils/Logger/Logger.h"

ViewController::ViewController(SDL_Renderer* renderer_) {

    this->renderer= renderer_;
    this->view = new View(renderer_);
}

ViewController::~ViewController() = default;


void ViewController::addBackground(ControllerBackground* controller) {

    backgrounds.push_back(controller);
}


void ViewController::handleEvent() {

    CLogger* logger = CLogger::GetLogger();

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        logger -> Log("Saliendo del juego", INFO, "");
        throw -1;
    }
// MODIFICAR EL HANDLEEVENT!
    try {
        if(event.key.state != SDL_RELEASED) {
            logger -> Log("Manejando el evento: " + to_string(event.type), DEBUG, "");
        }
        team1->handleEvent(event, backgrounds);
        team2->handleEvent(event, backgrounds);
        flipManager->update();
    } catch(exception e) {
        logger -> Log("Falló al querer manejar un evento", ERROR, e.what());
        logger -> Log("Falló al querer manejar el evento: " + to_string(event.type), DEBUG, e.what());
        throw -1;
    }
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();

    // Luego renderizo los elementos que la componen

    for (std::vector<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {
        //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
        (*controllerBackground)->render();
    }

    team1->render();
    team2->render();
    SDL_RenderPresent(renderer);

}

void ViewController::addTeams(TeamManager* teamManager1, TeamManager* teamManager2) {

    team1 = teamManager1;
    team2 = teamManager2;
}

void ViewController::addFlipManager(FlipManager *flipManager_) {

    flipManager = flipManager_;

}

