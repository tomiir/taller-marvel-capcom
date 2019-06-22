//
// Created by arielpm on 16/05/19.
//

#include "Character_server.h"

Character_server::Character_server(int initialY, std::string name, int width, int height, HitboxManager* hitbox_, int wSprite, int hSprite, Character_server* projectile_) :
        GameObject_server(name, 0, initialY, width, height) {

    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->state = "still";
    hitbox = hitbox_;
    this->name = name;
    this->wSprite = int( wSprite * 2.5);
    this->hSprite = int( hSprite * 2.5);
    projectile = projectile_;

}

Character_server::~Character_server() = default;

void Character_server::move(DirectionVector* direction){
    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;

    hitbox->move(direction);
}

vector<int> Character_server::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character_server::spriteCoordinates(){

    if (name == "CaptainAmerica"){
        xPos = objRect.x - 234;
        xPosFlip = objRect.x - 372;
        yPos = objRect.y - 196;
    }
    if (name == "SpiderMan"){
        xPos = objRect.x - 428;
        xPosFlip = objRect.x - 528;
        yPos = objRect.y - 307;
    }
    if (name == "ChunLi"){
        xPos = objRect.x - 421;
        xPosFlip = objRect.x - 397;
        yPos = objRect.y - 240;
    }
    if (name == "Venom"){
        xPos = objRect.x - 578;
        xPosFlip = objRect.x - 529;
        yPos = objRect.y - 227;
    }
}

void Character_server::setState(string state) {

    this->state = state;

    spriteCoordinates();
    spriteRect = SDL_Rect{xPos, yPos, wSprite, hSprite};
    spriteRectFlip = SDL_Rect{xPosFlip, yPos, wSprite, hSprite};

    hitbox->setHitboxes(state, horizontalFlip, spriteRect, spriteRectFlip );  // pongo con estos dos poque por ahora estan estos dos solos
}

void Character_server::stayInFloor() {

    objRect.y = initialY;
    spriteCoordinates();
    hitbox->stayInFloor(yPos);
}


void Character_server::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;
}

void Character_server::setInitialXPositions(int positionLeft, int positionRight){
    posInitialLeft = positionLeft;
    posInitialRight = positionRight;
}

void Character_server::setInitialPos(bool left){

    if (left){
        objRect.x =  posInitialLeft;
        spriteCoordinates();
        hitbox->setInitialPosH(xPos, yPos, left);

        initialX = posInitialLeft;
    }
    else{
        objRect.x = posInitialRight;
        spriteCoordinates();
        hitbox->setInitialPosH(xPosFlip, yPos, !left);

        initialX = posInitialRight;
    }
}

void Character_server::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
    horizontalFlip = flip == SDL_FLIP_HORIZONTAL;
}

vector<int> Character_server::getPosInfo() {

    vector<int> positions = {objRect.x, objRect.y};

    return positions;
}

string Character_server::getState() {
    return state;
}

SDL_RendererFlip Character_server::getFlip() {
    return flip;
}

vector<SDL_Rect> Character_server::getHitboxInfo() {
    return hitbox->getCurrentHitboxes();
}

void Character_server::resetPosition(bool initialFlip) {

    objRect.x = initialX;
    objRect.y = initialY;

    if(initialFlip) flip = SDL_FLIP_NONE;
    else flip = SDL_FLIP_HORIZONTAL;
}

char Character_server::getCode() {

    if (name == "CaptainAmerica"){
        return 'a';
    }
    else if (name == "SpiderMan"){
        return 's';

    }
    else if (name == "ChunLi"){
        return 'c';

    }
    else if (name == "Venom"){
        return 'v';

    }
}

Character_server *Character_server::getProjectile() {
    return projectile;
}
