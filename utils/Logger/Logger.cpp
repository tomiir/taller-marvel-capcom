#include "Logger.h"

#include <stdarg.h>
#include <execinfo.h> // for backtrace
#include <dlfcn.h>    // for dladdr
#include <cxxabi.h>   // for __cxa_demangle

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

string CLogger::filename = "taller-marvel-capcom-0.log";
CLogger* CLogger::m_pThis = NULL;
fstream CLogger::m_Logfile;
CLogger::CLogger(){}
vector<string> CLogger::levelNames = {"ERROR", "INFO", "NETWORK", "DEBUG"};

std::string Backtrace(int skip = 1)
{
    void *callstack[128];
    const int nMaxFrames = sizeof(callstack) / sizeof(callstack[0]);
    char buf[1024];
    int nFrames = backtrace(callstack, nMaxFrames);
    char **symbols = backtrace_symbols(callstack, nFrames);

    std::ostringstream trace_buf;
    for (int i = skip; i < nFrames; i++) {

        Dl_info info;
        if (dladdr(callstack[i], &info) && info.dli_sname) {
            char *demangled = NULL;
            int status = -1;
            if (info.dli_sname[0] == '_')
                demangled = abi::__cxa_demangle(info.dli_sname, NULL, 0, &status);
            snprintf(buf, sizeof(buf), "%-3d %*p %s + %zd\n",
                     i, int(2 + sizeof(void*) * 2), callstack[i],
                     status == 0 ? demangled :
                     info.dli_sname == 0 ? symbols[i] : info.dli_sname,
                     (char *)callstack[i] - (char *)info.dli_saddr);
            free(demangled);
        } else {
            snprintf(buf, sizeof(buf), "%-3d %*p %s\n",
                     i, int(2 + sizeof(void*) * 2), callstack[i], symbols[i]);
        }
        trace_buf << buf;
    }
    free(symbols);
    if (nFrames == nMaxFrames)
        trace_buf << "[truncated]\n";
    return trace_buf.str();
}

CLogger* CLogger::GetLogger(){
    if (m_pThis == NULL){
        m_pThis = new CLogger();

        m_Logfile.open(filename.c_str());
        while(!m_Logfile.fail()) {
            filename = filename.substr(0, filename.find("."));
            int id = std::atoi (filename.substr(filename.find_first_of("1234567890"), filename.size()-1).c_str());
            string idString =  to_string(id +1);
            filename = filename.substr(0,filename.find_first_of("1234567890")) + idString + ".log";

            m_Logfile.close();
            m_Logfile.open(filename.c_str());
        }
        m_Logfile.open(filename.c_str(), ios::app);
    }
    return m_pThis;
}

void CLogger::Log(const string& sMessage, int level, string e) {
    if(level > this -> level) return;
    m_Logfile << "\n[" << levelNames[level] << "]\t ";
    logCurrentDateTime();
    m_Logfile << sMessage << "\n";

    if (this -> level == DEBUG && !e.empty()) {
        this->logCurrentDateTime();
        m_Logfile << Backtrace() << endl;
    }
    if (e.size()) {
        m_Logfile << e << "\n";
    }
}

void CLogger:: logCurrentDateTime() {
    char timeStr[200];
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    strftime(timeStr,200,"[ %c ]", now);
    m_Logfile << timeStr << "\n";
}

void CLogger::LogMovement(string cName, DirectionVector* dir, int x, int y) {
    string message;
    message = "Moviendo a " + cName +
            "\n Posición anterior: [" + to_string(x) + " , " + to_string(y) + "]" +
            "\n Direccion: ["+ to_string(dir->x) + to_string(dir->y) + "]" +
            "\n Posicion nueva: " + "[" + to_string(x+dir->x) + " , " + to_string(y+dir->y) + "]";
    this -> Log(message, DEBUG, "");
}

void CLogger::LogError(string parameter, string object) {
    string message = "Hubo un error al cargar el parametro: " + parameter + " de  " + object + " , se levantara el parametro del default";
    this -> Log(message, ERROR, "");

}

void CLogger::closeLogger() {
    Log("Ha ocurrido un error de network, cerrando logger", ERROR, "");
    this -> m_Logfile.close();
}