//
// Created by magali on 01/05/19.
//

#include "ViewController.h"

#include <algorithm> // for heap operations
#include <SDL2/SDL.h>
#include "../../utils/Logger/Logger.h"
#include "../../views/View/View.h"

ViewController::ViewController () {
}

ViewController::~ViewController() {

}

void ViewController::handleEvent(string event) {

}

bool ViewController::end() {
    return false;
}

string ViewController::getNextView() {
    return std::__cxx11::string();
}

string ViewController::giveNewParameters() {
    return std::__cxx11::string();
}




