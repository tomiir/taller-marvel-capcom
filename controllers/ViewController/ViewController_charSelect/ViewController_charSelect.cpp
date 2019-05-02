//
// Created by magali on 01/05/19.
//

#include "ViewController_charSelect.h"
#include <algorithm>

ViewController_charSelect::ViewController_charSelect(SDL_Renderer *renderer_): ViewController(renderer_){
    squarePosition["cap_america"] = {1,1,1,1}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["spider_man"] = {1,1,1,1}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["chun_li"] = {1,1,1,1}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["venom"] = {1,1,1,1}; // FALTA AGREGAR LAS POSICIONES

    std::vector<int> aux_1 = {1,1,1,1};
    std::vector<int> aux_2 = {1,1,1,1};
    std::vector<int> aux_3 = {1,1,1,1};
    std::vector<int> aux_4 = {1,1,1,1};


    posc_side_1 = {aux_1 , aux_2};
    posc_side_2 = {aux_3, aux_4};
}

void ViewController_charSelect::addGameObject_square(GameObject_charSelect* square, int team){
    if (team == 1 ){
       square_team1 = square;
    }
    else{
        square_team2= square;
    }
}

void ViewController_charSelect::updateView(){
    this->view->render();
    background->render();


    std::vector<string>::iterator itr = selected_1.begin();

    int aux = 0;

    for (itr ; itr != selected_1.end(); ++itr) {
        itr_team_1 = team_1.find((*itr));
        (itr_team_1 -> second) ->setPosc(posc_side_1[aux]);
        (itr_team_1 -> second) -> render();
        aux ++;
    }

    aux = 0;

    std::vector<string>::iterator itr_2 = selected_2.begin();

    for (itr_2; itr_2 != selected_1.end(); ++itr_2) {
        itr_team_2 = team_2.find((*itr_2));
        (itr_team_2 -> second) ->setPosc(posc_side_2[aux]);
        (itr_team_2 -> second) -> render();

    }

    itr_squarePosition = squarePosition.find(mapper_1->getPreselected());
    square_team1 ->setPosc((itr_squarePosition->second));
    square_team1->render();

    itr_squarePosition = squarePosition.find(mapper_2->getPreselected());
    square_team2 ->setPosc((itr_squarePosition->second));
    square_team2->render();

    SDL_RenderPresent(renderer);

}

void ViewController_charSelect::addGameObject_background(GameObject_charSelect *background){
    this->background = background;
}

void ViewController_charSelect:: addGameObject_character(GameObject_charSelect* gameObject, int team){
    if (team == 1 ){
        team_1[gameObject->getName()] = gameObject;
    }
    else{
        team_2[gameObject->getName()] = gameObject;
    }
}


void ViewController_charSelect:: handleEvent(){

    SDL_Event event;
    SDL_PollEvent(&event);
    string respuesta_1 = mapper_1->map(event);
    if (strcmp(respuesta_1.c_str(),"no_selecciono") != 0 ) setTeam1(respuesta_1);
    string respuesta_2 = mapper_2->map(event);
    if (strcmp(respuesta_2.c_str(),"no_selecciono") != 0 ) setTeam1(respuesta_2);

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

