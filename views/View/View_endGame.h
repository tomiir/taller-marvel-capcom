//
// Created by magali on 16/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H
#define TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H

#include "View.h"

class View_endGame: public View {
public:

    View_endGame(SDL_Renderer *renderer_);
    ~View_endGame() override = default;
    void addBackground(GameObject* background, GameObject* ilumination);
    void addWinners(vector <GameObject*> winners);

    void updateView() override;
    void updateWinners(char* winner);
    bool end() override;
    string getNextView() override;


    void addGameObject_disconnected(GameObject *disconnected_);
    void renderDisconnected() override;

private:
    GameObject* background;
    GameObject* ilumination;
    map <string,GameObject*> winners;
    map <string, GameObject*>::iterator itr_winners= winners.begin();
    string winner_string;


};


#endif //TALLER_MARVEL_CAPCOM_VIEW_ENDGAME_H
