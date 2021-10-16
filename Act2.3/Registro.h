#ifndef _REGISTRO_H_
#define _REGISTRO_H_
#include <string>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Registro{
  protected:
    Fecha date;
    string ip, error, log;
    int puerto;
  public:
    Registro();
    Registro(Fecha date, string ip, int puerto, string error);
    Fecha getFecha();
    string getLog();
};

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

  // Lleva a cabo el input y la validación de los datos ingresados por el usuario, Complejidad: O(n)
  void ingresoDatos(string &mes, int &dia, int &hora, int &min, int &seg){
  bool validate = false, validate2 = false, validate3 = false;
  vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  string fechainp;
  cout << "Mes (las 3 primeras letras del mes en inglés con la primera letra en mayúscula): ";
  cin >> mes;
  while(!validate){
    for(int l = 0; l < 12; l++){
      if (mes == meses[l])
      validate = true;
    }
      if(!validate){
        cout << "Escritura del mes incorrecta, vuelva a intentarlo: ";
        cin >> mes;
      }
    }
  cout << "Día (número): ";
  cin >> dia;
  validate = false;
  while(!validate){
    if(mes == "Apr" || mes == "Jun" || mes == "Sep" || mes == "Nov"){
      if(dia >= 1 && dia <= 30)
        validate = true;
    }
    else if (mes == "Feb"){
      if(dia >= 1 && dia <= 28)
        validate = true;
    }
    else{
      if(dia >= 1 && dia <= 31)
        validate = true;
    }
    if(!validate){
      cout << "Dia no válido, vuelva a intentarlo: ";
      cin >> dia;
    }
  }
  cout << "Hora [hh:mm:ss] (00:00:00 a 23:59:59): ";
  cin >> fechainp;
  hora = stoi(fechainp.substr(0,2));
  min = stoi(fechainp.substr(3,2));
  seg = stoi(fechainp.substr(6,2));
  while(!validate || !validate2 || !validate3){
    validate = false, validate2 = false, validate3 = false;
    if(hora >= 0 && hora < 24){
      validate = true;
    }
    if(min >= 0 && min < 60){
      validate2 = true;
    }
    if(seg >= 0 && seg < 60){
      validate3 = true;
    }
    if(!validate || !validate2 || !validate3){
      cout << "Hora no válida, vuelva a intentarlo: ";
      cin >> fechainp;
      hora = stoi(fechainp.substr(0,2));
      min = stoi(fechainp.substr(3,2));
      seg = stoi(fechainp.substr(6,2));
    }
  }
}

#endif