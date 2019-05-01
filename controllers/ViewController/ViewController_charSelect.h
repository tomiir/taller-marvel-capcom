//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H

#include "ViewController.h"
#include "../../utils/EventToValueMapper/EventToValueMapper_charSelect_1.h"
#include "../../utils/EventToValueMapper/EventToValueMapper_charSelect_2.h"
#include <string>
#include <stdio.h>

class ViewController_charSelect: public ViewController {
public:
    ViewController_charSelect(SDL_Renderer *renderer_);

    ~ViewController_charSelect() = default;

    void updateView() override;

    void handleEvent() override;

    void addBackground(ControllerBackground *controller) override;

    void setTeam1(string character);

    void setTeam2(string character);

private:
    int getTeam(SDL_Event event);
    std::vector<string> selected_1;
    std::vector<string> selected_2;
    std::vector<string> selected;

    EventToValueMapper_charSelect_1* mapper_1;
    EventToValueMapper_charSelect_2* mapper_2;
};

#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H
