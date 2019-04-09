//
// Created by fer on 25/03/19.
//

#include "Game.h"


Game::Game(int screenWidth_, int screenHeight_){

    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY) {

    CLogger* logger = CLogger::GetLogger();
    logger ->Log("Inicializando juego");

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, posX, posY, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cout << "Fallo la creación de la ventana" << std::endl;
        } else {
                renderer = SDL_CreateRenderer(window, -1, 0);
                if (!renderer){
                    std::cout << "Fallo la creacion del render" << std::endl;
                }
            }
        isRunning = true;

        factory = new ViewControllerFactory(renderer, screenWidth, screenHeight);

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
