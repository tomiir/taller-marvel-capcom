//
// Created by fer on 25/03/19.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *path, SDL_Renderer *renderer)
{
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if(!texture) return nullptr;
    SDL_FreeSurface(tempSurface);

    return texture;

}
