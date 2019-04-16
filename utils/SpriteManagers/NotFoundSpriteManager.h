//
// Created by feeer on 15/4/2019.
//

#ifndef TALLER_MARVEL_CAPCOM_NOTFOUNDSPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_NOTFOUNDSPRITEMANAGER_H


#include "SpriteManager.h"

class NotFoundSpriteManager : public SpriteManager {

public:
    NotFoundSpriteManager();
    ~NotFoundSpriteManager() = default;

    void init() override ;
};



#endif //TALLER_MARVEL_CAPCOM_NOTFOUNDSPRITEMANAGER_H
