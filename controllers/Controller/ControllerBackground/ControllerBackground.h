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

class ControllerBackground : public Controller {

    public:
            ControllerBackground(GameObject* background, int speedCam_, double speedPercentageCam_);
            ~ControllerBackground();
            void handleEvent(SDL_Event event) override;

    private:

            double speedCam;
            double speedPercetageCam;


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H