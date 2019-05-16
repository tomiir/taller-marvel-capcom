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

    this->view->render();
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



void View_fight::addFlipManager(FlipManager *flipManager_) {
    flipManager = flipManager_;

}

void View_fight::addBackground(Background *background) {
    backgrounds.push_back(background);
}

void View_fight::addTeams(TeamManager *teamManager1, TeamManager *teamManager2) {
    team1 = teamManager1;
    team2 = teamManager2;
}

bool View_fight::end() {
    return false;
}

string View_fight::getNextView() {
    return "todavia_no_existe";
}

void View_fight::setTeam(vector<Character *> characters, int team) {
    if (team == 1) {
        team1->setCharacters(characters);
        team1->setInitialPos(true);
    }
    else {

        team2->setCharacters(characters);
        team2->setInitialPos(false);
    }
}

void View_fight::createFlipManager() {
    flipManager->create();
}

void View_fight::addCharacter(Character * character) {
    characters.push_back(character);
}
