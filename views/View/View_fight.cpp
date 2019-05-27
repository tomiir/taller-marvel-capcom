//
// Created by arielpm on 16/05/19.
//

#include <algorithm>
#include "View_fight.h"

View_fight::View_fight(SDL_Renderer *renderer_) : View(renderer_) {
    currentChar1 = 0;
    currentChar2 = 0;

}

View_fight::~View_fight() = default;

struct Comp {
    bool operator()(Renderable *&renderable1, Renderable *&renderable2) {
        return renderable1->getZIndex() > renderable2->getZIndex();
    }
};

void View_fight::updateView() {
    // Primero renderizo (limpio) la vista;

    this->clearWindow();
    std::vector<Renderable*> renderables;

    // Luego renderizo los elementos que la componen


    for (std::vector<Background*>::iterator background=backgrounds.begin(); background != backgrounds.end(); ++background) {

        renderables.push_back((*background));
    }

    renderables.push_back(team1[currentChar1]);
    renderables.push_back(team2[currentChar2]);

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

string selectState(char state){

    if (state == '0') return "still";
    else if(state == '1') return "walk";
    else if(state == '2') return  "jump";
    else if(state == '3') return "crowchedDown";
    else if(state == '4') return "entering";
    else return NULL;//LOGGEAR ESTE ERROR
}

SDL_RendererFlip selectFlip(char flip){

    if (flip == '0') return SDL_FLIP_NONE;
    else if (flip == '1') return  SDL_FLIP_HORIZONTAL;
}

void View_fight::updateCharacters(char *posT1_x, char *posT1_y, char stateT1, char flip1, char currentCharT1, char *posT2_x, char *posT2_y,
                                  char stateT2, char flip2, char currentCharT2) {

    int pos1_x = atoi(posT1_x);
    int pos1_y = atoi(posT1_y);
    int pos2_x = atoi(posT2_x);
    int pos2_y = atoi(posT2_y);

    currentChar1 = currentCharT1 - '0';
    currentChar2 = currentCharT2 - '0';

    team1[currentChar1]->changePosition(pos1_x, pos1_y);
    team2[currentChar2]->changePosition(pos2_x, pos2_y);

    team1[currentChar1]->setState(selectState(stateT1));
    team2[currentChar2]->setState(selectState(stateT2));

    team1[currentChar1]->flipSprite(selectFlip(flip1));
    team2[currentChar2]->flipSprite(selectFlip(flip2));

}

Character* View_fight::getCharacter(string name){

    if (name == "CaptainAmerica") return characters[0];
    else if(name == "ChunLi") return characters[1];
    else if(name == "SpiderMan") return characters[2];
    else if(name == "Venom") return characters[3];
    else return NULL;// LOGGEAR ESTE ERROR
}


void View_fight::setTeams(Character* characterT1_1, Character* characterT1_2, Character* characterT2_1, Character* characterT2_2) {

    team1 = {characterT1_1, characterT1_2};
    team2 = {characterT2_1, characterT2_2};

    team1[0]->flipSprite(SDL_FLIP_HORIZONTAL);
    team2[0]->flipSprite(SDL_FLIP_NONE);

}


