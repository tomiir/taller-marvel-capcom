//
// Created by trocchi on 3/31/19.
//


#include "View.h"

using namespace std;

View::View(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

View::~View() = default;

void View::clearWindow() {
    SDL_RenderClear(renderer);
}

void View::updateView() {

}

bool View::end() {
    return false;
}

string View::getNextView() {
    return std::__cxx11::string();
}


