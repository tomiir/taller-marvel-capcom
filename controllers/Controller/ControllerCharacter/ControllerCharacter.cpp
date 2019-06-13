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
    jump = jumpRight = jumpLeft = inAir = leaving = entering = crowchedDown = movingRight = punching =  movingLeft = moving = guarding = false;

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
        direction ->add(4, 4);
    }
    else if (event == "m") {
        direction ->add(-3,-3);
    }
    else if (event == "i") {
        direction ->add(-4,-4);
    }
    return direction;
}



void ControllerCharacter::handleEvent(string event, GameObject_server* enemy) {

    DirectionVector *direction = giveDirectionVect(event);

    vector<int> info = gameObject->getInfo();
    vector<int> enemyInfo = enemy->getInfo();

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= 0;
    bool collision = collisionManager->Collisioning(gameObject, enemy);


    if(punching) {
        punching = ++punching_timer != 15;
        if(!punching) {
            state = "walk";
        }
    }

    if (direction->isEqual(RIGHT) and !inAir and !crowchedDown and !punching and !guarding) {
        state = "walk";
        movingRight = true;
    }
    if (direction->isEqual(LEFT) and !inAir and !crowchedDown and !punching and !guarding) {
        state = "walk";
        movingLeft = true;
    }
    if (direction->isEqual(DOWN) and !inAir and !punching) {
        if (state != "crowchedDown") logger->Log("El personaje " + character->getName() + " se agacho.", DEBUG, "");
        state = "crowchedDown";
        crowchedDown = true;
    }

    if (direction->isEqual(GUARD) and !punching) {
        if(state == "crowchedDown"){
            state = "DownGuard";
        }else if(inAir){
            state = "AirGuard";
        }else state = "StandGuard";
        guarding = true;
    }

    if (direction->isEqual(STOP_GUARD)) {
        if (inAir) state = "jump";
        else state = "still";  //ESTO NO SE SI ESTA BIEN. HAY QUE PROBAR

        guarding = false;
    }

    if (direction->isEqual(GETTINGUP) and !punching) {
        state = "still";
        crowchedDown = false;
    }
    if ((direction->isEqual(STOPRIGHT) or inAir)) {
        movingRight = false;
        state = "still";
    }
    if ((direction->isEqual(STOPLEFT) or inAir)) {
        movingLeft = false;
        state = "still";
    }
    if (direction->isEqual(KEYSRELEASED) and !inAir and !crowchedDown and !movingLeft and !movingRight and !punching)
        state = "still";


    //LOGICA DE GOLPES
    if(direction -> isEqual(WEAK_PUNCH) and !punching and !guarding) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "weakDownPunch";
        }else if(inAir){
            state = "weakAirPunch";
        }else state = "weakStandPunch";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
        }
    }

    if(direction -> isEqual(STRONG_PUNCH) and !punching and !guarding) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "strongDownPunch";
        }else if(inAir){
            state = "strongAirPunch";
        }else state = "strongStandPunch";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
        }
    }

    if(direction -> isEqual(WEAK_KICK) and !punching and !guarding) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "weakDownKick";
        }else if(inAir){
            state = "weakAirKick";
        }else state = "weakStandKick";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
        }
    }

    if(direction -> isEqual(STRONG_KICK) and !punching and !guarding) {
        logger->Log("Pegando", INFO, "");

        if(state == "crowchedDown"){
            state = "strongDownKick";
        }else if(inAir){
            state = "strongAirKick";
        }else state = "strongStandKick";

        dynamic_cast<Character_server *>(gameObject)->setState(state);
        punching = true;
        punching_timer = 0;
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision){
            cout << gameObject->getName() << " golpeo a " << enemy->getName() << endl;
        }
    }


    //

    if (movingRight and characterIsntInRightBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding) {

        direction->setX(speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (movingLeft and characterIsntInLeftBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding) {

        direction->setX(-speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (direction->isDiagonalRight() and !inAir and !crowchedDown and !punching) jumpRight = true;
    if (direction->isDiagonalLeft() and !inAir and !crowchedDown and !punching) jumpLeft = true;
    if (direction->isEqual(UP) and !inAir and !crowchedDown and !punching and !guarding) {
        logger->Log("El personaje " + character->getName() + " salto.", DEBUG, "");
        jump = true;
    }

    if (direction->isEqual(DOWN) and !inAir and !punching and !guarding) {
        state = "crowchedDown";
    }

    if (direction->isEqual(GETTINGUP) and !inAir and !punching) gameObject->stayInFloor();

    if (jump) {

        state = "jump";
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

        state = "jump";

        DirectionVector *step = new DirectionVector(0, jumpSpeed);
        if (jumpRight and characterIsntInRightBoundary) step->setX(jumpSpeed / 2);
        if (jumpLeft and characterIsntInLeftBoundary) step->setX(-jumpSpeed / 2);

        gameObject->move(step);

        bool characterInFloor = info[1] >= (screenHeight - info[3] - jumpDistance);

        if (characterInFloor and !punching) {
            inAir = jumpRight = jumpLeft = entering = false;
            gameObject->stayInFloor();
            state = "still";
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
        characterIsntInLeftBoundary and !punching) {

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

    dynamic_cast<Character_server*>(gameObject)->setInitialPos(left);

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
