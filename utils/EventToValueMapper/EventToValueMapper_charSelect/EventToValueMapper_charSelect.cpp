//
// Created by magali on 01/05/19.
//

#include "EventToValueMapper_charSelect.h"


EventToValueMapper_charSelect::EventToValueMapper_charSelect(){

    /* [cap_america] [spiderman]
     * [chun_li] [venom] */


    cap_america["up"] = "chun_li" ;
    cap_america["down"] = "chun_li";
    cap_america["right"] = "spider_man" ;
    cap_america["left"] = "spider_man";

    chun_li["up"] = "cap_america";
    chun_li["down"] = "cap_america" ;
    chun_li["right"] = "venom";
    chun_li["left"] = "venom";

    spider_man["up"] = "venom";
    spider_man["down"] = "venom";
    spider_man["right"] =  "cap_america";
    spider_man["left"] = "cap_america";

    venom["up"] = "spider_man";
    venom["down"] = "spider_man" ;
    venom["right"] = "chun_li" ;
    venom["left"] = "chun_li" ;

    map_map["cap_america"] = cap_america;
    map_map["chun_li"] = chun_li;
    map_map["venom"] = venom;
    map_map["spiderman"] = spider_man;


}

string EventToValueMapper_charSelect::getPreselected() {
    return preselected;

}

EventToValueMapper_charSelect::~EventToValueMapper_charSelect() {

}

string EventToValueMapper_charSelect::map(SDL_Event event) {
    return std::__cxx11::string();
}
