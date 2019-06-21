//
// Created by magali on 16/06/19.
//

#include "ViewController_endGame.h"



void ViewController_endGame::handleEvent(string event) {
    // no creo que haya nada que handlear
    return;
}

bool ViewController_endGame::end() {
    // no creo que termine nunca
    return false;
}

string ViewController_endGame::getNextView() {
    return nullptr;
}

string ViewController_endGame::giveNewParameters() {

    string updates = "020000000000000000000000000000000000000000000000000000000";

    /*
     * a = captain America
     * c = chunLi
     * v = venom
     * s = spiderman
     */
    updates[2] = winner_1;
    updates[3] = winner_2;


    return updates;
}

void ViewController_endGame::setWinners(char winner_1, char winner_2) {
    this->winner_1 = winner_1;
    this->winner_2 = winner_2;
}
