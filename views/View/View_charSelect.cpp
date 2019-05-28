//
// Created by arielpm on 12/05/19.
//

#include "View_charSelect.h"
#include <algorithm>

View_charSelect::View_charSelect(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_): View(renderer_){

    screenWidth = screenWidth_;
    screenHeight = screenHeight_;

    int aux_y = (screenHeight - 600)/2;
    int aux_x = (screenWidth - 800)/2;

    squarePosition["CaptainAmerica"] = {233 + aux_x,291 + aux_y,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["SpiderMan"] = {400 + aux_x,291 + aux_y,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["ChunLi"] = {234 + aux_x,417 + aux_y,165,127}; // FALTA AGREGAR LAS POSICIONES
    squarePosition["Venom"] = {399 + aux_x,417 + aux_y,165,127}; // FALTA AGREGAR LAS POSICIONES

    std::vector<int> aux_1 = {497 + aux_x,0 + aux_y,303,300};// arriba a la derecha
    std::vector<int> aux_2 = {497 + aux_x,300 + aux_y,303,300};// abajo a la derecha
    std::vector<int> aux_3 = {0 + aux_x,0 + aux_y,303,300};// arriba a la izquierda
    std::vector<int> aux_4 = {0 + aux_x,300 + aux_y,303,300};// abajo a la izquierda

    posc_side_1 = {aux_1 , aux_2};
    posc_side_2 = {aux_3, aux_4};

}

void View_charSelect::addGameObject_square(GameObject_charSelect* square, int team){
    if (team == 1 ){
        square_team1 = square;
    }
    else {
        square_team2 = square;
    }
}

void View_charSelect::addGameObject_square_gray(GameObject_charSelect* square){
    greySquare[square->getName()] =  square;
}

void View_charSelect::updateView() {

    this->clearWindow();

    background->render();
    renderVector(this->getGreysSquares());
    renderVector(this->getSelectionSquares());
    renderVector(this->getSides());


    //LO PRESENTO EN EL RENDER
    SDL_RenderPresent(renderer);

}

void View_charSelect::addGameObject_background(GameObject_charSelect *background){
    this->background = background;
}

void View_charSelect:: addGameObject_character(GameObject_charSelect* gameObject, int team){
    if (team == 1 ){
        team_1[gameObject->getName()] = gameObject;
    }
    else{
        team_2[gameObject->getName()] = gameObject;
    }
}

void View_charSelect:: addGameObject_character_selected(GameObject_charSelect* gameObject, int team){
    if (team == 1 ){
        team_1_selected[gameObject->getName()] = gameObject;
    }
    else{
        team_2_selected[gameObject->getName()] = gameObject;
    }
}


bool View_charSelect:: end(){
    return selected.size() == 4;

}

View_charSelect::~View_charSelect() {

}

string View_charSelect::getNextView() {
    return "fight";
}

std::vector<GameObject_charSelect *> View_charSelect::getSides() {

    // LOGICA DE LATERALES. to_render es un vector que tiene los laterales a renderizar.
    std::vector<GameObject_charSelect *> to_render;

    if (selected_1.empty()) {
        itr_team_1 = team_1.find((preselectedT1));
        (itr_team_1->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1->second);
    }

    if (selected_2.empty()) {
        itr_team_2 = team_2.find((preselectedT2));
        vector<int> posc_prueba = posc_side_2[0];
        (itr_team_2->second)->setPosc(posc_prueba);
        to_render.push_back(itr_team_2->second);
    }

    if (selected_1.size() == 1) {
        itr_team_1_selected = team_1_selected.find(selected_1[0]);
        (itr_team_1_selected->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1_selected->second);

        itr_team_1 = team_1.find(preselectedT1);
        (itr_team_1->second)->setPosc(posc_side_1[1]);
        to_render.push_back(itr_team_1->second);
    }

    if (selected_2.size() == 1) {
        itr_team_2_selected = team_2_selected.find(selected_2[0]);
        (itr_team_2_selected->second)->setPosc(posc_side_2[0]);
        to_render.push_back(itr_team_2_selected->second);

        itr_team_2 = team_2.find(preselectedT2);
        (itr_team_2->second)->setPosc(posc_side_2[1]);
        to_render.push_back(itr_team_2->second);

    }

    if (selected_1.size() == 2) {

        itr_team_1_selected = team_1_selected.find(selected_1[0]);
        (itr_team_1_selected->second)->setPosc(posc_side_1[0]);
        to_render.push_back(itr_team_1_selected->second);

        itr_team_1_selected = team_1_selected.find(selected_1[1]);
        (itr_team_1_selected->second)->setPosc(posc_side_1[1]);
        to_render.push_back(itr_team_1_selected->second);
    }

    if (selected_2.size() == 2) {
        itr_team_2_selected = team_2_selected.find(selected_2[0]);
        (itr_team_2_selected->second)->setPosc(posc_side_2[0]);
        to_render.push_back(itr_team_2_selected->second);

        itr_team_2_selected = team_2_selected.find(selected_2[1]);
        (itr_team_2_selected->second)->setPosc(posc_side_2[1]);
        to_render.push_back(itr_team_2_selected->second);

    }
    return to_render;
}

std::vector<GameObject_charSelect *> View_charSelect::getGreysSquares() {

    std::vector<GameObject_charSelect *> to_render;

    std::vector<string>::iterator itr_selected = selected.begin();

    for (itr_selected; itr_selected != selected.end(); ++itr_selected){
        itr_greySquare= greySquare.find(*itr_selected);
        to_render.push_back(itr_greySquare->second);
    }
    return to_render;
}

std::vector<GameObject_charSelect *> View_charSelect::getSelectionSquares() {

    std::vector<GameObject_charSelect*> to_render;

    itr_squarePosition = squarePosition.find(preselectedT1);
    square_team1->setPosc((itr_squarePosition->second));

    to_render.push_back(square_team1);

    itr_squarePosition = squarePosition.find(preselectedT2);
    square_team2->setPosc((itr_squarePosition->second));

    to_render.push_back(square_team2);

    return to_render;
}

void View_charSelect::renderVector(std::vector<GameObject_charSelect*> to_render) {

    std::vector<GameObject_charSelect*>::iterator itr_to_render = to_render.begin();

    for (itr_to_render; itr_to_render != to_render.end(); ++itr_to_render){
        (*itr_to_render)->render();
    }
}

std::vector<string> View_charSelect::getTeam1() {
    return selected_1;
}

std::vector<string> View_charSelect::getTeam2() {
    return selected_2;
}

bool View_charSelect::selectedNotContains(string name){

    std::vector<string>::iterator itr_selected = selected.begin();

    for (itr_selected; itr_selected != selected.end(); ++itr_selected){

        if (*itr_selected == name) return false;
    }
    return true;
}

void View_charSelect::updateGreySquares(char* greySquares ) {

    if (greySquares[0] == '1' and selectedNotContains("CaptainAmerica")) selected.push_back("CaptainAmerica");
    if (greySquares[1] == '1' and selectedNotContains("SpiderMan")) selected.push_back("SpiderMan");
    if (greySquares[2] == '1' and selectedNotContains("ChunLi")) selected.push_back("ChunLi");
    if (greySquares[3] == '1' and selectedNotContains("Venom")) selected.push_back("Venom");


}

void View_charSelect::updateSelects(char *selectT1, char *selectT2) {

    if (strcmp(selectT1, "00") == 0){
        preselectedT1 = "CaptainAmerica";
    } else if(strcmp(selectT1, "01") == 0){
        preselectedT1 = "SpiderMan";
    } else if(strcmp(selectT1, "10") == 0) {
        preselectedT1 = "ChunLi";
    } else preselectedT1 = "Venom";

    if (strcmp(selectT2, "00") == 0){
        preselectedT2 = "CaptainAmerica";
    } else if(strcmp(selectT2, "01") == 0){
        preselectedT2 = "SpiderMan";
    } else if(strcmp(selectT2, "10") == 0) {
        preselectedT2 = "ChunLi";
    } else preselectedT2 = "Venom";
}

void View_charSelect::updateCharacterImages(char *selected_1_, char *selected_2_) {

    if (strcmp(selected_1_, "100") == 0){
        this->selected_1.push_back("CaptainAmerica");
    } else if (strcmp(selected_1_, "101") == 0){
        this->selected_1.push_back("SpiderMan");
    } else if (strcmp(selected_1_, "110") == 0){
        this->selected_1.push_back("ChunLi");
    } else if (strcmp(selected_1_, "111") == 0) {
        this->selected_1.push_back("Venom");
    }

    if (strcmp(selected_2_, "100") == 0){
        this->selected_2.push_back("CaptainAmerica");
    } else if (strcmp(selected_2_, "101") == 0){
        this->selected_2.push_back("SpiderMan");
    } else if (strcmp(selected_2_, "110") == 0){
        this->selected_2.push_back("ChunLi");
    } else if (strcmp(selected_2_, "111") == 0){
        this->selected_2.push_back("Venom");
    }


}

