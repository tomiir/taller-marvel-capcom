//
// Created by trocchi on 3/31/19.
//

#include <iostream>
#include "View.h"
//#include "../../Clases/Character.h"
//#include "../../Clases/Background.h"

using namespace std;

View::View(SDL_Renderer* renderer) {
    this->renderer = renderer;

};

View::~View() = default;

void View::render() {
    SDL_RenderClear(renderer);
}

