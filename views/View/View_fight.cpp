//
// Created by arielpm on 16/05/19.
//

#include <algorithm>
#include "View_fight.h"

View_fight::View_fight(SDL_Renderer *renderer_) : View(renderer_) {

}

View_fight::~View_fight() = default;

struct Comp {
    bool operator()(Renderable *&renderable1, Renderable *&renderable2) {
        return renderable1->getZIndex() > renderable2->getZIndex();
    }
};

void View_fight::updateView() {
    // Primero renderizo (limpio) la vista;

    this->render();
    std::vector<Renderable*> renderables;

    // Luego renderizo los elementos que la componen


    for (std::vector<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {
        //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
        renderables.push_back((*controllerBackground));
    }

    renderables.push_back(team1);
    renderables.push_back(team2);

    Comp comp;
    std::make_heap(renderables.begin(),renderables.end(), comp);
    int size = renderables.size();
    for (int i = 0; i < size; i++){
        std::pop_heap(renderables.begin(), renderables.end(), comp);
        Renderable* rend = renderables.back();
        rend->render();
        renderables.pop_back();
    }

    SDL_RenderPresent(renderer);

}

void View_fight::addBackground(Background *background) {
    backgrounds.push_back(background);
}

bool View_fight::end() {
    return false;
}

string View_fight::getNextView() {
    return "todavia_no_existe";
}

void View_fight::addCharacter(Character * character) {
    characters.push_back(character);
}

void
View_fight::updateBackgrounds(char *posFloor_x, char *posFloor_y, char *posMoon_x, char *posMoon_y, char *posGalaxy_x,
                             char *posGalaxy_y) {

    int floor_x = atoi(posFloor_x);
    int floor_y = atoi(posFloor_y);
    int moon_x = atoi(posMoon_x);
    int moon_y = atoi(posMoon_y);
    int galaxy_x = atoi(posGalaxy_x);
    int galaxy_y = atoi(posGalaxy_y);

    backgrounds[0]->updatePos(floor_x, floor_y);
    backgrounds[1]->updatePos(moon_x, moon_y);
    backgrounds[2]->updatePos(galaxy_x, galaxy_y);

}

void View_fight::updateCharacters(char *posT1_x, char *posT1_y, char stateT1, char flip1, char currentCharT1, char *posT2_x, char *posT2_y,
                                  char stateT2, char flip2, char currentCharT2) {


}

Character* View_fight::getCharacter(string name){

    if (name == "CaptainAmerica") return characters[0];
    else if(name == "ChunLi") return characters[1];
    else if(name == "SpiderMan") return characters[2];
    else if(name == "Venom") return characters[3];
    else return NULL;// LOGGEAR ESTE ERROR
}


void View_fight::setTeams(vector<string> team1_, vector<string> team2_) {

    team1[0] = getCharacter(team1_[0]);
    team1[1] = getCharacter(team1_[1]);
    team2[0] = getCharacter(team2_[0]);
    team2[1] = getCharacter(team2_[1]);

}


