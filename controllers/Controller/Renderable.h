//
// Created by magali on 14/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_RENDERABLE_H
#define TALLER_MARVEL_CAPCOM_RENDERABLE_H


class  Renderable{

public:
    virtual void render();
    Renderable() = default;
    ~Renderable() = default;
    virtual int getZIndex();
};



#endif //TALLER_MARVEL_CAPCOM_RENDERABLE_H
