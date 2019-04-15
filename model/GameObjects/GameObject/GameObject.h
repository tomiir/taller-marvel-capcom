
#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECT_H


#include <vector>
#include "../../../utils/TextureManager/TextureManager.h"
#include "../../../utils/Vector2D/DirectionVector.h"

using namespace std;

class GameObject {

public:
    GameObject(const char* folderPath, int z_index, SDL_Renderer* rend, int initialX, int initialY, int width, int height);
    ~GameObject();

    virtual void move(DirectionVector* direction);
    virtual void render();
    virtual vector<int> getInfo();
    virtual void stayInFloor();
    virtual void crowchDown();
    int getZIndex();

protected:
    SDL_Texture* objTexture;
    SDL_Renderer* renderer;
    SDL_Rect objRect;
    int z_index;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
