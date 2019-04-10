#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_H


#include "../../GameObject/GameObject.h"
#include "../../../../utils/TextureManager/TextureManager.h"
#include "../../../../utils/SpriteManagers/SpriteManager.h"

using namespace std;


class Character : public GameObject {

public:
    Character(const char* imagePath, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialX, int initialY, int width, int height);
    ~Character();

    void move(DirectionVector* direction);
    vector<int> getInfo();
    void render();
    void setState(string state);
    void flipRight() ;
    void flipLeft() ;


private:
    SpriteManager* spriteManager;
    SDL_RendererFlip flip_status;
    double flip_angle;
    SDL_Rect sprite ;
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
