//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_JSONBACKGROUND_H
#define JSON_2_JSONBACKGROUND_H

#include <list>
#include <string>

class JsonBackground {

    std::string path;
    int zindex;
    int height;
    int width;
    bool error;
    std::string name;
    std::list<std::string> errorsList;


public:
    JsonBackground() = default;
    ~JsonBackground() = default;
    JsonBackground(std::list<std::string> errors);
    JsonBackground(std::string name, std::string path,int zindex,  int width, int height);
    std::string getFilePath();
    std::string getName();
    int getzIndex();
    int getHeight();
    int getWidth();
    bool getError();
    std::list<std::string> getErrorList();
};



#endif //JSON_2_JSONBACKGROUND_H
