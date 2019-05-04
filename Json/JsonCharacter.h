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
    int height;
    int width;
    int zindex;
    std::string spriteManager;
    double size;

public:
    JsonCharacter() = default;
    ~JsonCharacter() = default;
    JsonCharacter(std::list<std::string> errors);
    JsonCharacter(std::string name, std::string filepath, int height, int width, int zindex, std::string spriteManager, double size);
    std::string getName();
    std::string getFilePath();
    int getHeight();
    int getWidth();
    int getzIndex();
    std::list<std::string> getErrorList();
    std::string getSpriteManager();
    double getSize();
    bool getError();

private:
    bool error;
    std::list<std::string> errorsList;
};


#endif //JSON_2_CHARACTER_H
