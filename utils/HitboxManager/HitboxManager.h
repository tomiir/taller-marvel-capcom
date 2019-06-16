//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_HITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_HITBOXMANAGER_H

#include <SDL_rect.h>
#include <vector>
#include <map>
#include "../Vector2D/DirectionVector.h"

using namespace std;

class HitboxManager {

public:

    HitboxManager();
    ~HitboxManager();

    void move(DirectionVector* direction);
    void setHitboxes(string state, bool horizontalFlip, SDL_Rect spriteRect, SDL_Rect spriteRectFlip);

    virtual void setInitialPos(int x, int y);
    vector<SDL_Rect> getCurrentHitboxes();
    void stayInFloor(int initialY);
    void updateHitboxes(bool flipH);

protected:

    string currentState;
    vector<SDL_Rect> currentHitboxes;

    map<string, vector<SDL_Rect>> stateHitBoxes;
    map<string, vector<SDL_Rect>>::iterator stateIterHitboxes = stateHitBoxes.begin();


};


#endif //TALLER_MARVEL_CAPCOM_HITBOXMANAGER_H
