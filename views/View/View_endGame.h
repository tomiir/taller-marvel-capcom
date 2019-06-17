//
// Created by magali on 16/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H
#define TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H

#include "View.h"

class View_endGame: public View {
public:

    View_endGame() = default;
    ~View_endGame() override = default;
    void addBackground(GameObject* background);
    void addWinners(vector <GameObject*> winners);

    void updateView() override;
    void updateWinner(char* winner);
    bool end() override;
    string getNextView() override;


    void renderDisconnected() override;

private:
    GameObject* background;
    map <string,GameObject*> winners;
    map <string, GameObject*>::iterator itr_winners= winners.begin();
    string winner;


};


#endif //TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H
