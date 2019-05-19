//
// Created by magali on 18/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_JSONGAMEOBJECT_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_JSONGAMEOBJECT_CHARSELECT_H
#include "string"
#include "list"
#include "vector"

class JsonGameObject_charSelect {
public:
    JsonGameObject_charSelect(const char* path, std::vector<int> posc, std::string name);
    ~JsonGameObject_charSelect() =default;
    const char* getFilePath();
    std::string getName();
    std::vector <int> getPosc();
    JsonGameObject_charSelect() = default;
    std::list<std::string> getErrorList();

    JsonGameObject_charSelect(std::list<std::string> errors);
    bool getError();

private:
    const char* path;
    std::vector <int> posc;
    std::string name;
    bool error;
    std::list<std::string> errorsList;
};


#endif //TALLER_MARVEL_CAPCOM_JSONGAMEOBJECT_CHARSELECT_H
