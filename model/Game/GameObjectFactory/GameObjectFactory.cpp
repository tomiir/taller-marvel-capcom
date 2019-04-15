//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"
#include "../../../utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.h"
#include "../../../utils/SpriteManagers/SpiderManSpriteManager/SpiderManSpriteManager.h"
#include "../../../utils/SpriteManagers/ChunLiSpriteManager/ChunLiSpriteManager.h"
#include "../../../Json/JsonConfigs.cpp"

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;

}

GameObjectFactory::~GameObjectFactory() = default;


vector<GameObject*> GameObjectFactory:: getGameObjectsCharacters_fight() {

    vector<GameObject*>  gameObjects;


    JsonConfigs* config = new JsonConfigs("../../../configs.json");
    std::list<Character> charactersTeam1 = config->getCharactersTeam1();


    list <Character>::iterator iter = charactersTeam1.begin();
    for (iter ;iter != charactersTeam1.end();++iter) {
        std::string path = (*iter).getRuta();
        // json: debe dar el spriteManager correcto comparando entre strings!
        int initialY = screenHeight -(*iter)->getHeight();
        Character* C = new Character(path.c_str(), (*iter).getzIndex(), renderer, (*iter).getSpriteManager(), (*iter).getWidth()/2, initialY, initialY + (*iter).getCrowchedDownY() );

        if(!C){
            //lanzar excp
        }

        gameObjects.push_back((C));
    }

    std::list<Character> charactersTeam2 = config->getCharactersTeam2();
    list <Character>::iterator iter_2 = charactersTeam2.begin();
    for (iter_2 ;iter_2 != charactersTeam2.end();++iter_2) {
        std::string path = (*iter_2).getRuta();
        // json: debe dar el spriteManager correcto comparando entre strings!
        int initialY = screenHeight -(*iter_2)->getHeight();
        int width = (*iter_2).getWidth();
        int height = (*iter_2).getHeight();
        Character* C = new Character(path.c_str(), (*iter_2).getzIndex(), renderer, (*iter_2).getSpriteManager(),(screenWidth - width) - (width/2), initialY, initialY + (*iter_2).getCrowchedDownY()) ;
        if(!C){
            //lanzar excp
        }

        gameObjects.push_back((C));
    }

    /*
    Character* captainAmerica = new Character("Images/CaptainAmerica.png",5, renderer, new CaptainAmericaSpriteManager(), 200/2, screenHeight - 280, screenHeight - 280 + 75);
    Character* chunLi = new Character("Images/ChunLi.png",5, renderer, new ChunLiSpriteManager(), 200/2,screenHeight - 220, screenHeight - 220 + 40);

    Character* spiderMan= new Character("Images/SpiderMan.png",4, renderer, new SpiderManSpriteManager(), (screenWidth - 200) - (200/2),screenHeight - 245, screenHeight - 245 + 95);
    Character* venom = new Character("Images/Venom.png",4, renderer, new VenomSpriteManager(), (screenWidth - 200) - (200/2), screenHeight - 280, screenHeight - 280 + 60);


    gameObjects = {spiderMan, venom, captainAmerica, chunLi};
*/

    return gameObjects;

}

double GameObjectFactory::cameraSpeedPercentage(int widthMax, int widthImg) {
    double a = widthImg - screenWidth;
    double b = widthMax - screenWidth;
    return a/b;
}


vector<GameObject*> GameObjectFactory:: getGameObjectsBackgrounds_fight() {

    vector<GameObject *> gameObjects;

/*
 * ahí habria que hacer un for que cree los backgrounds.
 * Mientras los va creando va actualizando el ancho máximo.
 * Acá termina el for.
 * Por cada background se va a calcular el porcentaje de su velocidad y la velocidad con la que se tiene que mover.
 * Luego, se pasa por una función dicha velocidad.
 * */

    JsonConfigs* config = new JsonConfigs("../../../configs.json");
    list <Battlefield> battlefields = config->getBattlefields();

    //HAY QUE LANZAR EXCEPCIONES POR SI NO SE CREA EL GAME OBJECT BACKGROUND!
    int maxWidth = 0;
    int speedCharacter = config.getCharacterSpeed();

    list <Battlefield>::iterator iter = battlefields.begin();
    for (iter ;iter != battlefields.end();++iter){

        std::string path = (*iter).getRuta();
        int width = (*iter).getWidth();
        Background *B = new Background(path.c_str(),(*iter).getzIndex(), renderer, width, (*iter).getHeigth(), screenWidth, screenHeight);

        if (!B){
            //excepción
        }

        if (width > maxWidth) maxWidth = width;

        gameObjects.push_back(B);

    }

    vector <GameObject*>::iterator itr = gameObjects.begin();
    for (itr; itr != gameObjects.end(); ++itr){
        double speedPercentageB = cameraSpeedPercentage(maxWidth, (*itr)->getInfo()[2]);
        int cameraSpeedB = speedCharacter * speedPercentageB;
        dynamic_cast<Background*>(*itr)->setSpeeds(cameraSpeedB,speedPercentageB);
    }




    return gameObjects;

}