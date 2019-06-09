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

    if (name == "CaptainAmerica"){
        auxY = 205;
        auxLeft = 237;
        auxRight = 411;
    }
    if (name == "SpiderMan"){
        auxY = 307;
        auxLeft = 424;
        auxRight = 527;
    }
    if (name == "ChunLi"){
        auxY = 240;
        auxLeft = 423;
        auxRight = 376;
    }
    if (name == "Venom"){
        auxY = 180;
        auxLeft = 575;
        auxRight = 527;
    }


}

Character::~Character() = default;


void Character::render() {

    SDL_Rect sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * size);
    objRect.h = (int) (sprite.h * size);
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, 0.0, nullptr, flip);

    SDL_Rect hitbox = getHitbox();

    hitbox.y += auxY;
    if (flip == SDL_FLIP_NONE){
        hitbox.x += auxLeft;
    }else hitbox.x += auxRight;

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

//    if (name == "CaptainAmerica"){
//        positionLeft -= 237;
//        positionRight -= 411;
//    }
//    if (name == "SpiderMan"){
//        positionLeft -= 424;
//        positionRight -= 527;
//    }
//    if (name == "ChunLi"){
//        positionLeft -= 423;
//        positionRight -= 376;
//    }
//    if (name == "Venom"){
//        positionLeft -= 575;
//        positionRight -= 527;
//    }

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
           hitbox = SDL_Rect{objRect.x + 26, objRect.y, 160, 277};
       }
       else if (state == "walk"){
           hitbox = SDL_Rect{objRect.x + 26 + 30, objRect.y , 145, 282};
       }
       else if (state == "jump"){
           hitbox = SDL_Rect{objRect.x + 26, objRect.y, 157, 215};
       }
       else if (state == "crowchedDown"){
           hitbox = SDL_Rect{objRect.x + 26, objRect.y + 82, 162, 195};
       }
    }

    if(name == "Venom"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 65, objRect.y + 65, 245, 230};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 65, objRect.y + 65 -65, 182, 295};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 65, objRect.y + 65, 230, 170};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 65 - 65, objRect.y + 65 + 45, 280, 200};
        }
    }

    if(name == "SpiderMan"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 26, objRect.y + 40, 223, 200};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 26, objRect.y + 40, 160, 185};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 26, objRect.y + 40, 207, 167};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 26, objRect.y + 40 + 70, 238, 130};
        }
    }

    if(name == "ChunLi"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 32, objRect.y, 141, 217};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 32, objRect.y, 122, 210};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 32, objRect.y, 130, 185};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 32, objRect.y + 42, 165, 175};
        }
    }

    return hitbox;
}
