//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_PRUEBA_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_H


#include <string>
#include "../../../model/GameObject_charSelect/GameObject_charSelect.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

class ViewController_charSelect {

public:

    explicit ViewController_charSelect();
    ~ViewController_charSelect();
    void handleEvent(string event);
    void setTeam1(string character);
    void setTeam2(string character);

    bool end();
    string getNextView();

    std::vector<string> getTeam1();
    std::vector<string> getTeam2();


    string giveNewParametes();

private:


    // PERSONAJES SELECCIONADOS POR CADA TEAM
    std::vector<string> selected_1;
    std::vector<string> selected_2;

    // PERSONAJES SELECCIONADOS
    std::vector<string> selected;

    string preselectedT1 = "CaptainAmerica";
    string preselectedT2 = "SpiderMan";


    std::map<string, std::map<string,string> > map_map;
    std::map<string, string> cap_america;
    std::map<string, string> chun_li;
    std::map<string, string> spider_man;
    std::map<string, string> venom;

    std::map<string, string> map_preselectedT1 = cap_america;
    std::map<string, string> map_preselectedT2 = spider_man;

    string recentlySelected = "";
    string recentlySelected2 = "";

};

#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_CHARSELECT_PRUEBA_H
