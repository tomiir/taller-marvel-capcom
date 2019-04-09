//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

vector<GameObject*> GameObjectFactory:: getCharacters_fight() {

    vector<GameObject*>  characters;

    Character* captainAmerica1 = new Character("/home/fer/Escritorio/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* wolverine1 = new Character("/home/fer/Escritorio/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);

    Character* captainAmerica2 = new Character("/home/fer/Escritorio/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* wolverine2 = new Character("/home/fer/Escritorio/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);

    characters = {captainAmerica1, wolverine1, captainAmerica2, wolverine2 };

    return characters;

}

vector<GameObject *> GameObjectFactory::getBackgrounds_fight() {

    vector<GameObject*>  backgrounds;


    Background* B1 = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Background1.png", renderer, 1500, 900, 1200, 700);
    if (!B1) {
        //usar imagen " ? "
    }

    Background* B2 = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Background2.png", renderer, 1900, 900, 1200, 700);
    if (!B2) {
        //usar imagen " ? "
    }

    Background* B3 = new Background("/home/fer/Escritorio/taller-marvel-capcom/Images/Backgrounds/Background3.png", renderer, 2300, 900, 1200, 700);
    if (!B3) {
        //usar imagen " ? "
    }

    backgrounds = {B1, B2, B3};

    return backgrounds;
}



