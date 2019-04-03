
#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECT_H


#include <vector>
#include "../../../utils/TextureManager/TextureManager.h"

using namespace std;

class GameObject {

public:
        GameObject(const char* folderPath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh);
        ~GameObject();

        virtual void move(std::vector<int> &dir);
        virtual void render();
        virtual vector<int> getInfo();

protected:

        SDL_Texture* objTexture;
        SDL_Renderer* renderer;
        SDL_Rect objRect;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECT_H
