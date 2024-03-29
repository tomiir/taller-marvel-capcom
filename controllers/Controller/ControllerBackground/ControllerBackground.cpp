#include <utility>

#include "ControllerBackground.h"
#include "../../../Server/Background_server/Background_server.h"


ControllerBackground::ControllerBackground(GameObject_server* background_, int jumpSpeed) :
                      Controller(background_, jumpSpeed){
    this->speedCam = dynamic_cast<Background_server*> (background_)->getSpeedCam();
    this->speedPercetageCam = dynamic_cast<Background_server*> (background_) ->getSpeedPercetageCam();
}


ControllerBackground::~ControllerBackground() = default;

void ControllerBackground::handleEvent(string event, ControllerCharacter* controllerCharacter1, ControllerCharacter* controllerCharacter2) {

    vector<int> cameraInfo = dynamic_cast< Background_server* >(gameObject)->getCameraInfo();
    vector<int> infoCharacter1 = controllerCharacter1->getInfo();
    vector<int> infoCharacter2 = controllerCharacter2->getInfo();
    vector<int> infoBackgroundImg = gameObject->getInfo();

    DirectionVector* dirLeft = new DirectionVector();
    DirectionVector* dirRight = new DirectionVector();
    DirectionVector* dirUp = new DirectionVector();


    int distanceBetweenCharacters = characterOnRightInfo[0]+characterOnRightInfo[2] - characterOnLeftInfo[0];

    bool distanceMinorCameraWidth =  distanceBetweenCharacters < cameraInfo[2] - 2* distanceBoundaryHorizontal;
    bool distanceEqualCameraWidth =  distanceBetweenCharacters == cameraInfo[2]- 2* distanceBoundaryHorizontal;



    bool characterOnRightIsInRightBoundary = characterOnRightInfo[0] > (cameraInfo[2] - characterOnRightInfo[2] - distanceBoundaryHorizontal);
    bool cameraIsUnderRightLimit = cameraInfo[0] < (infoBackgroundImg[0] - cameraInfo[2] - 80);
    bool characterOnLeftIsInLeftBoundary = characterOnLeftInfo[0] < distanceBoundaryHorizontal;
    bool cameraIsOverLeftLimit = cameraInfo[0] > 80;


    bool characterIsInUpBoundary = infoCharacter1[1] < distanceBoundaryVertical and
                                   infoCharacter2[1] < distanceBoundaryVertical + cameraInfo[3] - 400;

    bool cameraIsOverUpLimit = cameraInfo[1] > 0;

    bool characterIsInDownBoundary = infoCharacter1[1] > (cameraInfo[1] - infoCharacter1[1] - distanceBoundaryHorizontal) and
                                     infoCharacter2[1] > (cameraInfo[1] - infoCharacter2[1] - distanceBoundaryHorizontal);

    bool cameraIsUnderDownLimit = cameraInfo[1] < (infoBackgroundImg[1] - cameraInfo[3]);

    if(controllerCharacterOnRight->isMovingRight() and distanceMinorCameraWidth and cameraIsUnderRightLimit and characterOnRightIsInRightBoundary and !distanceEqualCameraWidth and !controllerCharacterOnRight->isJumping()){

        int speed = (int) ((speedCam/2) - 0.01) + 1;
        dirRight->setX(speed);
        gameObject->move(dirRight);

        dirRight->setX(-(speedCam/5) - 0.6);
        controllerCharacterOnLeft->move(dirRight);

        DirectionVector* projectileSpeed = new DirectionVector();
        projectileSpeed->setX(-(speedCam/5) - 0.8);

        controllerCharacter1->moveProjectile(projectileSpeed);
        controllerCharacter2->moveProjectile(projectileSpeed);

        delete projectileSpeed;
    }

    if(controllerCharacterOnLeft->isMovingLeft() and distanceMinorCameraWidth and cameraIsOverLeftLimit and characterOnLeftIsInLeftBoundary and !distanceEqualCameraWidth and !controllerCharacterOnLeft->isJumping()){

        int speed = (int) ((-speedCam/2) + 0.01) - 1;
        dirLeft->setX(speed);
        gameObject->move(dirLeft);

        dirLeft->setX((speedCam/5) + 0.6);
        controllerCharacterOnRight->move(dirLeft);

        DirectionVector* projectileSpeed = new DirectionVector();
        projectileSpeed->setX((speedCam/5) + 0.8);

        controllerCharacter1->moveProjectile(projectileSpeed);
        controllerCharacter2->moveProjectile(projectileSpeed);

        delete projectileSpeed;
    }


    if (characterIsInUpBoundary and cameraIsOverUpLimit and !controllerCharacter1->isChanging()) {

        dirUp->setY( -jumpSpeed/2 );
        gameObject->move(dirUp);

        dirUp->multiply(-1);
        controllerCharacter1->moveProjectile(dirUp);
        controllerCharacter2->moveProjectile(dirUp);
    }

    if( characterIsInDownBoundary and cameraIsUnderDownLimit ){

        dirUp->setY( jumpSpeed/2 );
        gameObject->move(dirUp);

        dirUp->multiply(-1);
        controllerCharacter1->moveProjectile(dirUp);
        controllerCharacter2->moveProjectile(dirUp);
    }


    if (characterOnRightIsInRightBoundary and cameraIsUnderRightLimit and controllerCharacter1->isJumpingRight() and distanceMinorCameraWidth and (controllerCharacterOnRight == controllerCharacter1)) {

        dirLeft->setX( (jumpSpeed/2) * speedPercetageCam );
        gameObject->move(dirLeft);

        dirLeft->setX(-(((jumpSpeed/2) * speedPercetageCam)/2) -0.7);
        controllerCharacterOnLeft->move(dirLeft);

    }

    if (characterOnLeftIsInLeftBoundary and cameraIsOverLeftLimit and controllerCharacter1->isJumpingLeft() and distanceMinorCameraWidth and (controllerCharacterOnLeft == controllerCharacter1)) {

        dirRight->setX( -(jumpSpeed/2) * speedPercetageCam );
        gameObject->move(dirRight);

        dirRight->setX((((jumpSpeed/2) * speedPercetageCam)/2) +0.7);
        controllerCharacterOnRight->move(dirRight);

    }

    delete dirUp;
    delete dirLeft;
    delete dirRight;
}

void ControllerBackground::update(ControllerCharacter *controllerCharacterOnLeft_,const vector<int>& characterOnLeftInfo_,
                                  ControllerCharacter *controllerCharacterOnRight_,const vector<int>& characterOnRightInfo_) {

    controllerCharacterOnLeft = controllerCharacterOnLeft_;
    controllerCharacterOnRight = controllerCharacterOnRight_;

    characterOnLeftInfo = characterOnLeftInfo_;
    characterOnRightInfo = characterOnRightInfo_;

}

vector<int> ControllerBackground::getPosCamera() {

     return gameObject->getPosInfo();
}
