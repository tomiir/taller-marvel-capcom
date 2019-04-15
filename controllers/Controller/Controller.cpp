//
// Created by trocchi on 3/28/19.
//

#include "Controller.h"


Controller::Controller(GameObject *gameObject_, int z_index ): Renderable() {

    gameObject = gameObject_;
    this->z_index = z_index;

    //habria que asociarle algo del modelo y no de la "vista", ya que el GO es lo que lo representa en la pantalla.

}


Controller::~Controller() = default;

int Controller::getZIndex(){
    return z_index;
}

void Controller::render(){ //en vez de render tendria que ser "draw"

    gameObject->render();
}

vector<int> Controller::getInfo(){

    vector<int> info = gameObject->getInfo();
    return info;
}

void Controller::handleEvent(SDL_Event event) {}

void Controller::writeLog(string content) {
}
