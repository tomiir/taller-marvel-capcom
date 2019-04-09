//
// Created by fer on 06/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_ANIMATION_H
#define TALLER_MARVEL_CAPCOM_ANIMATION_H


#include <SDL_render.h>
#include <vector>
#include <tiff.h>

using namespace std;

class Animation {

protected:

    vector< vector<int> > animation = {};
    virtual void init();
    int index = 0;
    int animationLength, animationRate;
    Uint32 startTime ;


public:

    Animation();
    ~Animation();

    void resetIndex();

    vector<int> play();

};


#endif //TALLER_MARVEL_CAPCOM_ANIMATION_H
