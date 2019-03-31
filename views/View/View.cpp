//
// Created by trocchi on 3/31/19.
//

#include <iostream>
#include "View.h"
#include "../../Clases/Character.h"
#include "../../Clases/Background.h"

using namespace std;

View::View(char* viewId, SDL_Renderer* renderer) {
    // cargar data de json usando ID, quizas habría que pasarle el json manager o lo que sea
    Character* character = new Character("Images/capComSprites/capCom_walk_1.png", renderer, 400, 300, 50, 120);
    Background* sky = new Background("Images/Backgrounds/Sky.png", renderer, 0, 0, 800, 600, 10 );
    Background* buildings = new Background("Images/Backgrounds/Buildings.png", renderer, 0, 0, 800, 600, 20);
    Background* street = new Background("Images/Backgrounds/Street.png", renderer, 0, 0, 800, 600, 40);
    this -> objects = {sky,buildings,street,character};
    objectCount = 4;
    this->renderer = renderer;
};

View::~View() = default;

void View::render() {
    SDL_RenderClear(renderer);
    for(int i = 0; i < objectCount; i++) {
        GameObject* object = objects[i];
        object->render();
    }
    SDL_RenderPresent(renderer);
}

std::vector<int> View::mapEventToValue(SDL_Event event, std::vector<int> &dir){
    switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
            dir[0]++;
            break;
        case SDLK_LEFT:
            dir[0]--;
            break;
        case SDLK_UP:
            dir[1]++;
            break;
        case SDLK_DOWN:
            dir[1]--;
            break;
        default:
            break;
    }
    if(event.type == SDL_KEYUP){
        dir[1]*= -1;
    };
    return dir;
}

void View::handleEvent(SDL_Event event) {
    std::vector<int> dir = {0,0};
    dir = this->mapEventToValue(event, dir);
    for(int i = 0; i < objectCount; i++) {
        GameObject* object = objects[i];
        // Habría que tener una referencia a los controllers en vez de a los GO directo
        // para que se actualice el modelo
        object->move(dir);
    }
}