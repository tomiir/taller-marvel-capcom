
#ifndef TRABAJOPRACTICOTALLER_GAMEOBJECT_H
#define TRABAJOPRACTICOTALLER_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>

class GameObject {

public:
        GameObject(const char* folderPath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh);
        ~GameObject();

        virtual void move(std::vector<int> &dir);
        void render();

protected:

        int posX;
        int posY;
        int width;
        int heigh;

        SDL_Texture* objTexture;
        SDL_Renderer* renderer;
        SDL_Rect objRect;

};


#endif //TRABAJOPRACTICOTALLER_GAMEOBJECT_H
