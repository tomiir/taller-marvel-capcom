//
// Created by magali on 16/06/19.
//

#include "View_endGame.h"

void View_endGame::updateView() {

    this->clearWindow();

    background->render();

    GameObject* winner_toRender;
    itr_winners = winners.find(winner);
    winner_toRender = itr_winners->second;
    winner_toRender->render();


    SDL_RenderPresent(renderer);
}

void View_endGame::addBackground(GameObject* background){
    this->background = background;
}

void View_endGame::addWinners(vector <GameObject*> winners){

   this->winners[winners[0]->getName()] = winners[0];
   this->winners[winners[1]->getName()] = winners[1];
   this->winners[winners[2]->getName()] = winners[2];
   this->winners[winners[3]->getName()] = winners[3];

}


bool View_endGame::end() {
    return false;
}

string View_endGame::getNextView() {
    return "final_del_juego";
}

void View_endGame::updateWinner(char *winner) {
    // falta agregar el ordnado alfabetico y convertir el char* en string
}
