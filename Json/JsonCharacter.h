//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_JSONCHARACTER_H
#define JSON_2_JSONCHARACTER_H


#include <string>

class JsonCharacter {
    std::string name;
    std::string filepath;
    int height;
    int width;
    int zindex;
    int crowchedDownY;
    std::string spriteManager;
    double size;

public:

    JsonCharacter(std::string name, std::string filepath, int height, int width, int zindex, int crowchedDownY, std::string spriteManager, double size);
    std::string getName();
    std::string getFilePath();
    int getHeight();
    int getWidth();
    int getzIndex();
    int getCrowchedDownY();
    std::string getSpriteManager();
    double getSize();

};


#endif //JSON_2_CHARACTER_H