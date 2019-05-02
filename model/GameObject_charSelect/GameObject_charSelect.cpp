//
// Created by magali on 01/05/19.
//

#include "GameObject_charSelect.h"

GameObject_charSelect::GameObject_charSelect(const char* folderPath, std::string name, int z_index, SDL_Renderer *rend, std::vector<int> posc){
    renderer = rend;
    this->posc = posc;
    // posc =  initialX, initialY, width, height
    if (strcmp(name.c_str(), "background")==0){
        objRect_source = SDL_Rect{posc[0], posc[1], posc[2], posc[3]};
        objRect_dest = SDL_Rect{0, 0, posc[2], posc[3]};
    }
    else{
        objRect_source = SDL_Rect{0, 0, posc[2], posc[3]};
        objRect_dest = SDL_Rect{posc[0], posc[1], posc[2], posc[3]};
    }


    objTexture = TextureManager::LoadTexture(folderPath, renderer);
    this->z_index = z_index;
    this->name = name;

}

void GameObject_charSelect::setPosc(std::vector<int> posc){
    this->posc = posc;
    objRect_dest = SDL_Rect{posc[0], posc[1], posc[2], posc[3]};

}

int GameObject_charSelect:: getZIndex(){
    return z_index;
}

std::string GameObject_charSelect:: getName(){
    return name;
}
void GameObject_charSelect::render() {

    SDL_RenderCopy(renderer, objTexture, &objRect_source, &objRect_dest);
}