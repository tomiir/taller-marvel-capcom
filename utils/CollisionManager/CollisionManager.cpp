//
// Created by arielpm on 30/05/19.
//

#include "CollisionManager.h"


CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() = default;




bool checkCollision(SDL_Rect C1, SDL_Rect C2){

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

    cout << "botc1: " << bottomC1 << ", topc2: " << topC2 << endl;
    cout << "botc2: " << bottomC2 << ", topc1: " << topC1 << endl;
    cout << "leftc1: " << leftC1 << ", rightc2: " << rightC2 << endl;
    cout << "leftc2: " << leftC2 << ", rightc1: " << rightC1 << endl;
    return !(bottomC1 <= topC2 or bottomC2 <= topC1 or rightC1 <= leftC2 or rightC2 <= leftC1);
}

bool CollisionManager::Collisioning(GameObject_server *character1, GameObject_server *character2) {

    vector<SDL_Rect> C1 = dynamic_cast<Character_server*>(character1)->getHitboxInfo();
    vector<SDL_Rect> C2 = dynamic_cast<Character_server*>(character2)->getHitboxInfo();

    bool collision = false;

    for(auto hitboxC1 : C1){
        for(auto hitboxC2 : C2) {
            collision = checkCollision(hitboxC1, hitboxC2);
            cout << "La colision es: " << collision << endl;
            if(collision) return true;
        }
    }
    return collision;
}



