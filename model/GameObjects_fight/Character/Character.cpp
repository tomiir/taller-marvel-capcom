//
// Created by fer on 26/03/19.
//

#include "Character.h"
#include <string.h>


Character::Character(const char* imagePath, int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialY, string name, double size, Character* projectile_) :
           GameObject(imagePath, name, z_index, rend, 0, initialY, 0, 0) {

    spriteManager = spriteManager_;
    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->size = size;
    state = "still";
    projectile = projectile_;

    this->name = name;

    if (name == "CaptainAmerica"){
        auxY = 196;
        auxLeft = 234;
        auxRight = 372;
    }
    if (name == "SpiderMan"){
        auxY = 307;
        auxLeft = 428;
        auxRight = 528;
    }
    if (name == "ChunLi"){
        auxY = 240;
        auxLeft = 421;
        auxRight = 397;
    }
    if (name == "Venom"){
        auxY = 227;
        auxLeft = 578;
        auxRight = 529;
    }
    if (name == "projectileCA"){
        auxY = 270;
        auxLeft = 234;
        auxRight = 372;
    }
    if (name == "projectileSM"){
        auxY = 370;
        auxLeft = 428;
        auxRight = 528;
    }
    if (name == "projectileCL"){
        auxY = 230;
        auxLeft = 410;
        auxRight = 397;
    }
    if (name == "projectileV"){
        auxY = 270;
        auxLeft = 578;
        auxRight = 529;
    }


}

Character::~Character() = default;


void Character::render() {

    SDL_Rect sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * size);
    objRect.h = (int) (sprite.h * size);
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, 0.0, nullptr, flip);

//    SDL_Rect hitbox = getHitbox();
//
//    SDL_SetRenderDrawColor(renderer, 0,255,0,255);
//    SDL_RenderDrawRect(renderer, &hitbox);

    if(projectile_flying) projectile->render();

}


void Character::setState(string state) {

    spriteManager->setState(state);
    audioManager->setState(state);
    this->state = state;
}

void Character::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
}


void Character::changePosition(int changeX, int changeY) {

    if (flip == SDL_FLIP_NONE){
        objRect.x = changeX - auxLeft;
    }else objRect.x = changeX - auxRight;

    objRect.y = changeY - auxY;

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
           hitbox = SDL_Rect{objRect.x + 273, objRect.y + 200, 150, 260};
       }
       else if (state == "walk"){
           hitbox = SDL_Rect{objRect.x + 273 , objRect.y + 200, 123, 278};
       }
       else if (state == "jump"){
           hitbox = SDL_Rect{objRect.x + 260, objRect.y + 200, 130, 203};
       }
       else if (state == "crowchedDown"){
           hitbox = SDL_Rect{objRect.x + 260 , objRect.y + 280, 183, 185};
       }
    }

    if(name == "Venom"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x, objRect.y, 310, 250};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x, objRect.y - 45, 270, 295};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x, objRect.y, 295, 170};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 20, objRect.y + 50, 250, 200};
        }
    }

    if(name == "SpiderMan"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x + 20, objRect.y, 223, 240};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x + 20 , objRect.y, 240, 240};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x + 20, objRect.y, 207, 167};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x + 20, objRect.y + 110, 238, 130};
        }
    }

    if(name == "ChunLi"){

        if (state == "still"){
            hitbox = SDL_Rect{objRect.x, objRect.y, 170, 217};
        }
        else if (state == "walk"){
            hitbox = SDL_Rect{objRect.x, objRect.y, 200, 217};
        }
        else if (state == "jump"){
            hitbox = SDL_Rect{objRect.x, objRect.y, 190, 185};
        }
        else if (state == "crowchedDown"){
            hitbox = SDL_Rect{objRect.x, objRect.y + 42, 195, 175};
        }
    }

    return hitbox;
}

void Character::setAudioManager(AudioManager *audioManager) {
    this->audioManager = audioManager;
}

void Character::flipProjectileSprite(SDL_RendererFlip flip) {

    projectile->flipSprite(flip);
}

void Character::changeProjectilePosition(int pos_x, int pos_y) {

    projectile->changePosition(pos_x, pos_y);
}

void Character::setProjectileState(char state) {

    if (state == '0') projectile_flying = false;
    else projectile_flying = true;
}
