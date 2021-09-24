// Código basado en dateTime, con algunas modificaciones.
#ifndef _FECHA_H_
#define _FECHA_H_

#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector> 

class Fecha {
  public:
    Fecha();
    Fecha(std::string mes, int dia, int horas, int minutos, int segundos);
    time_t getDate();
    std::string getMonth();
    int getDay();
    int getHour();
    int getMinute();
    int getSecond();
    bool operator ==(const Fecha&);
    bool operator <=(const Fecha&);
    bool operator !=(const Fecha&);
    bool operator >(const Fecha&);
    bool operator <(const Fecha&);
    
  private:
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
    std::string month;
    int day, hour, minute, second;
};
#endif