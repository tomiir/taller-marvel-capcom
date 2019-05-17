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

    //pasar los strcmp a ==
    if (event == "0000000" or event == "0000010"
        or event == "0000001" or event == "0000011")
        return;


    if (event == "1000000" or event == "1000010") preselectedT1 = map_preselectedT1["right"];
    if (event == "0100000" or event == "0100010") preselectedT1 = map_preselectedT1["left"];
    if (event == "0010000" or event == "0010010") preselectedT1 = map_preselectedT1["up"];
    if (event == "0001000" or event == "0001010") preselectedT1 = map_preselectedT1["down"];

    map_preselectedT1 = map_map[preselectedT1];

    if (selected_1.size() < 2){

        if (event == "0000100" or event == "0000110") setTeam1(preselectedT1);
    }


    if (event == "1000001" or event == "1000011") preselectedT2 = map_preselectedT2["right"];
    if (event == "0100001" or event == "0100011") preselectedT2 = map_preselectedT2["left"];
    if (event == "0010001" or event == "0010011") preselectedT2 = map_preselectedT2["up"];
    if (event == "0001001" or event == "0001011") preselectedT2 = map_preselectedT2["down"];

    map_preselectedT2 = map_map[preselectedT2];

    if(selected_2.size() < 2){

        if (event == "0000101" or event == "0000111") setTeam2(preselectedT2);
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

string ViewController_charSelect::giveNewParameters() {

    string updates = "0000000000000000000000000000000000000000000";

    if(recentlySelected == "CaptainAmerica" or recentlySelected2 == "CaptainAmerica") updates[2] = '1';
    else if(recentlySelected == "SpiderMan" or recentlySelected2 == "SpiderMan") updates[3] = '1';
    else if(recentlySelected == "ChunLi" or recentlySelected2 == "ChunLi") updates[4] = '1';
    else if(recentlySelected == "Venom" or recentlySelected2 == "Venom") updates[5] = '1';

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



