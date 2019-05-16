//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H


#include "../GameObject_server/GameObject_server.h"
#include "../../utils/Logger/Logger.h"

using namespace std;

class Character_server : public GameObject_server {

public:
    Character_server(string name_, int initialY, string name);
    ~Character_server();

    void move(DirectionVector* direction) override ;
    vector<int> getInfo() override ;
    void setState(string state);
    void stayInFloor() override ;
    void changePosition(int changeX, int changeY);
    void setInitialXPositions(int positionLeft, int positionRight);
    void setInitialPos(bool left);
    string name;

private:

    int initialY;
    CLogger* logger = CLogger::GetLogger();
    int posInitialLeft;
    int posInitialRight;
    sting state;

};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
