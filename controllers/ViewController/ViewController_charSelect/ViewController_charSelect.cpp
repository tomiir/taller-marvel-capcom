//
// Created by magali on 01/05/19.
//

#include "ViewController_charSelect.h"
#include <algorithm>

ViewController_charSelect::ViewController_charSelect(SDL_Renderer *renderer_): ViewController(renderer_){

    squarePosition["cap_america"] = {233,291,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["spider_man"] = {400,291,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["chun_li"] = {234,417,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["venom"] = {399,417,165,127}; // FALTA AGREGAR LAS POSICIONES

    std::vector<int> aux_1 = {497,0,303,300};// arriba a la derecha
    std::vector<int> aux_2 = {497,300,303,300};// abajo a la derecha
    std::vector<int> aux_3 = {0,0,303,300};// arriba a la izquierda
    std::vector<int> aux_4 = {0,300,303,300};// abajo a la izquierda

    mapper_1 = new  EventToValueMapper_charSelect_1() ;
    mapper_2 = new  EventToValueMapper_charSelect_2() ;

    posc_side_1 = {aux_1 , aux_2};
    posc_side_2 = {aux_3, aux_4};
}

void ViewController_charSelect::addGameObject_square(GameObject_charSelect* square, int team){
    if (team == 1 ){
       square_team1 = square;
    }
    else {
        square_team2 = square;
    }
}

void ViewController_charSelect::addGameObject_square_gray(GameObject_charSelect* square){
    greySquare[square->getName()] =  square;
}

void ViewController_charSelect::updateView() {
    this->view->render();


    //std::vector<string>::iterator itr = selected_1.begin();


    // MODIFICAR ESTA LOGICA DE LATERALES
    std::vector<GameObject_charSelect *> to_render;

    if (selected_1.size() == 0) {
        itr_team_1 = team_1.find((mapper_1->getPreselected()));
        (itr_team_1->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1->second);
    }

    if (selected_2.size() == 0) {
        itr_team_2 = team_2.find((mapper_2->getPreselected()));
        (itr_team_2->second)->setPosc(posc_side_2[0]);
        to_render.push_back(itr_team_2->second);
    }

    if (selected_1.size() == 1) {
        itr_team_1 = team_1.find(selected_1[0]);
        (itr_team_1->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1->second);

        itr_team_1 = team_1.find(mapper_1->getPreselected());
        (itr_team_1->second)->setPosc(posc_side_1[1]);
        to_render.push_back(itr_team_1->second);
    }

    if (selected_2.size() == 1) {
        itr_team_2 = team_2.find(selected_2[0]);
        (itr_team_2->second)->setPosc(posc_side_2[0]);
        to_render.push_back(itr_team_2->second);

        itr_team_2 = team_2.find(mapper_2->getPreselected());
        (itr_team_2->second)->setPosc(posc_side_2[1]);
        to_render.push_back(itr_team_2->second);

    }

    if (selected_1.size() == 2) {
        itr_team_1 = team_1.find(selected_1[0]);
        (itr_team_1->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1->second);

        itr_team_1 = team_1.find(selected_1[1]);
        (itr_team_1->second)->setPosc(posc_side_1[1]);
        to_render.push_back(itr_team_1->second);
    }

    if (selected_2.size() == 2) {
        itr_team_2 = team_2.find(selected_2[0]);
        (itr_team_2->second)->setPosc(posc_side_2[0]);
        to_render.push_back(itr_team_2->second);

        itr_team_2 = team_2.find(selected_2[1]);
        (itr_team_2->second)->setPosc(posc_side_2[1]);
        to_render.push_back(itr_team_2->second);

    }

    std::vector<GameObject_charSelect *> to_render_2;

    std::vector<string>::iterator itr_selected = selected.begin();

    for (itr_selected; itr_selected != selected.end(); ++itr_selected){
        itr_greySquare= greySquare.find(*itr_selected);
        to_render_2.push_back(itr_greySquare->second);
    }

    //LÓGICA DE LATERALES

    itr_squarePosition = squarePosition.find(mapper_1->getPreselected());
    square_team1->setPosc((itr_squarePosition->second));


    itr_squarePosition = squarePosition.find(mapper_2->getPreselected());
    square_team2->setPosc((itr_squarePosition->second));


    background->render();

    std::vector<GameObject_charSelect*>::iterator itr_to_render = to_render.begin();

    for (itr_to_render; itr_to_render != to_render.end(); ++itr_to_render){
        (*itr_to_render)->render();
    }

    std::vector<GameObject_charSelect*>::iterator itr_to_render_2 = to_render_2.begin();

    for (itr_to_render_2; itr_to_render_2 != to_render_2.end(); ++itr_to_render_2){
        (*itr_to_render_2)->render();
    }

    square_team1->render();
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


void ViewController_charSelect:: handleEvent() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (selected_1.size() < 2) {
        string respuesta_1 = mapper_1->map(event);
        if (strcmp(respuesta_1.c_str(), "no_selecciono") != 0) setTeam1(respuesta_1);
    }

    if (selected_1.size() < 2) {
    string respuesta_2 = mapper_2->map(event);
    if (strcmp(respuesta_2.c_str(), "no_selecciono") != 0) setTeam2(respuesta_2);
    }
}

void ViewController_charSelect::setTeam1(string character){

    bool posible = true;

    std::vector<string>::iterator itr = selected.begin();

    for (itr; itr != selected.end(); ++itr){
        if (strcmp((*itr).c_str(),(character).c_str()) == 0){
            posible = false;
        }
    }

    if(posible) {
        selected.push_back(character);
        selected_1.push_back(character);
    }
}

void ViewController_charSelect::setTeam2(string character) {
    bool posible = true;

    std::vector<string>::iterator itr = selected.begin();

    for (itr; itr != selected.end(); ++itr){
        if (strcmp((*itr).c_str(),(character).c_str()) == 0){
            posible = false;
        }
    }

    if(posible) {
        selected.push_back(character);
        selected_2.push_back(character);
    }

}


void ViewController_charSelect::addBackground(ControllerBackground* controller){

    // ESTE LO DEFINO POR HERENCIA PERO NO LO USA
    backgrounds.push_back(controller);
}


bool ViewController_charSelect:: end(){
    return selected.size() == 4;

}

ViewController_charSelect::~ViewController_charSelect() {

}

string ViewController_charSelect::getNextView() {
    return "fight";
}

