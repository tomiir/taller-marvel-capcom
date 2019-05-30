//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../utils/Mapper/Mapper_fight/Mapper_fight.h"
#include "../../../model/GameObjects_fight/Character/Character.h"
#include "../../../Server/Character_server/Character_server.h"
#include "../../../utils/CollisionManager/CollisionManager.h"

using namespace std;

class ControllerCharacter : public Controller{


public:
    ControllerCharacter(GameObject_server *gameObject, int screenWidth_, int screenHeight_, int speedCharacter_, int speedCharacter);
    ~ControllerCharacter();
    void handleEvent(string event, GameObject_server* enemy);
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();
    void setInitialPos(bool left);
    void move(DirectionVector *pVector);
    void changePosition(int changeX, int changeY);
    bool isInAir();
    void gone();
    void entry();
    bool isChanging();
    bool isMovingRight();
    bool isMovingLeft();
    void flip(SDL_RendererFlip flip);

    vector<int> getPosInfo();

    string getState();

    SDL_RendererFlip getFlip();

    GameObject_server *getGameObject();

private:

    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft, leaving, entering, crowchedDown, movingRight, movingLeft, moving;
    string state = "still";
    CLogger* logger = CLogger::GetLogger();
    Character_server* character = dynamic_cast<Character_server*>(gameObject);
    CollisionManager* collisionManager;
};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
