#include "ControllerBackground.h"


ControllerBackground::ControllerBackground(GameObject* background_, ControllerCharacter* controllerCharacter_, int speedCam_, double speedPercentageCam_) :
                      Controller(background_) {

    controllerCharacter = controllerCharacter_;
    speedCam = speedCam_;
    speedPercetageCam = speedPercentageCam_;
}

ControllerBackground::~ControllerBackground() = default;


void ControllerBackground::render() {}

void ControllerBackground::handleEvent(SDL_Event event) {

    vector<int> dir = {0, 0};
    dir = mapper->map(event, dir);


    vector<int> cameraInfo = dynamic_cast< Background* >(gameObject)->getCameraInfo();
    vector<int> infoCharacter = controllerCharacter->getInfo();
    vector<int> infoBackgroundImg = gameObject->getInfo();

    bool characterIsInRightBoundary = infoCharacter[0] > (cameraInfo[2] - infoCharacter[2] - distanceBoundaryHorizontal);
    bool cameraIsUnderRightLimit = cameraInfo[0] < (infoBackgroundImg[0] - cameraInfo[2]);
    bool characterIsInLeftBoundary = infoCharacter[0] < distanceBoundaryHorizontal;
    bool cameraIsOverLeftLimit = cameraInfo[0] > 0;

    bool characterIsInUpBoundary = infoCharacter[1] < distanceBoundaryVertical;
    bool cameraIsOverUpLimit = cameraInfo[1] > 0;
    bool characterIsInDownBoundary = infoCharacter[1] > (cameraInfo[1] - infoCharacter[1] - distanceBoundaryHorizontal);
    bool cameraIsUnderDownLimit = cameraInfo[1] < (infoBackgroundImg[1] - cameraInfo[3]);


    if ( (dir[0] == RIGHT and characterIsInRightBoundary and cameraIsUnderRightLimit and !controllerCharacter->isJumping()) or
        (dir[0] == LEFT and characterIsInLeftBoundary and cameraIsOverLeftLimit and !controllerCharacter->isJumping()) ) {

        dir[0] *= speedCam;
        gameObject->move(dir);
    }

    if (characterIsInUpBoundary and cameraIsOverUpLimit) {

        dir[1] = -jumpSpeed / 2;
        gameObject->move(dir);
    }

    if( characterIsInDownBoundary and cameraIsUnderDownLimit ){

        dir[1] = jumpSpeed / 2;
        gameObject->move(dir);
    }

    if (characterIsInRightBoundary and cameraIsUnderRightLimit and controllerCharacter->isJumpingRight()) {

        dir[0] = (jumpSpeed / 2) * speedPercetageCam;
        gameObject->move(dir);
    }

    if (characterIsInLeftBoundary and cameraIsOverLeftLimit and controllerCharacter->isJumpingLeft()) {

        dir[0] = -(jumpSpeed / 2) * speedPercetageCam;
        gameObject->move(dir);
    }
}

