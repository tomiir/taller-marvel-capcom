//
// Created by arielpm on 12/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_VIEW_CHARSELECT_H

#include <string>
#include <stdio.h>
#include "../../controllers/ViewController/ViewController.h"
#include "../../model/GameObject_charSelect/GameObject_charSelect.h"

class View_charSelect: public View {

public:

    explicit View_charSelect(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_);
    ~View_charSelect() override;
    void updateView() override;
    void updateGreySquares(char* greySquares);
    void updateSelects(char *selectT1, char *selectT2);
    void updateCharacterImages(char* selected_1, char* selected_2);
    bool end() override;
    string getNextView() override;

    // fotos laterales para cada TEAM
    void addGameObject_character(GameObject_charSelect* gameObject, int team);

    // fondo
    void addGameObject_background(GameObject_charSelect* background);

    //el cuadrado de cada team
    void addGameObject_square(GameObject_charSelect* square, int team);

    //agregar 4 cuadrados grises
    void addGameObject_square_gray(GameObject_charSelect* square);

    //fotos laterales de seleccionados para cada TEAM
    void addGameObject_character_selected(GameObject_charSelect *gameObject, int team);


    std::vector<string> getTeam1() ;
    std::vector<string> getTeam2() ;

    void renderDisconnected() override;


    void addGameObject_disconnected(GameObject *disconnected_);

private:

    std::vector <GameObject_charSelect*> getSides();
    std::vector <GameObject_charSelect*> getGreysSquares();
    std::vector <GameObject_charSelect*> getSelectionSquares();

    void renderVector(std::vector<GameObject_charSelect*> to_render);

    // PERSONAJES SELECCIONADOS POR CADA TEAM
    std::vector<string> selected_1;
    std::vector<string> selected_2;

    // PERSONAJES SELECCIONADOS
    std::vector<string> selected;


    //VECTOR DE VECTORES DE POSICIONES PARA CADA TEAM
    //En la posc 1 de este vector esta la posicion del team 1 para su primera foto lateral.
    std::vector<std::vector<int>> posc_side_1;
    //En la posc 1 de este vector esta la posicion del team 2 para su primera foto lateral
    std::vector<std::vector<int>> posc_side_2;

    // DICCIONARIOS POR TEAM DE FOTOS LATERALES, PRESELECCIONADOS

    std::map<string, GameObject_charSelect* > team_1;
    map<string, GameObject_charSelect*>::iterator itr_team_1= team_1.begin();
    std::map<string, GameObject_charSelect* > team_2;
    map<string, GameObject_charSelect*>::iterator itr_team_2= team_2.begin();

    // DICCIONARIOS POR TEAM DE FOTOS LATERALES, SELECCIONADOS

    std::map<string, GameObject_charSelect* > team_1_selected;
    map<string, GameObject_charSelect*>::iterator itr_team_1_selected= team_1_selected.begin();
    std::map<string, GameObject_charSelect* > team_2_selected;
    map<string, GameObject_charSelect*>::iterator itr_team_2_selected= team_2_selected.begin();


    // CUADRADITOS
    GameObject_charSelect* square_team1;
    GameObject_charSelect* square_team2;

    //DICCIONARIO DE POSCIONES DE CUADRADITOS;
    std::map<string, vector<int> > squarePosition;
    map<string, vector<int> >::iterator itr_squarePosition = squarePosition.begin();

    //DICCIONARIO DE CUADRATITOS GRISES
    std::map<string, GameObject_charSelect* > greySquare;
    map<string, GameObject_charSelect*>::iterator itr_greySquare =greySquare.begin();

    //FONDO
    GameObject_charSelect* background;

    string preselectedT1 = "CaptainAmerica";
    string preselectedT2 = "SpiderMan";

    int screenWidth;
    int screenHeight;

    bool selectedNotContains(string name);

    GameObject* disconnected;
};


#endif //TALLER_MARVEL_CAPCOM_VIEW_CHARSELECT_H
