//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongAirKickAnimation.h"

void SpiderManStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 4;


    vector<int> frame0 = {0, 5092, 491, 268};
    vector<int> frame1 = {491, 5092, 491, 268};
    vector<int> frame2 = {982, 5092, 491, 268};
    vector<int> frame3 = {1473, 5092, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManStrongAirKickAnimation::SpiderManStrongAirKickAnimation() : Animation() {

    this->init();

}