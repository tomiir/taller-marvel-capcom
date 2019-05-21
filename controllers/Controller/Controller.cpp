//
// Created by trocchi on 3/28/19.
//

#include "Controller.h"


Controller::Controller(GameObject_server *gameObject_, int jumpSpeed){

    gameObject = gameObject_;
    this->jumpSpeed = jumpSpeed;

    //habria que asociarle algo del modelo y no de la "vista", ya que el GO es lo que lo representa en la pantalla.

}


Controller::~Controller() = default;

vector<int> Controller::getInfo(){

    vector<int> info = gameObject->getInfo();
    return info;
}

void Controller::handleEvent(string event) {}

void Controller::writeLog(string content) {
}

string Controller::getName() {
    return gameObject->getName();
}
