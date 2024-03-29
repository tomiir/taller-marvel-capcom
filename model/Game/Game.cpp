//
// Created by fer on 25/03/19.
//

#include "Game.h"
#include "../../utils/Logger/Logger.h"
#include "../../views/View/View_endGame.h"
#include <unistd.h>



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


        //Aca se pone la imagen de Loading
        SDL_Rect black = SDL_Rect{0,0, screenWidth, screenHeight};

        SDL_SetRenderDrawColor(renderer, 1,1,1,255);
        SDL_RenderFillRect(renderer, &black);

        const char *folderPath = "../Images/Loading Screen/Loading.png";

        SDL_Rect  dest = SDL_Rect{(screenWidth - 800)/2, (screenHeight - 600)/2, 800, 600};
        SDL_Rect source = SDL_Rect{0, 0, 800, 600};
        SDL_Texture* loading = TextureManager::LoadTexture(folderPath, renderer);

        SDL_RenderCopy(renderer, loading, &source, &dest);

        SDL_RenderPresent(renderer);

        //---------------------------sound  intro----------------------
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8 *wavBuffer;

        SDL_LoadWAV("../Audio/Intro.wav", &wavSpec, &wavBuffer, &wavLength);
        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
        SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_PauseAudioDevice(deviceId, 0);
        //-------------------------------------------------

        //aca termina el cargado de la imagen de Loading
        factory = new ViewFactory(renderer, screenWidth, screenHeight);


        // Mando viewFight pq es la unica que tenemos. Deberiamos mandar la primera, y luego, las ViewController conocerse entre
        // si para saber quien va luego o implementar el VIEW MANAGER

        SDL_RenderCopy(renderer, loading, &source, &dest);
        SDL_RenderPresent(renderer);

        views["fight"] = factory -> getView_fight();
        characters = factory -> getCharacter();
        views["char_select"] = factory -> getView_charSelect();
        views["endGame"] = factory->getView_endGame();

        view = (views.find("char_select"))->second;
        viewAudioManager = new ViewAudioManager();

        SDL_RenderCopy(renderer, loading, &source, &dest);
        SDL_RenderPresent(renderer);

        logger -> Log("Inicialización completa, ventana, renderer y vista creados correctamente", INFO, "");

    } else {
            logger -> Log("Fallo la creación del renderer", ERROR, "");
        }
}



void Game::clean(){
    CLogger* logger = CLogger::GetLogger();

    SDL_DestroyWindow(window);
    logger -> Log("Ventana destruida", INFO, "");

    SDL_DestroyRenderer(renderer);
    logger -> Log("Renderer destruido", INFO, "");

    SDL_Quit();

}


void Game::updateGreySquares(char* greySquares) {

    dynamic_cast<View_charSelect*>(this->view)->updateGreySquares(greySquares);
}

void Game::updateSelects(char *selectT1, char *selectT2) {
    dynamic_cast<View_charSelect*>(this->view)->updateSelects(selectT1, selectT2);
}

void Game::updateCharactersImages(char *selected_1, char *selected_2) {
    dynamic_cast<View_charSelect*>(this->view)->updateCharacterImages(selected_1, selected_2);
}

void Game::render() {
    this->view->updateView();
}

bool Game::haveToChangeView() {
    return this->view->end();
}


Character *Game::getCharacter(string character){

    itr_characters = characters.find(character);
    return itr_characters->second;
}


void Game::changeView(int viewNumber) {
    string nextViewName = "";
    if(viewNumber == 1){
        vector<string> team1 =  dynamic_cast<View_charSelect*>(this->view)->getTeam1();
        vector<string> team2 =  dynamic_cast<View_charSelect*>(this->view)->getTeam2();

    nextViewName = (this->view)->getNextView();
    View* nextView = views.find(nextViewName)->second;
    this->view = nextView;

    dynamic_cast<View_fight*>(this->view)->setTeams(getCharacter(team1[0]), getCharacter(team1[1]), getCharacter(team2[0]), getCharacter(team2[1]));

    viewAudioManager->setState(nextViewName);
    }
    else if (viewNumber == 2){
        nextViewName = (this->view)->getNextView();
        View* nextView = views.find(nextViewName)->second;
        this->view = nextView;
        viewAudioManager->setState(nextViewName);
    }
}

void Game::UpdateBackgrounds(char *posFloor_x, char *posFloor_y, char *posMoon_x, char *posMoon_y, char *posGalaxy_x,
                             char *posGalaxy_y) {
    dynamic_cast<View_fight*>(this->view)->updateBackgrounds(posFloor_x, posFloor_y, posMoon_x, posMoon_y, posGalaxy_x, posGalaxy_y);
}

void Game::updateCharacters(char *posCharTeam1_x, char *posCharTeam1_y, char stateCharTeam1, char flipChar1, char currentCharT1,
                            char *posCharTeam2_x, char *posCharTeam2_y, char stateCharTeam2, char flipChar2, char currentCharT2) {
    dynamic_cast<View_fight*>(this->view)->updateCharacters(posCharTeam1_x, posCharTeam1_y, stateCharTeam1, flipChar1, currentCharT1,
            posCharTeam2_x, posCharTeam2_y, stateCharTeam2, flipChar2, currentCharT2);
}

void Game::renderDisconnected() {

    view->renderDisconnected();
}

void Game::updateTime(char* ten, char* unity, char* round) {
    dynamic_cast<View_fight*>(this->view)->updateTime(ten, unity, round);
}

void Game::updateLife(char* lifeTeam1, char* lifeTeam2) {
    dynamic_cast<View_fight*>(this->view)->updateLife(lifeTeam1, lifeTeam2);
}

void Game::updateWinners(char *winners) {
    dynamic_cast<View_endGame*>(this->view)->updateWinners(winners);

}

void Game::updateShouldFight(char *shouldFight) {
    dynamic_cast<View_fight*>(this->view)->updateShouldFight(shouldFight);
}

void Game::updateTeamsWons(char roundsT1, char roundsT2) {
    dynamic_cast<View_fight*>(this->view)->updateTeamsWons(roundsT1, roundsT2);
}

void Game::updateProjectiles(char *posProjectilesTeam1_x, char *posProjectilesTeam1_y, char stateProjectilesTeam1, char flipProjectiles1,
                            char *posProjectilesTeam2_x, char *posProjectilesTeam2_y, char stateProjectilesTeam2, char flipProjectiles2) {
    dynamic_cast<View_fight*>(this->view)->updateProjectiles(posProjectilesTeam1_x, posProjectilesTeam1_y, stateProjectilesTeam1, flipProjectiles1,
                                                            posProjectilesTeam2_x, posProjectilesTeam2_y, stateProjectilesTeam2, flipProjectiles2);
}


