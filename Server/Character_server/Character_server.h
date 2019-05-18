//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H


#include <SDL_render.h>
#include "../GameObject_server/GameObject_server.h"
#include "../../utils/Logger/Logger.h"

using namespace std;

class Character_server : public GameObject_server {

public:
    Character_server(int initialY, string name);
    ~Character_server();

    void move(DirectionVector* direction) override ;
    vector<int> getInfo() override ;
    void setState(string state);
    void stayInFloor() override ;
    void changePosition(int changeX, int changeY);
    void setInitialXPositions(int positionLeft, int positionRight);
    void setInitialPos(bool left);
    string name;

    void flipSprite(SDL_RendererFlip flip);
    vector<int> getPosInfo() override;

    string getState();

private:

    int initialY;
    CLogger* logger = CLogger::GetLogger();
    int posInitialLeft;
    int posInitialRight;
    string state;
    SDL_RendererFlip flip;

};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
