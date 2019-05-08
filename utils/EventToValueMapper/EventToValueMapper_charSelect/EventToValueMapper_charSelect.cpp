//
// Created by magali on 01/05/19.
//

#include "EventToValueMapper_charSelect.h"


EventToValueMapper_charSelect::EventToValueMapper_charSelect(){

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


}

string EventToValueMapper_charSelect::getPreselected() {
    return preselected;

}

EventToValueMapper_charSelect::~EventToValueMapper_charSelect() {

}

string EventToValueMapper_charSelect::map(SDL_Event event) {
    return std::__cxx11::string();
}