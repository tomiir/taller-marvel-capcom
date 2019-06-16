//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H


#include <SDL_render.h>
#include "../GameObject_server/GameObject_server.h"
#include "../../utils/Logger/Logger.h"
#include "../../utils/HitboxManager/HitboxManager.h"

using namespace std;

class Character_server : public GameObject_server {

public:
    Character_server(int initialY, string name, int width, int height, HitboxManager* hitbox_, int wSprite, int hSprite);
    ~Character_server();

    void move(DirectionVector* direction) override ;
    vector<int> getInfo() override ;
    void setState(string state);
    void stayInFloor() override ;
    void changePosition(int changeX, int changeY);
    void setInitialXPositions(int positionLeft, int positionRight);
    void setInitialPos(bool left);
    string name;
    void flipSprite(SDL_RendererFlip flip);
    vector<int> getPosInfo() override;
    string getState();
    SDL_RendererFlip getFlip();
    vector<SDL_Rect> getHitboxInfo();

    bool getHorizontalFlip();

private:

    int initialY;
    CLogger* logger = CLogger::GetLogger();
    int posInitialLeft;
    int posInitialRight;
    string state;
    SDL_RendererFlip flip;
    bool horizontalFlip = false;
    int wSprite, hSprite;
    int xPos = 0, yPos = 0, xPosFlip = 0;
    SDL_Rect spriteRect, spriteRectFlip;

    HitboxManager* hitbox;

};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_SERVER_H
