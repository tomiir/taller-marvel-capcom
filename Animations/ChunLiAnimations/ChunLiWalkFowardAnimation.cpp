//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkFowardAnimation.h"
#include <SDL_timer.h>

void ChunLiWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 12;

    vector<int> frame0 = {0, 210, 407, 210};
    vector<int> frame1 = {407, 210, 407, 210};
    vector<int> frame2 = {814, 210, 407, 210};
    vector<int> frame3 = {1221, 210, 407, 210};
    vector<int> frame4 = {1628, 210, 407, 210};
    vector<int> frame5 = {2035, 210, 407, 210};
    vector<int> frame6 = {2442, 210, 407, 210};
    vector<int> frame7 = {2035, 210, 407, 210};
    vector<int> frame8 = {1628, 210, 407, 210};
    vector<int> frame9 = {1221, 210, 407, 210};
    vector<int> frame10 = {814, 210, 407, 210};
    vector<int> frame11 = {407, 210, 407, 210};




    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame9);
    animation.push_back(frame10);
    animation.push_back(frame11);


}

ChunLiWalkFowardAnimation::ChunLiWalkFowardAnimation() : Animation() {

    this->init();

}