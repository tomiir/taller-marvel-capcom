#ifndef TALLER_MARVEL_CAPCOM_BACKGROUNDSCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_BACKGROUNDSCONTROLLER_H

#include "../Controller/ControllerBackground/ControllerBackground.h"

using namespace std;

class BackgroundsController {

private:

    vector< ControllerBackground* > backgrounds;
    int maxWidth = 0;
    int minWidth = 0;
    int minHeight = 0;
    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    double jumpSpeed = 10;
    SDL_Rect camera;

    DirectionVector* RIGHT = new DirectionVector(1, 0);
    DirectionVector* LEFT = new DirectionVector(-1, 0);

    vector< ControllerBackground* >::iterator itr = backgrounds.begin();

    void widthVeluesRefresh();


public:

    BackgroundsController() = default;
    ~BackgroundsController() = default;

    void addBackgroundController( ControllerBackground* background );

    void render();

    bool canMove( DirectionVector* direction, ControllerCharacter* character, vector<int> infoCharacter );



};


#endif //TALLER_MARVEL_CAPCOM_BACKGROUNDSCONTROLLER_H
