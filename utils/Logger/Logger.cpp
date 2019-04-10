#include "Logger.h"
#include "Logger.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
using namespace std;

string CLogger::filename = "taller-marvel-capcom-0";
CLogger* CLogger::m_pThis = NULL;
fstream CLogger::m_Logfile;
CLogger::CLogger(){}
vector<string> CLogger::levelNames = {"ERROR", "INFO", "DEBUG"};


CLogger* CLogger::GetLogger(){
    if (m_pThis == NULL){
        m_pThis = new CLogger();

        m_Logfile.open((filename + ".log").c_str());
        while(!m_Logfile.fail()) {
            int id = std::atoi (&filename[filename.size()-5]);
            string idString =  to_string(id +1);
            filename.replace(filename.size() -1,idString.size(), idString);
            filename+= ".log";
            m_Logfile.close();
            m_Logfile.open(filename.c_str());
        }
        m_Logfile.open(filename.c_str(), ios::app);
    }
    return m_pThis;
}

void CLogger::Log(const string& sMessage, int level, string e) {

    if(level > this -> level) return;
    m_Logfile << "[" << levelNames[level] << "] ";
    m_Logfile << sMessage << "\t";

    if (level == DEBUG) {
        this->logCurrentDateTime();
    }
    if (e.size()) {
        m_Logfile << ">>>> \t" << e << "\n";
    }
}

void CLogger:: logCurrentDateTime() {
    char timeStr[200];
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    strftime(timeStr,200,"[ %c ]", now);
    m_Logfile << timeStr << "\n";
}
