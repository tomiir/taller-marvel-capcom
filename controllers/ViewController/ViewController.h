//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H


#include <vector>
#include "../Controller/ControllerBackground/ControllerBackground.h"
#include "../../views/View/View.h"

class ViewController{
public:

    ViewController(SDL_Renderer* renderer_);
    virtual ~ViewController();
    virtual void updateView();
    virtual void handleEvent();
    virtual void addBackground(ControllerBackground* controller);
    virtual bool end();
    virtual string getNextView();

protected:
    View* view;
    SDL_Renderer* renderer;
    std::vector<ControllerBackground*> backgrounds;

};



#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
