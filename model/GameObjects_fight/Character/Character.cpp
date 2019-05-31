//
// Created by fer on 26/03/19.
//

#include "Character.h"
#include <string.h>


Character::Character(const char* imagePath, int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialY, string name, double size) :
           GameObject(imagePath, name, z_index, rend, 0, initialY, 0, 0) {

    spriteManager = spriteManager_;
    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->size = size;
    state = "still";

    this->name = name;
}

Character::~Character() = default;


void Character::render() {

    SDL_Rect sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * size);
    objRect.h = (int) (sprite.h * size);
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, 0.0, nullptr, flip);

    SDL_Rect hitbox = getHitbox();

    SDL_SetRenderDrawColor(renderer, 0,255,0,255);
    SDL_RenderDrawRect(renderer, &hitbox);
}


void Character::setState(string state) {

    spriteManager->setState(state);

    this->state = state;
}

void Character::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
}


void Character::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;

}

void Character::setInitialXPositions(int positionLeft, int positionRight){
    posInitialLeft = positionLeft;
    posInitialRight = positionRight;
}

void Character::setInitialPos(bool left){

    objRect.x = left ? posInitialLeft : posInitialRight;
}

SDL_Rect Character::getHitbox() {

    SDL_Rect hitbox;

    if(name == "CaptainAmerica"){

       if (state == "still"){
           hitbox = SDL_Rect{objRect.x + 6, objRect.y, 200, 277};
       }
       else if (state == "walk"){
           hitbox = SDL_Rect{objRect.x + 6, objRect.y, 145, 282};
       }
       else if (state == "jump"){
           hitbox = SDL_Rect{objRect.x + 6, objRect.y, 187, 215};
       }
       else if (state == "crowchedDown"){
           hitbox = SDL_Rect{objRect.x + 6, objRect.y + 82, 192, 195};
       }
    }

    if(name == "Venom"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 40, objRect.y + 35, 295, 257};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 40, objRect.y + 35, 315, 280};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 40, objRect.y + 35, 332, 257};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 40, objRect.y + 45 + 35, 280, 212};
        }
    }

    if(name == "SpiderMan"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 6, objRect.y, 263, 240};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 6, objRect.y, 200, 225};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 6, objRect.y, 247, 167};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 6, objRect.y + 110, 238, 130};
        }
    }

    if(name == "ChunLi"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 7, objRect.y, 201, 217};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 7, objRect.y, 162, 210};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 7, objRect.y, 130, 185};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 7, objRect.y + 42, 215, 175};
        }
    }

    return hitbox;
}
