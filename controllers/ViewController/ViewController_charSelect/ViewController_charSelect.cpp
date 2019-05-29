//
// Created by magali on 01/05/19.
//

#include "ViewController_charSelect.h"
#include <algorithm>

ViewController_charSelect::ViewController_charSelect():ViewController(){

    /* [cap_america] [spiderman]
     * [chun_li] [venom] */


    cap_america["up"] = "ChunLi" ;
    cap_america["down"] = "ChunLi";
    cap_america["right"] = "SpiderMan" ;
    cap_america["left"] = "SpiderMan";

    chun_li["up"] = "CaptainAmerica";
    chun_li["down"] = "CaptainAmerica" ;
    chun_li["right"] = "Venom";
    chun_li["left"] = "Venom";

    spider_man["up"] = "Venom";
    spider_man["down"] = "Venom";
    spider_man["right"] =  "CaptainAmerica";
    spider_man["left"] = "CaptainAmerica";

    venom["up"] = "SpiderMan";
    venom["down"] = "SpiderMan" ;
    venom["right"] = "ChunLi" ;
    venom["left"] = "ChunLi" ;

    map_map["CaptainAmerica"] = cap_america;
    map_map["ChunLi"] = chun_li;
    map_map["Venom"] = venom;
    map_map["SpiderMan"] = spider_man;

    map_preselectedT1 = cap_america;
    map_preselectedT2 = spider_man;
}



void ViewController_charSelect:: handleEvent(string event) {

    recentlySelected = "";
    recentlySelected2 = "";

    if (event == "h1" or event == "h3"
        or event == "h2" or event == "h4")
        return;


    if (event == "d1" or event == "d3") preselectedT1 = map_preselectedT1["right"];
    if (event == "a1" or event == "a3") preselectedT1 = map_preselectedT1["left"];
    if (event == "w1" or event == "w3") preselectedT1 = map_preselectedT1["up"];
    if (event == "s1" or event == "s3") preselectedT1 = map_preselectedT1["down"];

    map_preselectedT1 = map_map[preselectedT1];

    if (selected_1.size() < 2){

        if (event == "c1" or event == "c3") setTeam1(preselectedT1);
    }


    if (event == "d2" or event == "d4") preselectedT2 = map_preselectedT2["right"];
    if (event == "a2" or event == "a4") preselectedT2 = map_preselectedT2["left"];
    if (event == "w2" or event == "w4") preselectedT2 = map_preselectedT2["up"];
    if (event == "s2" or event == "s4") preselectedT2 = map_preselectedT2["down"];

    map_preselectedT2 = map_map[preselectedT2];

    if(selected_2.size() < 2){

        if (event == "c2" or event == "c4") setTeam2(preselectedT2);
    }

}

void ViewController_charSelect::setTeam1(string character){

    bool posible = true;

    std::vector<string>::iterator itr = selected.begin();

    for (itr; itr != selected.end(); ++itr){
        if (strcmp((*itr).c_str(),(character).c_str()) == 0){
            posible = false;
        }
    }

    if(posible) {
        selected.push_back(character);
        selected_1.push_back(character);
        recentlySelected = character;
    }
}

void ViewController_charSelect::setTeam2(string character) {
    bool posible = true;

    std::vector<string>::iterator itr = selected.begin();

    for (itr; itr != selected.end(); ++itr){
        if (strcmp((*itr).c_str(),(character).c_str()) == 0){
            posible = false;
        }
    }

    if(posible) {
        selected.push_back(character);
        selected_2.push_back(character);
        recentlySelected2 = character;
    }

}


bool ViewController_charSelect:: end(){
    return selected.size() == 4;

}

ViewController_charSelect::~ViewController_charSelect() {

}

string ViewController_charSelect::getNextView() {
    return "fight";
}

bool ViewController_charSelect::selectedContains(string name){

    std::vector<string>::iterator itr_selected = selected.begin();

    for (itr_selected; itr_selected != selected.end(); ++itr_selected){

        if (*itr_selected == name) return true;
    }
    return false;
}

string ViewController_charSelect::giveNewParameters() {

    string updates = "000000000000000000000000000000000000000000000";

    if(selectedContains("CaptainAmerica")) updates[2] = '1';
    if(selectedContains("SpiderMan")) updates[3] = '1';
    if(selectedContains("ChunLi")) updates[4] = '1';
    if(selectedContains("Venom")) updates[5] = '1';

    if(preselectedT1 == "CaptainAmerica") {
        updates[6] = '0';
        updates[7] = '0';
    }else if (preselectedT1 == "SpiderMan"){
        updates[6] = '0';
        updates[7] = '1';
    }else if (preselectedT1 == "ChunLi"){
        updates[6] = '1';
        updates[7] = '0';
    }else {
        updates[6] = '1';
        updates[7] = '1';
    }

    if(preselectedT2 == "CaptainAmerica") {
        updates[8] = '0';
        updates[9] = '0';
    }else if (preselectedT2 == "SpiderMan"){
        updates[8] = '0';
        updates[9] = '1';
    }else if (preselectedT2 == "ChunLi"){
        updates[8] = '1';
        updates[9] = '0';
    }else {
        updates[8] = '1';
        updates[9] = '1';
    }

    if(recentlySelected == "CaptainAmerica"){
        updates[10] = '1';
        updates[11] = '0';
        updates[12] = '0';

    }else if(recentlySelected == "SpiderMan") {
        updates[10] = '1';
        updates[11] = '0';
        updates[12] = '1';
    }else if(recentlySelected == "ChunLi"){
        updates[10] = '1';
        updates[11] = '1';
        updates[12] = '0';
    } else if(recentlySelected == "Venom"){
        updates[10] = '1';
        updates[11] = '1';
        updates[12] = '1';
    }

    if(recentlySelected2 == "CaptainAmerica"){
        updates[13] = '1';
        updates[14] = '0';
        updates[15] = '0';

    }else if(recentlySelected2 == "SpiderMan") {
        updates[13] = '1';
        updates[14] = '0';
        updates[15] = '1';
    }else if(recentlySelected2 == "ChunLi"){
        updates[13] = '1';
        updates[14] = '1';
        updates[15] = '0';
    } else if(recentlySelected2 == "Venom"){
        updates[13] = '1';
        updates[14] = '1';
        updates[15] = '1';
    }

    return updates;

}

bool ViewController_charSelect::haveToChangeView() {
    return selected.size() == 4;
}

std::vector<string> ViewController_charSelect::getTeam1() {
    return selected_1;
}

std::vector<string> ViewController_charSelect::getTeam2() {
    return selected_2;
}



