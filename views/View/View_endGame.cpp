//
// Created by magali on 16/06/19.
//

#include "View_endGame.h"

View_endGame::View_endGame(SDL_Renderer *renderer_) : View(renderer_){}

void View_endGame::updateView() {

    this->clearWindow();
    vector<int> position;
    background->render();
    sourcePosition_itr= sourcePosition.find(winner_string);
    position = sourcePosition_itr->second;

    winnerTeam->setOriginRect(position);
    GameObject* winner_toRender;

    winner_toRender->render();


    SDL_RenderPresent(renderer);
}

void View_endGame::addBackground(GameObject* background){
    this->background = background;
}

void View_endGame::addWinner(GameObject* winnerTeam){
   this->winnerTeam  = winnerTeam;
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

void View_endGame::addSourcePositions(map<string, vector<int>> sourcePosition) {
    this->sourcePosition = sourcePosition;
}
