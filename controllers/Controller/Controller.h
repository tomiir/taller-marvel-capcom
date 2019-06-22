//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects_fight/GameObject/GameObject.h"
#include "../../utils/Mapper/Mapper_fight/Mapper_fight.h"
#include "../../utils/Logger/Logger.h"
#include "Renderable.h"
#include "../../Server/GameObject_server/GameObject_server.h"

using namespace std;

class Controller{

public:
    string getName();
    Controller(GameObject_server* gameObject_, int jumpSpeed);
    ~Controller();
    virtual void handleEvent(string event);
    vector<int> getInfo();

protected:
    GameObject_server * gameObject;

    DirectionVector* RIGHT = new DirectionVector(1, 0);
    DirectionVector* LEFT = new DirectionVector(-1, 0);
    DirectionVector* UP = new DirectionVector(0, -1);
    DirectionVector* DOWN = new DirectionVector(0, 1);
    DirectionVector* GETTINGUP = new DirectionVector(0, 2);
    DirectionVector* STOPRIGHT = new DirectionVector(2, 0);
    DirectionVector* STOPLEFT = new DirectionVector(-2, 0);
    DirectionVector* KEYSRELEASED = new DirectionVector(0, 0);
    DirectionVector* CHANGECHARACTER = new DirectionVector(4, 0);
    DirectionVector* WEAK_PUNCH = new DirectionVector(-5, -5);
    DirectionVector* WEAK_KICK = new DirectionVector(-6, -5);
    DirectionVector* STRONG_PUNCH = new DirectionVector(-5, -7);
    DirectionVector* STRONG_KICK = new DirectionVector(-6, -7);
    DirectionVector* GUARD = new DirectionVector(3, 0);
    DirectionVector* GRAB = new DirectionVector(-3, -3);
    DirectionVector* STOP_GUARD = new DirectionVector(-3, 0);
    DirectionVector* THROW = new DirectionVector(8, 8);


    DirectionVector* DIAGONAL_UP_RIGHT = new DirectionVector(1, -1);
    DirectionVector* DIAGONAL_UP_LEFT = new DirectionVector(-1, -1);

    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    int jumpSpeed;

private:
    void writeLog(string content);
};


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
