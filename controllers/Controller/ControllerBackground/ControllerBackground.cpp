#include "ControllerBackground.h"


ControllerBackground::ControllerBackground(GameObject* background_, int speedCam_, double speedPercentageCam_) : Controller(background_){

    speedCam = speedCam_;
    speedPercetageCam = speedPercentageCam_;
}

ControllerBackground::~ControllerBackground() = default;

void ControllerBackground::elevate(DirectionVector *direction) {

    gameObject->move(direction);

}

void ControllerBackground::move(DirectionVector *direction) {

    direction->multiply(speedCam);
    gameObject->move(direction);
}

void ControllerBackground::moveAndElevate(DirectionVector *direction) {

    direction->setX( direction->x * speedPercetageCam );
    gameObject->move(direction);
}

int ControllerBackground::getWidth() {

    return  gameObject->getInfo()[0];
}

int ControllerBackground::getHeight() {

    return gameObject->getInfo()[1];
}

