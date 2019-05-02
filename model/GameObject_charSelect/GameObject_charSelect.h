//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECT_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECT_CHARSELECT_H


#include <vector>
#include "../../utils/TextureManager/TextureManager.h"
#include "SDL2/SDL.h"
#include <string>

class GameObject_charSelect {

public:
    GameObject_charSelect(const char* folderPath, std::string name, int z_index, SDL_Renderer *rend, std::vector<int> posc);
    ~GameObject_charSelect() = default;

    void setPosc(std::vector<int> posc);
    void render();
    int getZIndex();
    std::string getName();

private:
    std::vector<int> posc;
    SDL_Texture* objTexture;
    SDL_Renderer* renderer;
    SDL_Rect objRect_dest;
    SDL_Rect objRect_source;
    std::string name;
    int z_index;
};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECT_CHARSELECT_H

