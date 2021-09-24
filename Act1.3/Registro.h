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
#endif