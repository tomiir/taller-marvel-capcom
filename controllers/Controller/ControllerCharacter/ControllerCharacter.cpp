//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"
#include <chrono>
#include <thread>
#include "../../../utils/Logger/Logger.h"
#include <unistd.h>

ControllerCharacter::ControllerCharacter(GameObject_server* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_, int jumpSpeed) : Controller(gameObject, jumpSpeed){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_;
    jump = jumpRight = jumpLeft = inAir = leaving = entering = crowchedDown = movingRight 
            = punching =  movingLeft = moving = guarding = strongPunching = alreadyPunchInAir = kicked = false;

    collisionManager = new CollisionManager();

}

ControllerCharacter::~ControllerCharacter() = default;


DirectionVector* giveDirectionVect(string event){

    DirectionVector* direction = new DirectionVector();

    if (event == "h"){
      direction->add(0, 0);
    }
    else if (event == "d") {
        direction->add(1, 0);
    }
    else if (event == "a") {
        direction->add(-1, 0);
    }
    else if (event == "w") {
        direction->add(0, -1);
    }
    else if (event == "s") {
        direction->add(0, 1);
    }
    else if (event == "c") {
        direction->add(4, 0);
    }
    else if (event == "e") {
        direction->setDiagonal(1);
        direction->setY(-1);
    }
    else if (event == "q"){
        direction->setDiagonal(-1);
        direction->setY(-1);
    }
    else if (event == "r"){
        direction->add(0, 2);
    }
    else if (event == "t"){
        direction->add(-2, 0);
    }
    else if (event == "y"){
        direction->add(2, 0);
    }
    //Punch
    else if (event == "p") {
        direction ->add(-5,-5);
    }
    else if (event == "o") {
        direction ->add(-5,-7);
    }
    else if (event == "l") {
        direction ->add(-6,-5);
    }
    else if (event == "k") {
        direction ->add(-6,-7);
    }
    else if (event == "j") {
        direction ->add(3, 0);
    }
    else if (event == "m") {
        direction ->add(-3,-3);
    }
    else if (event == "i") {
        direction ->add(-3,0);
    }
    return direction;
}



