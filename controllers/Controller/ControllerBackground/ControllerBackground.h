//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H


#include "../Controller.h"
#include "../../../model/GameObjects/Background/Background.h"
#include "../ControllerCharacter/ControllerCharacter.h"

using namespace std;

class ControllerBackground : public Controller {

    public:
            ControllerBackground(GameObject* background, ControllerCharacter* controllerCharacter, int speedCam_);
            ~ControllerBackground();
            void render();
            void handleEvent(SDL_Event event);

    private:
            ControllerCharacter* controllerCharacter;
            int speedCam;
};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H