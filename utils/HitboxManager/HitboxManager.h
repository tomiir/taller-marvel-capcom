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
    virtual void setHitbox(string state);

    virtual void setInitialPos(int x, int y);

    SDL_Rect getCurrentHitbox();

    void stayInFloor(int initialY);

protected:

    string currentState;
    SDL_Rect currentHitbox;

    map<string, SDL_Rect> hitBoxes;
    map<string, SDL_Rect>::iterator iterHitboxes = hitBoxes.begin();


};


#endif //TALLER_MARVEL_CAPCOM_HITBOXMANAGER_H
