//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects/GameObject/GameObject.h"
#include "../../utils/EventToValueMapper/EventToValueMapper_player/EventToValueMapper.h"
#include "../../utils/Logger/Logger.h"
#include "Renderable.h"
using namespace std;

class Controller: virtual public Renderable{

public:
    string getName();

protected:
    GameObject * gameObject;

    DirectionVector* RIGHT = new DirectionVector(1, 0);
    DirectionVector* LEFT = new DirectionVector(-1, 0);
    DirectionVector* UP = new DirectionVector(0, -1);
    DirectionVector* DOWN = new DirectionVector(0, 1);
    DirectionVector* GETTINGUP = new DirectionVector(0, 2);

    DirectionVector* DIAGONAL_UP_RIGHT = new DirectionVector(1, -1);
    DirectionVector* DIAGONAL_UP_LEFT = new DirectionVector(-1, -1);

    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    int jumpSpeed = 13;




public:
    Controller(GameObject* gameObject_);
    ~Controller();
    int getZIndex() override;
    void render() override;
    virtual void handleEvent(SDL_Event event);
    vector<int> getInfo();

private:
    void writeLog(string content);
};


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
