
#include "BackgroundsController.h"

void BackgroundsController::widthVeluesRefresh() {

    for( itr; itr != backgrounds.end() ; ++itr ){

//        if (backgrounds.empty()) break;

        int backgroundWidth = (*itr)->getWidth();
        int backgroundHeight = (*itr)->getHeight();

        if( minWidth >= backgroundWidth ) minWidth = backgroundWidth;
        if( maxWidth <= backgroundWidth ) maxWidth = backgroundWidth;
        if( minWidth <= backgroundHeight ) minHeight = backgroundHeight;
    }

    itr = backgrounds.begin();

}


void BackgroundsController::addBackgroundController(ControllerBackground *background) {

    if(!background) {}// lanzar excepcion

    backgrounds.push_back(background);
    widthVeluesRefresh();
}



void BackgroundsController::render() {

}


bool BackgroundsController::canMove(DirectionVector *direction, ControllerCharacter* character, vector<int> infoCharacter ) {

    bool valid = false;

    int characterPosX = infoCharacter[0];
    int characterPosY = infoCharacter[1];
    int characterWidth = infoCharacter[2];
    int characterHeight = infoCharacter[3];

    bool characterIsInRightBoundary = characterPosX > ( camera.w - characterWidth - distanceBoundaryHorizontal);
    bool cameraIsUnderRightLimit = characterPosX < (minWidth - camera.w);
    bool characterIsInLeftBoundary = characterPosX < distanceBoundaryHorizontal;
    bool cameraIsOverLeftLimit = camera.x > 0;

    bool characterIsInUpBoundary = characterPosY < distanceBoundaryVertical;
    bool cameraIsOverUpLimit = camera.y > 0;
    bool characterIsInDownBoundary = characterPosY > (camera.y - characterPosY - distanceBoundaryVertical);
    bool cameraIsUnderDownLimit = camera.y < (minHeight - camera.h);

    if( (direction->isEqual(RIGHT) and characterIsInRightBoundary and cameraIsUnderRightLimit and !character->isJumping()) or
        (direction->isEqual(LEFT) and characterIsInLeftBoundary and cameraIsOverLeftLimit and !character->isJumping()) ){

        for (itr ; itr != backgrounds.end(); ++itr) (*itr)->move(direction);
        itr = backgrounds.begin();
        valid = true;
    }

    if( characterIsInUpBoundary and cameraIsOverUpLimit ) {

        direction->setY(-jumpSpeed / 2);
        for (itr; itr != backgrounds.end(); ++itr) (*itr)->elevate(direction);
        itr = backgrounds.begin();
        valid = true;
    }

    if( characterIsInDownBoundary and cameraIsUnderDownLimit ) {

        direction->setY(jumpSpeed / 2);
        for (itr; itr != backgrounds.end(); ++itr) (*itr)->elevate(direction);
        itr = backgrounds.begin();
        valid = true;
    }

    if( characterIsInRightBoundary and cameraIsUnderRightLimit and character->isJumpingRight() ){

        direction->setX(jumpSpeed/2);
        for(itr; itr != backgrounds.end(); ++itr) (*itr)->moveAndElevate(direction);
        itr = backgrounds.begin();
        valid = true;
    }

    if( characterIsInLeftBoundary and cameraIsOverLeftLimit and character->isJumpingLeft() ){

        direction->setX(-jumpSpeed/2);
        for(itr; itr != backgrounds.end(); ++itr) (*itr)->moveAndElevate(direction);
        itr = backgrounds.begin();
        valid = true;
    }

    return valid;
}