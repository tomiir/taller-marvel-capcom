//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_JSONCHARACTER_H
#define JSON_2_JSONCHARACTER_H


#include <string>
#include <list>

class JsonCharacter {
    std::string name;
    std::string filepath;
    std::string lifebarpath;
    int zindexlifebar;
    int height;
    int width;
    int zindex;
    std::string spriteManager;
    double size;
    int wSprite;
    int hSprite;

public:
    JsonCharacter() = default;
    ~JsonCharacter() = default;
    JsonCharacter(std::list<std::string> errors);
    JsonCharacter(std::string name, std::string filepath, std::string lifebarPath , int zindexlifebar, int height, int width, int zindex, std::string spriteManager, double size, int wSprite, int hSprite);
    std::string getName();
    std::string getFilePath();
    int getzIndexLifebar();
    int getHeight();
    int getWidth();
    int getzIndex();
    std::list<std::string> getErrorList();
    std::string getSpriteManager();
    std::string getLifebarpath();
    double getSize();
    bool getError();
    int getWSprite();
    int getHSprite();

private:
    bool error;
    std::list<std::string> errorsList;

};


#endif //JSON_2_CHARACTER_H
