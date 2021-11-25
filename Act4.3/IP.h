#ifndef _IP_H_
#define _IP_H_
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class IP{
  protected:
    int oct1, oct2, oct3, oct4, grado;
    string puerto;
  public:
    IP();
    IP(int oct1, int oct2, int oct3, int oct4, string puerto);
    string printIP();
    int getGrado();
    void setGrado(int val);
    void updateGrado();
    bool operator ==(const IP &other);
    bool operator >(const IP &other);
    bool operator <(const IP &other);
    bool operator <=(const IP &other);
    friend ostream& operator<<(ostream& os, const IP& ip);
};

IP::IP(){
  IP(0, 0, 0, 0, "0000");
}

IP::IP(int oct1, int oct2, int oct3, int oct4, string puerto){
  this->oct1 = oct1;
  this->oct2 = oct2;
  this->oct3 = oct3;
  this->oct4 = oct4;
  this->puerto = puerto;
  this->grado = 0;
}

string IP::printIP(){
  string IPstr = to_string(oct1) + "." + to_string(oct2) + "." + to_string(oct3) + "." + to_string(oct4) + ":" + puerto;
  return IPstr;
}

int IP::getGrado(){
  return this->grado;
}

void IP::setGrado(int val){
  this->grado = val;
}

void IP::updateGrado(){
  this->grado++;
}

bool IP::operator==(const IP &other){
  if(this->oct1 != other.oct1)
    return false;
  else if(this->oct2 != other.oct2)
    return false;
  else if(this->oct3 != other.oct3)
    return false;
  else if(this->oct4 != other.oct4)
    return false;
  else
    return true;
}

bool IP::operator>(const IP &other){
  if(*this == other)
    return false;
  else if(this->oct1 > other.oct1)
    return true;
  else if(this->oct1 < other.oct1)
      return false;
  else if(this->oct2 > other.oct2)
    return true;
  else if(this->oct2 < other.oct2)
      return false;
  else if(this->oct3 > other.oct3)
    return true;
  else if(this->oct3 < other.oct3)
      return false;
  else if(this->oct4 > other.oct4)
    return true;
  else if(this->oct4 < other.oct4)
      return false;
  else
    return false;
}

bool IP::operator<(const IP &other){
  if(*this == other)
    return false;
  else if(this->oct1 < other.oct1)
    return true;
  else if(this->oct1 > other.oct1)
      return false;
  else if(this->oct2 < other.oct2)
    return true;
  else if(this->oct2 > other.oct2)
      return false;
  else if(this->oct3 < other.oct3)
    return true;
  else if(this->oct3 > other.oct3)
      return false;
  else if(this->oct4 < other.oct4)
    return true;
  else if(this->oct4 > other.oct4)
      return false;
  else
    return false;
}

bool IP::operator<=(const IP &other){
  if(*this == other)
    return true;
  else if(this->oct1 < other.oct1)
    return true;
  else if(this->oct1 > other.oct1)
      return false;
  else if(this->oct2 < other.oct2)
    return true;
  else if(this->oct2 > other.oct2)
      return false;
  else if(this->oct3 < other.oct3)
    return true;
  else if(this->oct3 > other.oct3)
      return false;
  else if(this->oct4 < other.oct4)
    return true;
  else if(this->oct4 > other.oct4)
      return false;
  else
    return false;
}

ostream& operator<<(ostream& os, const IP& ip){
    os << to_string(ip.oct1) + "." + to_string(ip.oct2) + "." + to_string(ip.oct3) + "." + to_string(ip.oct4);
    return os;
}

#endif