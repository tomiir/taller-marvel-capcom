
#include "CaptainAmericaStillAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 0;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaStillAnimation::CaptainAmericaStillAnimation() : Animation() {

    this->init();

}
