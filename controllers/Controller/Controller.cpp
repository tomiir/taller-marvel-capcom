//
// Created by trocchi on 3/28/19.
//

#include "Controller.h"

Controller::Controller(GameObject *gameObject_) {

    gameObject = gameObject_;

    //habria que asociarle algo del modelo y no de la "vista", ya que el GO es lo que lo representa en la pantalla.
    //this->mapper =  new EventToValueMapper();

}

Controller::~Controller() = default;

void Controller::render(){//SDL_Renderer* renderer){

    gameObject->render();
}

vector<int> Controller::getInfo(){

    std::vector<int> info = gameObject->getInfo();
    return info;
}

void Controller::handleEvent(SDL_Event event) {}
