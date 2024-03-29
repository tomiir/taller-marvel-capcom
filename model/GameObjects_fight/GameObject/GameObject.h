
#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECT_H


#include <vector>
#include "../../../utils/TextureManager/TextureManager.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../controllers/Controller/Renderable.h"
#include <string>

using namespace std;

class GameObject: virtual public Renderable{

public:
    GameObject(const char* folderPath, string name, int z_index, SDL_Renderer* rend, int initialX, int initialY, int width, int height);
    ~GameObject();

    virtual void move(DirectionVector* direction);
    virtual void render();
    virtual vector<int> getInfo();
    virtual void stayInFloor();
    int getZIndex();
    string getName();
    void setOriginRect(vector<int> position);
    void setDestinyRect(vector<int> position);

protected:
    string name;
    SDL_Texture* objTexture;
    SDL_Renderer* renderer;
    SDL_Rect objRect, objRect2;
    int z_index;
};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
