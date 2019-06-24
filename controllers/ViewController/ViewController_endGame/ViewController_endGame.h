//
// Created by magali on 16/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_ENDGAME_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_ENDGAME_H

#include "../ViewController.h"
#include <string>

class ViewController_endGame:  public ViewController {
public:

    ViewController_endGame() = default;
    ~ViewController_endGame() override = default;
    void handleEvent(string event) override;
    bool end() override;
    string getNextView() override;

    void setWinners(char winner_1, char winner_2);

    string giveNewParameters() override;

private:
    char winner_1;
    char winner_2;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_ENDGAME_H
