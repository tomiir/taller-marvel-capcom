//
// Created by trocchi on 3/31/19.
//


#include "View.h"
//#include "../../Clases/Character.h"
//#include "../../Clases/Background.h"

using namespace std;

View::View(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

View::~View() = default;

void View::render() {
    SDL_RenderClear(renderer);
}

void View::updateView() {

}

void View::addBackground(ControllerBackground *controller) {

}

bool View::end() {
    return false;
}

string View::getNextView() {
    return std::__cxx11::string();
}

void View::updateGreySquares(char* greySquares) {

}

void View::updateSelects(char *string, char *string1) {

}

void View::updateCharacterImages(char *string, char *string1) {
}

