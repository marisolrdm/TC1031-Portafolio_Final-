#include "Registro.h"

Registro::Registro(){
  Fecha fecha;
  Registro(fecha, "960.96.3.29", 123, "Error");
}

Registro::Registro(Fecha date, string ip, int puerto, string error){
  this->date = date;
  this->ip = ip;
  this->puerto = puerto;
  this->error = error; 
}

Fecha Registro::getFecha(){
  return this->date;
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
  
  this->log = date.getMonth() + " " + logday + " " + loghour + ":" + logmin + ":" + logsec + " " + this->ip + ":" + to_string(this->puerto) + " " + this-> error;

  return this->log;
}