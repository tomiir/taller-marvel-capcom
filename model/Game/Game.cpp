//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "../../utils/Logger/Logger.h"

#define DEBUG_LEVEL DEBUG



Game::Game(int screenWidth_, int screenHeight_){

    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY) {

    CLogger* logger = CLogger::GetLogger();

    logger -> setLevel(DEBUG_LEVEL);
    logger ->Log("Inicializando juego", INFO, "");

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, posX, posY, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (!window) {
            logger -> Log("Fallo la creación de la ventana", ERROR, "");
        } else {
                renderer = SDL_CreateRenderer(window, -1, 0);
                if (!renderer){
                    logger -> Log("Fallo la creación del renderer", ERROR,"");
                }
            }
        isRunning = true;

        factory = new ViewControllerFactory(renderer, screenWidth, screenHeight);

        // Mando viewFight pq es la unica que tenemos. Deberiamos mandar la primera, y luego, las view conocerse entre
        // si para saber quien va luego o implementar el VIEW MANAGER

       viewController = factory->getViewController_fight();
       logger -> Log("Inicialización completa, ventana, renderer y vista creados correctamente", INFO, "");

    } else {
            logger -> Log("Fallo la creación del renderer", ERROR, "");
            isRunning = false;
        }
}

void Game::update(){

}

void Game::clean(){
    CLogger* logger = CLogger::GetLogger();

    SDL_DestroyWindow(window);
    logger -> Log("Ventana destruida", INFO, "");

    SDL_DestroyRenderer(renderer);
    logger -> Log("Renderer destruido", INFO, "");

    SDL_Quit();

}

void Game::tick() {
    this -> viewController -> handleEvent();
    update(); // Esto se va a usar para reconciliar data con el serve supongo. Tipo le envío el movimiento, espero resp.
    this -> viewController -> updateView();
}
