//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_CHUNLIHITBOXMANAGER_H


#include "../HitboxManager.h"

class ChunLiHitboxManager : public HitboxManager{

public:
    ChunLiHitboxManager();
    ~ChunLiHitboxManager() = default;

    void setHitboxes(string state, bool hFlip, SDL_Rect spriteRect, SDL_Rect spriteRectFlip) override ;

    void setInitialPos(int x, int y) override ;

};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIHITBOXMANAGER_H
