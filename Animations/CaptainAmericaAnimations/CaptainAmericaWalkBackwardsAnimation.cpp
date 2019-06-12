

#include "CaptainAmericaWalkBackwardsAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 2 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }


}

CaptainAmericaWalkBackwardsAnimation::CaptainAmericaWalkBackwardsAnimation() : Animation() {

    this->init();

}