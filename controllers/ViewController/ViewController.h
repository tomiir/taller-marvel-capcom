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

    ViewController();
    virtual ~ViewController();
    virtual void handleEvent(string event);
    virtual bool end();
    virtual string getNextView();

protected:
    std::vector<ControllerBackground*> backgrounds;
};



#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
