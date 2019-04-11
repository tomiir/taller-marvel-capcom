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
            void handleEvent(SDL_Event event, ControllerCharacter* controllerCharacter1, ControllerCharacter* controllerCharacter2);
            void update(ControllerCharacter* controllerCharacterOnLeft,const vector<int>& characterOnLeftInfo, ControllerCharacter* controllerCharacterOnRight,const vector<int>& characterOnRightInfo);

    private:

            double speedCam;
            double speedPercetageCam;
            ControllerCharacter* controllerCharacterOnLeft;
            vector<int> characterOnLeftInfo;
            ControllerCharacter* controllerCharacterOnRight;
            vector<int> characterOnRightInfo;


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERBACKGROUND_H