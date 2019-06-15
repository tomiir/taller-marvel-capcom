//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANHITBOXMANAGER_H


#include "../HitboxManager.h"

class SpiderManHitboxManager : public HitboxManager{

public:
    SpiderManHitboxManager();
    ~SpiderManHitboxManager() = default;

    void setHitboxes(string state, bool hFlip, SDL_Rect spriteRect, SDL_Rect spriteRectFlip) override ;

    void setInitialPos(int x, int y) override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANHITBOXMANAGER_H
