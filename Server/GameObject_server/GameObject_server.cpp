//
// Created by arielpm on 16/05/19.
//

#include "GameObject_server.h"

GameObject_server::GameObject_server(string name_, int initialX, int initialY, int width, int height) {

    name = name_;
    objRect = SDL_Rect{initialX, initialY, width, height};
}

GameObject_server::~GameObject_server() = default;

void GameObject_server::move(DirectionVector* direction){}

vector<int> GameObject_server::getInfo() {}

void GameObject_server::stayInFloor() {}

string GameObject_server::getName() {
    return name;
}

vector<int> GameObject_server::getPosInfo() {
}
