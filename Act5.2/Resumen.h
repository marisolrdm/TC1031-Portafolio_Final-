#ifndef _RESUMEN_H_
#define _RESUMEN_H_
using namespace std;

class Resumen{
  private:
    string IPstr;
    int numOut, numIn;
  public:
    Resumen();
    Resumen(string IPstr);
    string getIPstr();
    int getNumOut();
    int getNumIn();
    void updateNumOut();
    void updateNumIn();
    void printResumen();
};

Resumen::Resumen(){
  this->IPstr = "0.0.0.0";
  this->numOut = 0;
  this->numIn = 0;
}

Resumen::Resumen(string IPstr){
  this->IPstr = IPstr;
  this->numOut = 0;
  this->numIn = 0;
}

string Resumen::getIPstr(){
  return this->IPstr;
}

int Resumen::getNumOut(){
  return this->numOut;
}

int Resumen::getNumIn(){
  return this->numIn;
}

void Resumen::updateNumOut(){
  this->numOut++;
}

void Resumen::updateNumIn(){
  this->numIn++;
}

void Resumen::printResumen(){
  cout << "\n-> Dirección IP: " << IPstr << "\nTotal de direcciones que intentaron acceder a la IP: " << numIn << "\nTotal de direcciones accesadas desde la IP: " << numOut << endl;
}

#endif