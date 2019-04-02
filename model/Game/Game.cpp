//
// Created by fer on 25/03/19.
//

#include "Game.h"


int moveSpeed = 20;

Character* character;
Background* sky;
Background* street;
Background* buildings;

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY, int width, int height) {



    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, posX, posY, width, height, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cout << "Fallo la creación de la ventana" << std::endl;
        } else {
                renderer = SDL_CreateRenderer(window, -1, 0);
                if (!renderer){
                    std::cout << "Fallo la creacion del render" << std::endl;
                }
            }
        isRunning = true;

        factory= new ViewControllerFactory(renderer);
        // Mando viewFight pq es la unica que tenemos. Deberiamos mandar la primera, y luego, las view conocerse entre
        // si para saber quien va luego o implementar el VIEW MANAGER
       viewController = factory->getViewController_fight();


    } else{
            std::cout << "Fallo la inicializacion" << std::endl;
            isRunning = false;
        }
}

void Game::update(){

}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}

void Game::tick() {
    this -> viewController -> handleEvent();
    update(); // Esto se va a usar para reconciliar data con el serve supongo. Tipo le envío el movimiento, espero resp.
    this -> viewController -> updateView();
}
