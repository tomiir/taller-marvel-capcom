#ifndef TALLER_MARVEL_CAPCOM_CHARACTER_H
#define TALLER_MARVEL_CAPCOM_CHARACTER_H


#include "../../GameObject/GameObject.h"
#include "../../../../utils/TextureManager/TextureManager.h"
using namespace std;


class Character : public GameObject {

public:
    Character(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int height);
    ~Character();

    void move(DirectionVector* direction);
    vector<int> getInfo();
    void render();
};


#endif //TALLER_MARVEL_CAPCOM_CHARACTER_H
