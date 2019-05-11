
#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H


#include <iostream>
#include "../../controllers/ViewController/ViewController_fight/ViewController_fight.h"
#include "ViewControllerFactory/ViewControllerFactory.h"

class Game {

public:
    Game(int screenWidth_, int screenHeight_);
    ~Game();

    void init(const char* title, int posX, int posY);
    void tick();
    void update();
    void clean();
    ViewController* getViewContoller();

    void updateGreySquares(char* greySquares);

    void updateSelects(char string[3], char string1[3]);

    void updateCharactersImages(char selected_1[3], char selected_2[3]);

private:
    std::map<string, ViewController* > views;
    std::map<string, ViewController*>::iterator itr_views= views.begin();

    std::map<string, ControllerCharacter*> characters;

    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ViewController* viewController;
    ViewControllerFactory * factory; //Lo agrego para crear la primera ViewController
    int screenWidth, screenHeight;
    void setControllerCharacters(ViewController_fight *view, map<string, ControllerCharacter *> controllers);

};


#endif //TRABAJOPRACTICOTALLER_GAME_H
