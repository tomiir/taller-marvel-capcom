#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_H


#include "../GameObject/GameObject.h"
#include "../../../utils/TextureManager/TextureManager.h"
#include "../../../utils/SpriteManagers/SpriteManager.h"
#include "../../../utils/Logger/Logger.h"
#include "../../../utils/AudioManager/AudioManager.h"
#include <string.h>

using namespace std;


class Character : public GameObject {

public:
    Character(const char* imagePath, int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialY, string name, double size, Character* projectile_);
    ~Character();

    void render() override ;
    void setState(string state);
    void flipSprite(SDL_RendererFlip flip);
    void changePosition(int changeX, int changeY);
    void setInitialXPositions(int positionLeft, int positionRight);
    void setInitialPos(bool left);
    void setAudioManager(AudioManager* audioManager);
    string name;
    void flipProjectileSprite(SDL_RendererFlip flip);
    void changeProjectilePosition(int pos_x, int pos_y);
    void setProjectileState(char state);

private:
    SpriteManager* spriteManager;
    AudioManager* audioManager;

    SDL_RendererFlip flip;
    int initialY, auxLeft, auxRight, auxY;
    CLogger* logger = CLogger::GetLogger();
    double size;
    int posInitialLeft;
    int posInitialRight;
    string state;
    Character* projectile;

    SDL_Rect getHitbox();

    bool projectile_flying = false;
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
