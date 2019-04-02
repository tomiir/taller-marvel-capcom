//
// Created by fer on 25/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEXTUREMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEXTUREMANAGER_H

//#include "../../model/Game/Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* path, SDL_Renderer* renderer);

};


#endif //TALLER_MARVEL_CAPCOM_TEXTUREMANAGER_H
