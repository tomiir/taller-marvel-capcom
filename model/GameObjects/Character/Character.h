#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_H


#include "../GameObject/GameObject.h"
#include "../../../utils/TextureManager/TextureManager.h"
#include "../../../utils/SpriteManagers/SpriteManager.h"
#include "../../../utils/Logger/Logger.h"

using namespace std;


class Character : public GameObject {

public:
    Character(const char* imagePath, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialX, int initialY, int crowchedDownY_, string name);
    ~Character();

    void move(DirectionVector* direction) override ;
    vector<int> getInfo() override ;
    void render() override ;
    void setState(string state);
    void stayInFloor() override ;
    void crowchDown() override ;
    void flipSprite(SDL_RendererFlip flip);

    void changePosition(int changeX, int changeY);
    string name;

private:
    SpriteManager* spriteManager;
    SDL_RendererFlip flip;
    int initialY;
    int crowchedDownY;
    CLogger* logger = CLogger::GetLogger();
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
