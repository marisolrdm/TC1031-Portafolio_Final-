#ifndef _REGISTRO_H_
#define _REGISTRO_H_
#include <string>
#include <iostream>
#include "Fecha.h"
#include "IP.h"

using std::to_string;
using std::string;

class Registro{
  protected:
    Fecha date;
    string error, log;
    IP ip;
  public:
    Registro();
    Registro(Fecha date, IP ip, string error);
    Fecha getFecha();
    IP getIP();
    string getLog();
    void setAccess(int val);
};

Registro::Registro(){
  Fecha fecha;
  IP ip;
  Registro(fecha, ip, "Error");
}

Registro::Registro(Fecha date, IP ip, string error){
  this->date = date;
  this->ip = ip;
  this->error = error; 
}

Fecha Registro::getFecha(){
  return this->date;
}

IP Registro::getIP(){
  return this->ip;
}

void Registro::setAccess(int val){
  this->ip.setAccesos(val);
}

// Función para mostrar los registros en el formato correcto
string Registro::getLog(){
  string logday, loghour, logmin, logsec, cero = "0";

  logday = to_string(date.getDay());
  loghour = to_string(date.getHour());
  logmin = to_string(date.getMinute());
  logsec = to_string(date.getSecond());
  if (date.getDay() < 10)
    logday = cero + logday;
  if (date.getHour() < 10)
    loghour = cero + loghour;
  if (date.getMinute() < 10)
    logmin = cero + logmin;
  if (date.getSecond() < 10)
    logsec = cero + logsec;
  
  this->log = date.getMonth() + " " + logday + " " + loghour + ":" + logmin + ":" + logsec + " " + ip.printIP() + " " + this-> error;

  return this->log;
}


#endif