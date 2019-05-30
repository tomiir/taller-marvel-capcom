//
// Created by arielpm on 30/05/19.
//

#include "CollisionManager.h"


CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() = default;


bool CollisionManager::Collisioning(GameObject_server *character1, GameObject_server *character2) {

    SDL_Rect C1 = dynamic_cast<Character_server*>(character1)->getHitboxInfo();
    SDL_Rect C2 = dynamic_cast<Character_server*>(character2)->getHitboxInfo();

    int leftC1, leftC2;
    int rightC1, rightC2;
    int topC1, topC2;
    int bottomC1, bottomC2;

    leftC1 = C1.x;
    rightC1 = C1.x + C1.w;
    topC1 = C1.y;
    bottomC1 = C1.y + C1.h;

    leftC2 = C2.x;
    rightC2 = C2.x + C2.w;
    topC2 = C2.y;
    bottomC2 = C2.y + C2.h;

    if( bottomC1 <= topC2 )
    {
        return false;
    }

    if( topC1 >= bottomC2 )
    {
        return false;
    }

    if( rightC1 <= leftC2 )
    {
        return false;
    }

    if( leftC1 >= rightC2 )
    {
        return false;
    }

    return true;
}



