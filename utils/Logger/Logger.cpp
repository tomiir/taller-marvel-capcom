#include "Logger.h"
#include "Logger.h"
#include "Utils.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

const string CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
ofstream CLogger::m_Logfile;
CLogger::CLogger()
{

}
CLogger* CLogger::GetLogger(){
    if (m_pThis == NULL){
        m_pThis = new CLogger();
        m_Logfile.open(m_sFileName.c_str(), ios::out | ios::trunc); //Si quiero que sobreescriba ios::trunc , ios::app  para que appendee
    }
    return m_pThis;
}

void CLogger::Log(const string& sMessage)
{
    char buffer[80];
    Util::CurrentDateTime(buffer);
    m_Logfile <<  buffer << ":\t";
    m_Logfile << sMessage << "\n";
}

CLogger& CLogger::operator<<(const string& sMessage)
{
    char buffer[80];
    Util::CurrentDateTime(buffer);
    m_Logfile <<  buffer << ":\t";
    m_Logfile << sMessage << "\n";
    return *this;
}