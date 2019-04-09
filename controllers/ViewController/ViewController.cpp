//
// Created by trocchi on 3/31/19.
//

#include "ViewController.h"
#include <SDL2/SDL.h>

ViewController::ViewController(SDL_Renderer* renderer_) {

    this->renderer= renderer_;
    this->view = new View(renderer_);

    // ¿HAY QUE INICIALIZAR LA LISTA?
    //this->controllers = new std::list<Controller*>();
}

ViewController::~ViewController() = default;


void ViewController::addControllerCharacter(ControllerCharacter *controllerCharacter) {

    controllersCharacter.push_back(controllerCharacter);
}


void ViewController::handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        throw -1;
    }

    for (itr; itr != controllersCharacter.end(); ++itr){
            //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
            (*itr)->handleEvent(event);
    }
    itr = controllersCharacter.begin();
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();

    // Luego renderizo los elementos que la componen


    for (itr; itr != controllersCharacter.end(); ++itr){
        (*itr)->render();
    }
    itr = controllersCharacter.begin();



    //Actualizo los datos
    SDL_RenderPresent(renderer);

}

BackgroundsController *ViewController::addBackgroundsController(BackgroundsController *backgroundsController) {
    return nullptr;
}


