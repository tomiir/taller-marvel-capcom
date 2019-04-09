//
// Created by fer on 25/03/19.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *path, SDL_Renderer *renderer)
{
    SDL_Surface* tempSurface = IMG_Load(path);

    if(!tempSurface){
        std::cout << "Fallo carga imagen: %s" << SDL_GetError() << std::endl;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if(!texture)
    {
        std::cout << "Fallo al cargar la imagen: %s" << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_FreeSurface(tempSurface);

    return texture;

}
