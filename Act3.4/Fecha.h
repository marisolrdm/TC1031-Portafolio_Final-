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

Fecha::Fecha(){
  Fecha("None", 0, 00, 00, 00);
}

Fecha::Fecha(std::string mes, int dia, int horas, int minutos, int segundos) {
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = segundos;
  dateStruct.tm_min = minutos;
  dateStruct.tm_hour = horas;
  dateStruct.tm_mday = dia;
  month = mes;
  day = dia;
  hour = horas;
  minute = minutos;
  second = segundos;
  // Inicializado a 0 para evitar problemas de compatibilidad
  dateStruct.tm_isdst = 0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i]==mes)
    dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);
}

time_t Fecha::getDate(){
  std::cout<<date;
  return date;
}

std::string Fecha::getMonth(){
  return month;
}

int Fecha::getDay(){
  return day;
}

int Fecha::getHour(){
  return hour;
}

int Fecha::getMinute(){
  return minute;
}

int Fecha::getSecond(){
  return second;
}

bool Fecha::operator==(const Fecha &other){
  return this->date == other.date;
}

bool Fecha::operator<=(const Fecha &other) {
  return this->date <= other.date;
}

bool Fecha::operator!=(const Fecha &other) {
  return this->date != other.date;
}

bool Fecha::operator>(const Fecha &other) {
  return this->date > other.date;
}

bool Fecha::operator<(const Fecha &other) {
  return this->date < other.date;
}

#endif