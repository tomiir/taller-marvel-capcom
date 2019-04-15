#include <utility>

#include "ControllerBackground.h"


ControllerBackground::ControllerBackground(GameObject* background_, int z_index, int speedCam_, double speedPercentageCam_) :
                      Controller(background_, z_index){

    speedCam = speedCam_;
    speedPercetageCam = speedPercentageCam_;

}

ControllerBackground::~ControllerBackground() = default;

void ControllerBackground::handleEvent(SDL_Event event, ControllerCharacter* controllerCharacter1, ControllerCharacter* controllerCharacter2) {

    vector<int> cameraInfo = dynamic_cast< Background* >(gameObject)->getCameraInfo();
    vector<int> infoCharacter1 = controllerCharacter1->getInfo();
    vector<int> infoCharacter2 = controllerCharacter2->getInfo();
    vector<int> infoBackgroundImg = gameObject->getInfo();

    DirectionVector* dirLeft = controllerCharacterOnLeft->getMapper()->map(event);
    DirectionVector* dirRight = controllerCharacterOnRight->getMapper()->map(event);
    DirectionVector* dirUp = controllerCharacter1->getMapper()->map(event);

    int distanceBetweenCharacters = characterOnRightInfo[0]+characterOnRightInfo[2] - characterOnLeftInfo[0];

    bool distanceMinorCameraWidth =  distanceBetweenCharacters < cameraInfo[2] - 2* distanceBoundaryHorizontal;
    bool distanceEqualCameraWidth =  distanceBetweenCharacters == cameraInfo[2]- 2* distanceBoundaryHorizontal;



    bool characterOnRightIsInRightBoundary = characterOnRightInfo[0] > (cameraInfo[2] - characterOnRightInfo[2] - distanceBoundaryHorizontal);
    bool cameraIsUnderRightLimit = cameraInfo[0] < (infoBackgroundImg[0] - cameraInfo[2] - 80);
    bool characterOnLeftIsInLeftBoundary = characterOnLeftInfo[0] < distanceBoundaryHorizontal;
    bool cameraIsOverLeftLimit = cameraInfo[0] > 80;


    bool characterIsInUpBoundary = infoCharacter1[1] < distanceBoundaryVertical and
                                   infoCharacter2[1] < distanceBoundaryVertical + 300;//Este 300 es para que se mueva la cam para arriba si los dos estan en el aire
    //y no solo si estan los dos arriba de todo
    bool cameraIsOverUpLimit = cameraInfo[1] > 0;

    bool characterIsInDownBoundary = infoCharacter1[1] > (cameraInfo[1] - infoCharacter1[1] - distanceBoundaryHorizontal) and
                                     infoCharacter2[1] > (cameraInfo[1] - infoCharacter2[1] - distanceBoundaryHorizontal);

    bool cameraIsUnderDownLimit = cameraInfo[1] < (infoBackgroundImg[1] - cameraInfo[3]);

    if(dirRight->isEqual(RIGHT) and distanceMinorCameraWidth and cameraIsUnderRightLimit and characterOnRightIsInRightBoundary and !distanceEqualCameraWidth and !controllerCharacterOnRight->isJumping()){

        dirRight->multiply(speedCam/2);
        gameObject->move(dirRight);
        dirRight->setX(-speedCam/3);
        controllerCharacterOnLeft->move(dirRight);
    }

    if(dirLeft->isEqual(LEFT) and distanceMinorCameraWidth and cameraIsOverLeftLimit and characterOnLeftIsInLeftBoundary and !distanceEqualCameraWidth and !controllerCharacterOnLeft->isJumping()){

        dirLeft->multiply(speedCam/2);

        gameObject->move(dirLeft);

        dirLeft->setX(speedCam/3);
        controllerCharacterOnRight->move(dirLeft);
    }


    if (characterIsInUpBoundary and cameraIsOverUpLimit and !controllerCharacter1->isChanging()) {

        dirUp->setY( -jumpSpeed/2 );
        gameObject->move(dirUp);

    }

    if( characterIsInDownBoundary and cameraIsUnderDownLimit ){

        dirUp->setY( jumpSpeed/2 );
        gameObject->move(dirUp);

    }

    if (characterOnRightIsInRightBoundary and cameraIsUnderRightLimit and controllerCharacter1->isJumpingRight() and distanceMinorCameraWidth and (controllerCharacterOnRight == controllerCharacter1)) {

        dirLeft->setX( (jumpSpeed/2) * speedPercetageCam );
        gameObject->move(dirLeft);

        dirLeft->setX(-(((jumpSpeed/2) * speedPercetageCam)/2) -1);
        controllerCharacterOnLeft->move(dirLeft);

    }

    if (characterOnLeftIsInLeftBoundary and cameraIsOverLeftLimit and controllerCharacter1->isJumpingLeft() and distanceMinorCameraWidth and (controllerCharacterOnLeft == controllerCharacter1)) {

        dirRight->setX( -(jumpSpeed/2) * speedPercetageCam );
        gameObject->move(dirRight);

        dirRight->setX((((jumpSpeed/2) * speedPercetageCam)/2) +1);
        controllerCharacterOnRight->move(dirRight);

    }

}

void ControllerBackground::update(ControllerCharacter *controllerCharacterOnLeft_,const vector<int>& characterOnLeftInfo_,
                                  ControllerCharacter *controllerCharacterOnRight_,const vector<int>& characterOnRightInfo_) {

    controllerCharacterOnLeft = controllerCharacterOnLeft_;
    controllerCharacterOnRight = controllerCharacterOnRight_;

    characterOnLeftInfo = characterOnLeftInfo_;
    characterOnRightInfo = characterOnRightInfo_;

}


