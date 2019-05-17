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

void View::updateBackgrounds(char *posFloor_x, char *posFloor_y, char *posMoon_x, char *posMoon_y, char *posGalaxy_x,
                             char *posGalaxy_y) {

}

void View::updateCharacters(char *posT1_x, char *posT1_y, char stateT1, char flip1, char currentCharT1, char *posT2_x, char *posT2_y,
                            char stateT2, char flip2, char currentCharT2) {

}

vector<string> View::getTeam1() {
    return vector<string>();
}

vector<string> View::getTeam2() {
    return vector<string>();
}

