#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_H


#include "../GameObject/GameObject.h"
#include "../../../utils/TextureManager/TextureManager.h"
#include "../../../utils/SpriteManagers/SpriteManager.h"
#include "../../../utils/Logger/Logger.h"
#include <string.h>

using namespace std;


class Character : public GameObject {

public:
    Character(const char* imagePath, int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialY, string name, double size);
    ~Character();

    void render() override ;
    void setState(string state);
    void flipSprite(SDL_RendererFlip flip);
    void changePosition(int changeX, int changeY);
    void setInitialXPositions(int positionLeft, int positionRight);
    void setInitialPos(bool left);
    string name;

private:
    SpriteManager* spriteManager;
    SDL_RendererFlip flip;
    int initialY;
    CLogger* logger = CLogger::GetLogger();
    double size;
    int posInitialLeft;
    int posInitialRight;
    string state;

    SDL_Rect getHitbox();
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
