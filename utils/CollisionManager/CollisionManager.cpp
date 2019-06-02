//
// Created by arielpm on 30/05/19.
//

#include "CollisionManager.h"


CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() = default;


bool CollisionManager::Collisioning(GameObject_server *character1, GameObject_server *character2) {

    vector<SDL_Rect> C1 = dynamic_cast<Character_server*>(character1)->getHitboxInfo();
    vector<SDL_Rect> C2 = dynamic_cast<Character_server*>(character2)->getHitboxInfo();

    bool collision = true;


    int leftC1, leftC2;
    int rightC1, rightC2;
    int topC1, topC2;
    int bottomC1, bottomC2;

    for(int i = 0; i < C1.size(); i++){

        SDL_Rect hitboxC1 = C1[i];

        leftC1 = hitboxC1.x;
        rightC1 = hitboxC1.x + hitboxC1.w;
        topC1 = hitboxC1.y;
        bottomC1 = hitboxC1.y + hitboxC1.h;

        for(int j = 0; j< C2.size(); j++){

            SDL_Rect hitboxC2 = C2[j];

            leftC2 = hitboxC2.x;
            rightC2 = hitboxC2.x + hitboxC2.w;
            topC2 = hitboxC2.y;
            bottomC2 = hitboxC2.y + hitboxC2.h;

            if(bottomC1 <= topC2) collision = false;
            if(topC1 >= bottomC2) collision = false;
            if(rightC1 <= leftC2) collision = false;
            if(leftC1 >= rightC2) collision = false;
        }
    }

    cout << "La colision es: " << collision << endl;
    return collision;
}



