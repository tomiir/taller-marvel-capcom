//
// Created by trocchi on 3/28/19.
//

#include "Controller.h"

Controller::Controller(GameObject *gameObject_) {
    gameObject = gameObject_;
    //habria que asociarle algo del modelo y no de la "vista", ya que el GO es lo que lo representa en la pantalla.
    this->mapper =  new EventToValueMapper();

}

void Controller::handleEvent(SDL_Event event) {
    std::vector<int> dir = mapper->map(event);
    gameObject->move(dir);
    // habría que hacer algo para que se actualice el modelo o en fn de como se actualice el mismo (el modelo)
}

void Controller::render(){//SDL_Renderer* renderer){
    gameObject->render();
}