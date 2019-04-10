//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H


#include "../Controller.h"
#include "../../../model/GameObjects/Background/Background.h"
#include "../ControllerCharacter/ControllerCharacter.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"


using namespace std;

class ControllerBackground {

    public:
            ControllerBackground(Background* background, int speedCam_, double speedPercentageCam_);
            ~ControllerBackground();
            void handleEvent(SDL_Event event, ControllerCharacter* controllerCharacter1, ControllerCharacter* controllerCharacter2);
            void render();

    private:
            DirectionVector* RIGHT = new DirectionVector(1, 0);
            DirectionVector* LEFT = new DirectionVector(-1, 0);
            DirectionVector* UP = new DirectionVector(0, -1);
            DirectionVector* DOWN = new DirectionVector(0, 1);
            DirectionVector* STILL = new DirectionVector(0, 0);

            DirectionVector* DIAGONAL_UP_RIGHT = new DirectionVector(1, -1);
            DirectionVector* DIAGONAL_UP_LEFT = new DirectionVector(-1, -1);

            int distanceBoundaryHorizontal = 25;
            int distanceBoundaryVertical = 75;
            int jumpSpeed = 10;

            double speedCam;
            double speedPercetageCam;
            Background* gameObject;


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H