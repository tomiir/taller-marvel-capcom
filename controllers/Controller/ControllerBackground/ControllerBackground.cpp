#include "ControllerBackground.h"


ControllerBackground::ControllerBackground(GameObject* background_, ControllerCharacter* controllerCharacter_, int speedCam_) : Controller(background_) {

    controllerCharacter = controllerCharacter_;
    speedCam = speedCam_;
}

ControllerBackground::~ControllerBackground() = default;


void ControllerBackground::render() {
}

void ControllerBackground::handleEvent(SDL_Event event) {

    vector<int> dir = {0,0};
    dir = mapper->map(event, dir);


    vector<int> cameraInfo = dynamic_cast<Background*>(gameObject)->getCameraInfo();
    vector<int> infoCharacter = controllerCharacter->getInfo();
    vector<int> infoBackground = gameObject->getInfo();

    bool characterIsInRightBoundary = infoCharacter[0] > (cameraInfo[2] - infoCharacter[2] - 20);
    bool cameraIsUnderRightLimit = cameraInfo[0] < (infoBackground[0] - cameraInfo[2]);
    bool characterIsInLeftBoundary = infoCharacter[0] < 20;
    bool cameraIsOverLeftLimit = cameraInfo[0] > 0;

    if (( dir[0] == RIGHT and characterIsInRightBoundary and cameraIsUnderRightLimit) or (dir[0] == LEFT and characterIsInLeftBoundary and cameraIsOverLeftLimit)){
        dir[0] *= speedCam;
        dir[1] *= speedCam;
        gameObject->move(dir);
    }
}

