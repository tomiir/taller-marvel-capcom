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


void ViewController::addController(Controller *controller) {

    controllers.push_back(controller);
}


void ViewController::handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        throw -1;
    }

    for (std::list<Controller*>::iterator controller=controllers.begin(); controller != controllers.end(); ++controller){
            //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
            (*controller)->handleEvent(event);
    }
}

void ViewController::updateView() {

    //Acá debería chequear si debe cambiar de view
    // Primero renderizo (limpio) la vista;

    this->view->render();

    // Luego renderizo los elementos que la componen



    for (std::list<Controller*>::iterator controller=controllers.begin(); controller != controllers.end(); ++controller){
        (*controller)->render();
    }
    //Actualizo los datos
    SDL_RenderPresent(renderer);

}

