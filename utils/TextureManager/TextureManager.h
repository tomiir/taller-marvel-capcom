//
// Created by fer on 25/03/19.
//

#ifndef TRABAJOPRACTICOTALLER_TEXTUREMANAGER_H
#define TRABAJOPRACTICOTALLER_TEXTUREMANAGER_H

#include "Game.h"
#include <iostream>

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);

};


#endif //TRABAJOPRACTICOTALLER_TEXTUREMANAGER_H
