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

    void move(DirectionVector* direction) override ;
    vector<int> getInfo() override ;
    void render() override ;
    void setState(string state);
    void flipSprite(SDL_RendererFlip flip);

private:
    SpriteManager* spriteManager;
    SDL_RendererFlip flip;
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