void ControllerCharacter::handleEvent(string event, GameObject_server* enemy, ControllerCharacter* enemyController) {

    DirectionVector *direction = giveDirectionVect(event);

    vector<int> info = gameObject->getInfo();
    vector<int> enemyInfo = enemy->getInfo();

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= 0;
    bool collision = collisionManager->Collisioning(gameObject, enemy);


    if(punching) {
        punching = ++punching_timer != 20;
        if(!punching) {
            if(!inAir) {
                if(state != "weakDownPunch" and state != "weakDownKick" and
                state != "strongDownPunch" and state != "strongDownKick") state = "walk";
                else state = "crowchedDown";
            }
            else state = "jump";

            movingLeft = false;
            movingRight = false;
        }
    }

    if(strongPunching) {
        strongPunching = ++strongPunching_timer != 28;
        if(!strongPunching) {
            if(!inAir) {
                if(state != "weakDownPunch" and state != "weakDownKick" and
                   state != "strongDownPunch" and state != "strongDownKick") state = "walk";
                else state = "crowchedDown";
            }
            else state = "jump";

            movingLeft = false;
            movingRight = false;
        }
    }

    if(kicked) {
        kicked = ++kicked_timer != 18;
        if(!kicked) {
            if(!inAir) {
                if(state != "downKicked") state = "still";
                else state = "crowchedDown";
            }
            else state = "jump";
        }
    }

    if (direction->isEqual(STOP_GUARD)) {
        if (inAir) state = "jump";
        else if(state != "downGuard") state = "still";  //ESTO NO SE SI ESTA BIEN. HAY QUE PROBAR
        else state = "crowchedDown";

        guarding = false;

        movingLeft = false;
        movingRight = false;
    }

    if (direction->isEqual(RIGHT) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked) {
        state = "walk";
        movingRight = true;
    }
    if (direction->isEqual(LEFT) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked) {
        state = "walk";
        movingLeft = true;
    }
    if (direction->isEqual(DOWN) and !inAir and !punching and !guarding and !strongPunching and !kicked) {
        if (state != "crowchedDown") logger->Log("El personaje " + character->getName() + " se agacho.", DEBUG, "");
        state = "crowchedDown";
        crowchedDown = true;
    }

    if (direction->isEqual(GUARD) and !punching and !strongPunching and !kicked) {
        if(state == "crowchedDown" or state == "downGuard"){
            state = "downGuard";
        }else if(inAir){
            state = "airGuard";
        }else state = "standGuard";
        guarding = true;
    }



    if (direction->isEqual(GETTINGUP)) {
        state = "still";
        crowchedDown = false;
    }
    if ((direction->isEqual(STOPRIGHT) or inAir)and !punching and !guarding and !strongPunching and !kicked) {
        movingRight = false;
        state = "still";
    }
    if ((direction->isEqual(STOPLEFT) or inAir)and !punching and !guarding and !strongPunching and !kicked) {
        movingLeft = false;
        state = "still";
    }
    if (direction->isEqual(KEYSRELEASED) and !inAir and !crowchedDown and !movingLeft and !movingRight and !punching and !guarding and !strongPunching and !kicked)
        state = "still";


    //LOGICA DE GOLPES
    if(direction -> isEqual(WEAK_PUNCH) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "weakDownPunch";
        }else if(inAir){
            state = "weakAirPunch";
            alreadyPunchInAir = true;
        }else state = "weakStandPunch";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
            enemyController->Kicked();
        }
    }

    if(direction -> isEqual(STRONG_PUNCH) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "strongDownPunch";
        }else if(inAir){
            state = "strongAirPunch";
            alreadyPunchInAir = true;
        }else state = "strongStandPunch";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        strongPunching = true;
        strongPunching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
            enemyController->Kicked();
        }
    }

    if(direction -> isEqual(WEAK_KICK) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "weakDownKick";
        }else if(inAir){
            state = "weakAirKick";
            alreadyPunchInAir = true;
        }else state = "weakStandKick";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
            enemyController->Kicked();
        }
    }

    if(direction -> isEqual(STRONG_KICK) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "strongDownKick";
        }else if(inAir){
            state = "strongAirKick";
            alreadyPunchInAir = true;
        }else state = "strongStandKick";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        strongPunching = true;
        strongPunching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
            enemyController->Kicked();
        }
    }


    //

    if (movingRight and characterIsntInRightBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding and !strongPunching and !kicked) {

        state = "walk";

        direction->setX(speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (movingLeft and characterIsntInLeftBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding and !strongPunching and !kicked) {

        state = "walk";

        direction->setX(-speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (direction->isDiagonalRight() and !inAir and !crowchedDown and !punching and !strongPunching and !kicked) jumpRight = true;
    if (direction->isDiagonalLeft() and !inAir and !crowchedDown and !punching and !strongPunching and !kicked) jumpLeft = true;
    if (direction->isEqual(UP) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked) {
        logger->Log("El personaje " + character->getName() + " salto.", DEBUG, "");
        jump = true;
    }

    if (direction->isEqual(DOWN) and !inAir and !punching and !guarding and !strongPunching and !kicked) {
        state = "crowchedDown";
    }

    if (direction->isEqual(GETTINGUP) and !inAir and !punching and !strongPunching and !kicked) gameObject->stayInFloor();

    if (jump) {

        if(!punching and !guarding and !strongPunching and !kicked) state = "jump";
        inAir = true;
        DirectionVector *step = new DirectionVector(0, -jumpSpeed);

        if (jumpRight and characterIsntInRightBoundary) step->setX(jumpSpeed / 2);
        if (jumpLeft and characterIsntInLeftBoundary) step->setX(-jumpSpeed / 2);

        gameObject->move(step);

        bool characterTopOfJump = info[1] <= jumpDistance;
        if (characterTopOfJump) jump = false;

        delete step;
    }

    if (!jump and inAir and !leaving) {

        if(!punching and !guarding and !strongPunching and !kicked) state = "jump";

        DirectionVector *step = new DirectionVector(0, jumpSpeed);
        if (jumpRight and characterIsntInRightBoundary) step->setX(jumpSpeed / 2);
        if (jumpLeft and characterIsntInLeftBoundary) step->setX(-jumpSpeed / 2);

        gameObject->move(step);

        bool characterInFloor = info[1] >= (screenHeight - info[3] - jumpDistance);

        if (characterInFloor) {
            inAir = jumpRight = jumpLeft = entering = false;
            gameObject->stayInFloor();
            state = "still";
            punching = false;
            punching_timer = 0;
            strongPunching = false;
            strongPunching_timer = 0;
            alreadyPunchInAir = false;
        }

        delete step;
    }

    if (direction->isEqual(CHANGECHARACTER) and !inAir) {
        leaving = true;
        logger->Log(character->getName() + " cambio de personaje", DEBUG, "");
    }

    if (leaving) {

        state = "jump";
        inAir = true;
        DirectionVector *step = new DirectionVector(0, -jumpSpeed);

        gameObject->move(step);

        delete step;
    }

    if (entering) {
        state = "entering";
    }


    if (collisionManager->Collisioning(gameObject, enemy) and characterIsntInRightBoundary and
        characterIsntInLeftBoundary and !punching and !strongPunching and !kicked) {

        if (info[0] - 40 >= enemyInfo[0]) {

            direction->setX(speedCharacter);
            logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
            gameObject->move(direction);
        } else if (info[0] + 40 <= enemyInfo[0]) {
            direction->setX(-speedCharacter);
            logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
            gameObject->move(direction);
        }
    }


    delete direction;


    dynamic_cast<Character_server *>(gameObject)->setState(state);



}

bool ControllerCharacter::isJumping() {
    return inAir;
}

bool ControllerCharacter::isJumpingRight() {
    return jumpRight;
}

bool ControllerCharacter::isJumpingLeft() {
    return jumpLeft;
}


void ControllerCharacter::move(DirectionVector *direction) {

    gameObject->move(direction);

}

void ControllerCharacter::flip(SDL_RendererFlip flip) {

    dynamic_cast<Character_server*> (gameObject)->flipSprite(flip);

}

void ControllerCharacter::changePosition(int changeX, int changeY) {

    dynamic_cast<Character_server*> (gameObject)->changePosition(changeX, changeY);

}

bool ControllerCharacter::isInAir() {
    return inAir;
}

void ControllerCharacter::gone() {

    leaving = false;

}

void ControllerCharacter::entry() {

    entering = true;
    inAir = true;

}

bool ControllerCharacter::isChanging() {
    return (entering or leaving);
}

bool ControllerCharacter::isMovingRight() {
    return movingRight;
}

bool ControllerCharacter::isMovingLeft() {
    return movingLeft;
}

void ControllerCharacter::setInitialPos(bool left) {

    character->setInitialPos(left);

}

vector<int> ControllerCharacter::getPosInfo() {
    return gameObject->getPosInfo();
}

string ControllerCharacter::getState() {
    return dynamic_cast<Character_server*>(gameObject)->getState();
}

SDL_RendererFlip ControllerCharacter::getFlip() {
    return dynamic_cast<Character_server*>(gameObject)->getFlip();
}

GameObject_server *ControllerCharacter::getGameObject() {
    return gameObject;
}

void ControllerCharacter::Kicked() {

    if(state != "downGuard" and state != "standGuard" and state != "airGuard"){

        kicked = true;
        kicked_timer = 0;

        if(state == "crowchedDown"){
            state = "downKicked";
        }else if(inAir){
            state = "airKicked";
        }else state = "standKicked";
    }
    dynamic_cast<Character_server *>(gameObject)->setState(state);
}
