// Código basado en dateTime, con algunas modificaciones.
#include "Fecha.h"

Fecha::Fecha(){
  Fecha("Jan", 1, 00, 00, 00);
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