//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"
#include <chrono>
#include <thread>
#include "../../../utils/Logger/Logger.h"
#include <unistd.h>

ControllerCharacter::ControllerCharacter(GameObject_server* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_, int jumpSpeed, Character_server* projectile_) : Controller(gameObject, jumpSpeed){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_;
    jump = jumpRight = jumpLeft = inAir = leaving = entering = crowchedDown = movingRight = punching =  movingLeft =
            moving = guarding = strongPunching = alreadyPunchInAir = kicked = defeated = throwing = projectile_flying = grab = grabbed = grabbedImpact = false;

    collisionManager = new CollisionManager();

    projectile = projectile_;
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
    else if (event == "n") {
        direction ->add(8,8);
    }
    return direction;
}



void ControllerCharacter::handleEvent(string event, GameObject_server* enemy, ControllerCharacter* enemyController, int mate_life) {

    DirectionVector *direction = giveDirectionVect(event);

    vector<int> info = gameObject->getInfo();
    vector<int> enemyInfo = enemy->getInfo();

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= 0;
    bool collision = collisionManager->Collisioning(gameObject, enemy);

    if (defeated){
        state = "standKicked";
        jump = true;
        inAir = true;
        if (info[0] >= enemyInfo[0]) jumpRight = true;
        else jumpLeft = true;
    }


    if(projectile_flying) {

        DirectionVector *step = new DirectionVector(speedProjectile, 0);

        projectile->moveFoward(step);

        projectile->setState("flying");
        collision = collisionManager->Collisioning(projectile, enemy);
        if(collision){
            enemyController->Kicked(WEAK);
            projectile_flying = false;
        }

        vector<int> projectile_info= projectile->getInfo();

        if(projectile_info[0] <= (0 - projectile_info[2]) or projectile_info[0] >= screenWidth) projectile_flying = false;

        delete step;

    }

    if(throwing) {
        throwing = ++throwing_timer != 20;
        if (!throwing) {
            state = "still";
            projectile_flying = true;

            bool flip = character->isFlip();
            projectile->setNewPosition(info[0], info[2], flip);
        }
    }

    if(grab){
        grab = ++ grabing_timer != 20;
        if(!grab){
            state = "still";
        }
    }


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

    if (direction->isEqual(RIGHT) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {
        state = "walk";
        movingRight = true;
    }
    if (direction->isEqual(LEFT) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {
        state = "walk";
        movingLeft = true;
    }
    if (direction->isEqual(DOWN) and !inAir and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {
        if (state != "crowchedDown") logger->Log("El personaje " + character->getName() + " se agacho.", DEBUG, "");
        state = "crowchedDown";
        crowchedDown = true;
    }

    if (direction->isEqual(GUARD) and !punching and !strongPunching and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
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
    if ((direction->isEqual(STOPRIGHT) or inAir)and !punching and !guarding and !strongPunching and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
        movingRight = false;
        state = "still";
    }
    if ((direction->isEqual(STOPLEFT) or inAir)and !punching and !guarding and !strongPunching and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
        movingLeft = false;
        state = "still";
    }
    if (direction->isEqual(KEYSRELEASED) and !inAir and !crowchedDown and !movingLeft and !movingRight and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact)
        state = "still";

    //LOGICA DE TIRAR PROYECTIL
    if (direction->isEqual(THROW) and (state == "still" or state == "walk") and !projectile_flying and !inAir){

        movingRight = false;
        movingLeft = false;
        throwing = true;
        state = "throw";
        throwing_timer = 0;
    }

    if(direction->isEqual(GRAB) and (state == "still" or state == "walk") and !inAir){
        movingRight = false;
        movingLeft = false;
        grab = true;
        string oldState = state;
        state = "grab";
        character->setState(state);
        collision = collisionManager->Collisioning(gameObject, enemy);
        if(collision and !enemyController->isInAir()){
            grabing_timer = 0;
            enemyController->Grabbed();
        }
        else{
            grab = false;
            state = oldState;
            character->setState(state);
        }
    }

    if(state == "grabbed" or state == "grabbedImpact"){

        inAir = true;
        grabbed = true;

        DirectionVector* step;
        SDL_RendererFlip flip = this->getFlip();

        if(flipFlag == 0){
            if(flip == SDL_FLIP_NONE) isFliped = false;
            if(flip == SDL_FLIP_HORIZONTAL) isFliped = true;
            flipFlag = 1;
        }

        if( !characterIsntInLeftBoundary or !characterIsntInRightBoundary ){
            grabbed = false;
            grabbedImpact = true;

            if(grabbed_impact_timer == 20) {
                state = "still";
                inAir = false;
                grabbedImpact = false;
                gameObject->stayInFloor();
                life -= grabbed_dmg;
                flipFlag = 0;
                if (life <= 0) {
                    life = 0;
                    defeated = true;
                }
                grabbed_impact_timer = 0;
            } else {
                state = "grabbedImpact";
                grabbed_impact_timer += 1;
            }
            character->setState(state);
        }

        else {
            if(isFliped) step = new DirectionVector(-jumpSpeed, 0);
            else step = new DirectionVector(jumpSpeed, 0);
            gameObject->move(step);
            delete step;
        }
    }




        //LOGICA DE GOLPES
    if(direction -> isEqual(WEAK_PUNCH) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
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
            enemyController->Kicked(WEAK);
        }
    }

    if(direction -> isEqual(STRONG_PUNCH) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
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
            enemyController->Kicked(STRONG);
        }
    }

    if(direction -> isEqual(WEAK_KICK) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
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
            enemyController->Kicked(WEAK);
        }
    }

    if(direction -> isEqual(STRONG_KICK) and !punching and !guarding and !strongPunching and !alreadyPunchInAir and !kicked and !defeated and !throwing and !grab and !grabbed and !grabbedImpact) {
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
            enemyController->Kicked(STRONG);
        }
    }


    //

    if (movingRight and characterIsntInRightBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {

        state = "walk";

        direction->setX(speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (movingLeft and characterIsntInLeftBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and
        !direction->isEqual(GETTINGUP) and !collision and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {

        state = "walk";

        direction->setX(-speedCharacter);
        logger->LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (direction->isDiagonalRight() and !inAir and !crowchedDown and !punching and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) jumpRight = true;
    if (direction->isDiagonalLeft() and !inAir and !crowchedDown and !punching and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) jumpLeft = true;
    if (direction->isEqual(UP) and !inAir and !crowchedDown and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {
        logger->Log("El personaje " + character->getName() + " salto.", DEBUG, "");
        jump = true;
    }

    if (direction->isEqual(DOWN) and !inAir and !punching and !guarding and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {
        state = "crowchedDown";
    }

    if (direction->isEqual(GETTINGUP) and !inAir and !punching and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) gameObject->stayInFloor();


    if (jump) {

        if(!punching and !guarding and !strongPunching and !kicked and !defeated) state = "jump";
        inAir = true;
        DirectionVector *step = new DirectionVector(0, -jumpSpeed);

        if (jumpRight and characterIsntInRightBoundary) step->setX(jumpSpeed / 2);
        if (jumpLeft and characterIsntInLeftBoundary) step->setX(-jumpSpeed / 2);

        gameObject->move(step);

        bool characterTopOfJump = info[1] <= jumpDistance;
        if (characterTopOfJump and !defeated) jump = false;

        delete step;
    }

    if (!jump and inAir and !leaving and !grabbed) {

        if(!punching and !guarding and !strongPunching and !kicked and !defeated) state = "jump";

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

    if (direction->isEqual(CHANGECHARACTER) and !inAir and mate_life != 0) {
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
        characterIsntInLeftBoundary and !punching and !strongPunching and !kicked and !throwing and !grab and !grabbed and !grabbedImpact) {

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

    throwing = false;
    projectile_flying = false;

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

void ControllerCharacter::Grabbed(){

    grabbed = true;
    state = "grabbed";
    character->setState(state);
}

void ControllerCharacter::Kicked(int force) {

    if(!guarding){

        kicked = true;
        kicked_timer = 0;

        if(state == "crowchedDown"){
            state = "downKicked";
        }else if(inAir){
            state = "airKicked";
        }else state = "standKicked";

        if (force == WEAK) {
            life -= weak_strike_dmg;
            if (life <= 0) {
                life = 0;
                defeated = true;
            }
        }

        if (force == STRONG) {
            life -= strong_strike_dmg;
            if (life <= 0) {
                life = 0;
                defeated = true;
            }
        }
        throwing = false;
    }else {
        if (force == WEAK) {
            life -= weak_strike_dmg/3;
            if (life <= 0) {
                life = 0;
                defeated = true;
            }
        }

        if (force == STRONG) {
            life -= strong_strike_dmg/3;
            if (life <= 0) {
                life = 0;
                defeated = true;
            }
        }
    }

    dynamic_cast<Character_server *>(gameObject)->setState(state);

    if(strcmp(gameMode, "training") == 0) life = 100;
}

int ControllerCharacter::getLife() {
    return life;
}

void ControllerCharacter::resetLife() {

    life = 100;
    defeated = false;
    jump = false;
    projectile_flying = false;
    throwing = false;
}

void ControllerCharacter::resetPosition(bool initialFlip) {

    dynamic_cast<Character_server *>(gameObject)->resetPosition(initialFlip);
    state = "still";
    dynamic_cast<Character_server *>(gameObject)->setState(state);
}

char ControllerCharacter::getCode() {

    return dynamic_cast<Character_server *>(gameObject)->getCode();
}

void ControllerCharacter::setGameMode(const char *gameMode) {

    this->gameMode = gameMode;
}

bool ControllerCharacter::projectileIsFlying() {
    return projectile_flying;
}

bool ControllerCharacter::projectileIsFlip() {

    return projectile->getFlip() == SDL_FLIP_HORIZONTAL;
}

vector<int> ControllerCharacter::getProjectilePosition() {

    return projectile->getPosInfo();
}

void ControllerCharacter::moveProjectile(DirectionVector *dir) {

    if(projectile_flying) projectile->move(dir);
}
