//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H

#include "../ViewController.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_charSelect/EventToValueMapper_charSelect_1.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_charSelect/EventToValueMapper_charSelect_2.h"
#include <string>
#include "../../../model/GameObject_charSelect/GameObject_charSelect.h"
#include <stdio.h>

class ViewController_charSelect: public ViewController {

public:

    explicit ViewController_charSelect(SDL_Renderer *renderer_);
    ~ViewController_charSelect() override;
    void updateView() override;
    void handleEvent() override;
    void addBackground(ControllerBackground *controller) override;
    void setTeam1(string character);
    void setTeam2(string character);

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



private:
    int getTeam(SDL_Event event);



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

    // DICCIONARIOS POR TEAM DE FOTOS LATERALES
    std::map<string, GameObject_charSelect* > team_1;
    map<string, GameObject_charSelect*>::iterator itr_team_1= team_1.begin();
    std::map<string, GameObject_charSelect* > team_2;
    map<string, GameObject_charSelect*>::iterator itr_team_2= team_2.begin();

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

    //MAPEADORES DE TECLAS
    EventToValueMapper_charSelect_1* mapper_1;
    EventToValueMapper_charSelect_2* mapper_2;


};

#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H
