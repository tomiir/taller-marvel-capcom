
#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H


#include <iostream>
#include "../../controllers/ViewController/ViewController_fight/ViewController_fight.h"
#include "ViewFactory/ViewFactory.h"

class Game {

public:
    Game(int screenWidth_, int screenHeight_);
    ~Game();

    void init(const char* title, int posX, int posY);
    void clean();

    void updateGreySquares(char* greySquares);

    void updateSelects(char string[3], char string1[3]);

    void updateCharactersImages(char selected_1[3], char selected_2[3]);

    void render();

    bool haveToChangeView();

    void changeView();

    void UpdateBackgrounds(char posFloor_x[5], char PosFloor_y[4], char posMoon_x[5], char posMoon_y[4], char posGalaxy_x[5],
                      char posGalaxy_y[4]);

    void updateCharacters(char posCharTeam1_x[5], char posCharTeam1_y[4], char stateCharTeam1, char flipChar1, char currentCharT1,
                          char posCharTeam2_x[5], char posCharTeam2_y[4], char stateCharTeam2, char flipChar2, char currentCharT2);

private:
    std::map<string, View* > views;
    std::map<string, View*>::iterator itr_views= views.begin();

    std::map<string, Character*> characters;
    std::map<string, Character*>::iterator itr_characters= characters.begin();

    SDL_Window* window;
    SDL_Renderer* renderer;
    View* view;
    ViewFactory * factory; //Lo agrego para crear la primera ViewController
    int screenWidth, screenHeight;

    Character* getCharacter(string character);

};


#endif //TRABAJOPRACTICOTALLER_GAME_H
