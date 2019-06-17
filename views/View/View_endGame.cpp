//
// Created by magali on 16/06/19.
//

#include "View_endGame.h"

View_endGame::View_endGame(SDL_Renderer *renderer_) : View(renderer_){}

void View_endGame::updateView() {

    this->clearWindow();

    background->render();

    GameObject* winner_toRender;
    itr_winners = winners.find(winner_string);
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
   this->winners[winners[4]->getName()] = winners[4];
   this->winners[winners[5]->getName()] = winners[5];

}


bool View_endGame::end() {
    return false;
}

string View_endGame::getNextView() {
    return "final_del_juego";
}

void View_endGame::updateWinners(char *winner) {
    // falta agregar el ordenado alfabetico y convertir el char* en string
    winner_string = winner;
    if(winner[0]>winner[1]){
        char aux = winner[0];
        winner[0] = winner[1];
        winner[1] = aux;
        winner_string = winner;
    }
}

void View_endGame::renderDisconnected() {

    disconnected->render();
    SDL_RenderPresent(renderer);
}

void View_endGame::addGameObject_disconnected(GameObject *disconnected_) {
    disconnected = disconnected_;
}
