#ifndef CUSTOM_CLogger_H
#define CUSTOM_CLogger_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
#include <vector>
#include "../Vector2D/DirectionVector.h"

const int ERROR = 0;
const int INFO = 1;
const int DEBUG = 2;



using namespace std;
#define LOGGER CLogger::GetLogger()
/**
*   Singleton Logger Class.
*/
class CLogger
{
public:
    void Log(const std::string& sMessage, int level, string e);
    void LogMovement(string cName, DirectionVector* dir, int x, int y);
    void LogError(string parameter, string object);

    void setLevel(int level) {
        this -> level = level;
    }

    //Crea la instancia
    static CLogger* GetLogger();

private:

    // Constructor privado
    CLogger();
    CLogger(const CLogger&) = default;

    // Sobrescribe el operado igual (=)
    CLogger& operator=(const CLogger&){ return *this; };  // assignment operator is private

    static std::string filename;

    static CLogger* m_pThis;

    static fstream m_Logfile;

    static vector<string> levelNames;

    void logCurrentDateTime();

    int level;
};
#endif