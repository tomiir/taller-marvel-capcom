//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_CHARACTER_H
#define JSON_2_CHARACTER_H


#include <string>

class Character {
    std::string name;
    std::string filepath;
    int height;
    int width;
    int zindex;

public:
    Character(std::string name, std::string filepath, int height, int width, int zindex);

    std::string getName();
    std::string getFilePath();
    int getHeight();
    int getWidth();
    int getzIndex();

};


#endif //JSON_2_CHARACTER_H
