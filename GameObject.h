
#ifndef TRABAJOPRACTICOTALLER_GAMEOBJECT_H
#define TRABAJOPRACTICOTALLER_GAMEOBJECT_H

#include <SDL2/SDL.h>

class GameObject {

public:
        GameObject(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh);
        ~GameObject();

        void place(int posX, int posY);
        void move(int increase);
        void update();
        void render();

private:

        int posX;
        int posY;
        int width;
        int heigh;

        SDL_Texture* objTexture;
        SDL_Renderer* renderer;
        SDL_Rect objRect;

};


#endif //TRABAJOPRACTICOTALLER_GAMEOBJECT_H
