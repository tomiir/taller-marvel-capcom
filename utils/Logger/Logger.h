#ifndef CUSTOM_CLogger_H
#define CUSTOM_CLogger_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;
#define LOGGER CLogger::GetLogger()
/**
*   Singleton Logger Class.
*/
class CLogger
{
public:
    void Log(const std::string& sMessage);

    // Permite loggear con <<
    CLogger& operator<<(const string& sMessage);

    //Crea la instancia
    static CLogger* GetLogger();
private:

    // Constructor privado
    CLogger();

    CLogger(const CLogger&){};             // copy constructor is private

    // Sobrescribe el operado igual (=)
    CLogger& operator=(const CLogger&){ return *this; };  // assignment operator is private

    static const std::string m_sFileName;

    static CLogger* m_pThis;

    static ofstream m_Logfile;
};
#endif