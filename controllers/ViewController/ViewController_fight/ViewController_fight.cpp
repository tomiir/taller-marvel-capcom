//
// Created by trocchi on 3/31/19.
//

#include "ViewController_fight.h"
#include <algorithm> // for heap operations

#include <SDL2/SDL.h>

#include "../../../utils/Logger/Logger.h"

ViewController_fight::ViewController_fight(SDL_Renderer* renderer_):ViewController(renderer_) {
}

ViewController_fight::~ViewController_fight() = default;


void ViewController_fight::addBackground(ControllerBackground* controller) {

    backgrounds.push_back(controller);
}


void ViewController_fight::handleEvent() {

    CLogger* logger = CLogger::GetLogger();

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        logger -> Log("Saliendo del juego", INFO, "");
        throw -1;
    }
// MODIFICAR EL HANDLEEVENT!
    try {
        if(event.key.state != SDL_RELEASED) {
            //logger -> Log("Manejando el evento: " + to_string(event.type), DEBUG, "");
        }
        team1->handleEvent(event, backgrounds);
        team2->handleEvent(event, backgrounds);
        flipManager->update();
    } catch(exception e) {
        logger -> Log("Falló al querer manejar un evento", ERROR, e.what());
        logger -> Log("Falló al querer manejar el evento: " + to_string(event.type), DEBUG, e.what());
        throw -1;
    }
}

struct Comp{
    bool operator()(Renderable*& renderable1, Renderable*& renderable2){
        return renderable1->getZIndex() >  renderable2->getZIndex();
    }
};

void ViewController_fight::updateView() {

    //Acá debería chequear si debe cambiar de ViewController
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

void ViewController_fight::addTeams(TeamManager* teamManager1, TeamManager* teamManager2) {

    team1 = teamManager1;
    team2 = teamManager2;
}

void ViewController_fight::addFlipManager(FlipManager *flipManager_) {

    flipManager = flipManager_;

}

bool ViewController_fight::end() {
    //lo hardcodeo pq no tenemos otra view
    return false;
}

string ViewController_fight::getNextView() {
    return "todavia_no_existe";
}

