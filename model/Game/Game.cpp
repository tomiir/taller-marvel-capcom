//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "../../utils/Logger/Logger.h"


Game::Game(int screenWidth_, int screenHeight_){

    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

Game::~Game() = default;

void Game::init(const char *title, int posX, int posY) {

    CLogger* logger = CLogger::GetLogger();

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

        factory = new ViewFactory(renderer, screenWidth, screenHeight);


        // Mando viewFight pq es la unica que tenemos. Deberiamos mandar la primera, y luego, las ViewController conocerse entre
        // si para saber quien va luego o implementar el VIEW MANAGER

        views["fight"] = factory -> getView_fight();
        characters = factory -> getCharacter();
        views["char_select"] = factory -> getView_charSelect();

        view = (views.find("char_select"))->second;

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

//void Game::tick() {
//
//    this->view->handleEvent();
//
//
//    update(); // Esto se va a usar para reconciliar data con el serve supongo. Tipo le envío el movimiento, espero resp.
//    this->view->updateView();
//
//    if (this->view->end()) {
//
//        string nextViewName = (this->view)->getNextView();
//        View* nextView = views.find(nextViewName)->second;
//
//        if (strcmp(nextViewName.c_str(), "fight") == 0){
//            // esto significa que la anterior fue la de selección de personajes;
//            vector<string> team1 = ((View_charSelect*) view)-> getTeam1();
//            vector<string> team2 = ((View_charSelect*) view) -> getTeam2();
//
//            vector<ControllerCharacter*> aux = {(characters.find(team1[0])->second), (characters.find(team1[1])->second)};
//            ((ViewController_fight*)nextView)->setTeam(aux,1);
//
//            aux =  {(characters.find(team2[0])->second), (characters.find(team2[1])->second)};
//            ((ViewController_fight*)nextView)->setTeam(aux,2);
//
//            ((ViewController_fight*)nextView)->createFlipManager();
//        }
//        this->view = nextView;
//    }
//
//}

View *Game::getView() {
    return this->view;
}

void Game::updateGreySquares(char* greySquares) {

    this->view->updateGreySquares(greySquares);
}

void Game::updateSelects(char *selectT1, char *selectT2) {
    this->view->updateSelects(selectT1, selectT2);
}

void Game::updateCharactersImages(char *selected_1, char *selected_2) {
    this->view->updateCharacterImages(selected_1, selected_2);
}

void Game::render() {
    this->view->updateView();
}

bool Game::haveToChangeView() {
    return this->view->end();
}

void Game::changeView() {
    string nextViewName = (this->view)->getNextView();
    View* nextView = views.find(nextViewName)->second;
    this->view = nextView;
}

void Game::UpdateBackgrounds(char *posFloor_x, char *PosFloor_y, char *posMoon_x, char *posMoon_y, char *posGalaxy_x,
                             char *posGalaxy_y) {

}

