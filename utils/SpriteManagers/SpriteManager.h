//
// Created by fer on 07/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_SPRITEMANAGER_H


#include "../../Animations/Animation.h"
#include <map>
#include <iostream>
#include <string.h>

using namespace std;

class SpriteManager {

public:

    SpriteManager();
    ~SpriteManager() = default;

    void setState(string state);
    virtual SDL_Rect getSprite();
    virtual void init();


protected:

    map<string, Animation*> animationMap;
    string state;
    Animation* actualAnimation;
    map<string, Animation*>::iterator itr = animationMap.begin();
    bool stateChanges(string newState);

};


#endif //TALLER_MARVEL_CAPCOM_SPRITEMANAGER_H
