//
// Created by magali on 22/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_JSONDISCONECTION_H
#define TALLER_MARVEL_CAPCOM_JSONDISCONECTION_H

#include <string>
#include <list>

class JsonDisconection {

private:
    std::string name;
    std::string path;
    int x;
    int y;
    int height;
    int width;
    bool error;
    std::list<std::string> errorsList;

public:
    JsonDisconection() = default;
    ~JsonDisconection() = default;
    JsonDisconection(std::list<std::string> errors);
    JsonDisconection(std::string name, std::string path, int x, int y, int width, int height);
    std::string getName();
    std::string getPath();
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    bool getError();
    std::list<std::string> getErrorList();

};


#endif //TALLER_MARVEL_CAPCOM_JSONDISCONECTION_H
