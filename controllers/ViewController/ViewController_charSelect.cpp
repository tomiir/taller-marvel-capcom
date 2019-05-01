//
// Created by magali on 01/05/19.
//

#include "ViewController_charSelect.h"

ViewController_charSelect::ViewController_charSelect(SDL_Renderer *renderer_): ViewController(renderer_){

}


void ViewController_charSelect::updateView(){

}

void ViewController_charSelect:: handleEvent(){

    SDL_Event event;
    SDL_PollEvent(&event);
    mapper_1->map(event, this);
    mapper_2->map(event, this);
}

void ViewController_charSelect::setTeam1(string character){
    if (selected.size() == 0) {
        selected_1.push_back(character);
    }
    bool val = false;
    for (int i = 0; i < selected.size(); i++){
        if (selected[i] == character) val = true;
    }
    if(!val) {
        selected.push_back(character);
        selected_1.push_back(character);
    }
}

void ViewController_charSelect::setTeam2(string character) {
    if (selected.size() == 0) {
        selected_2.push_back(character);
    }
    bool val = false;
    for (int i = 0; i < selected.size(); i++) {
        if (selected[i] == character) val = true;
    }
    if (!val) {
        selected_2.push_back(character);
        selected.push_back(character);
    }
}

void ViewController_charSelect::addBackground(ControllerBackground* controller){
    backgrounds.push_back(controller);
}

