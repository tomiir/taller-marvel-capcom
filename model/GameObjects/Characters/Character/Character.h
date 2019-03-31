#ifndef TRABAJOPRACTICOTALLER_CHARACTER_H
#define TRABAJOPRACTICOTALLER_CHARACTER_H


#include "../../GameObject/GameObject.h"

class Character : public GameObject {

public:
    Character(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh);
    ~Character();

    void jump();
    void down();

};


#endif //TRABAJOPRACTICOTALLER_CHARACTER_H
