//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include "../Controller/Renderable.h"
#include <vector>
#include "../Controller/ControllerBackground/ControllerBackground.h"
#include "../../utils/TeamManager/TeamManager.h"
#include "../../utils/FlipManager/FlipManager.h"


class ViewController{
public:

    ViewController(SDL_Renderer* renderer_);
    virtual ~ViewController();
    virtual void updateView();
    virtual void handleEvent();
    virtual void addBackground(ControllerBackground* controller);
    virtual bool end();
    virtual string getNextView();

    virtual void updateGreySquares(char* greySquares);

    virtual void updateSelects(char *string, char *string1);

    virtual void updateCharacterImages(char *string, char *string1);

protected:
    View* view;
    SDL_Renderer* renderer;
    std::vector<ControllerBackground*> backgrounds;
};



#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
