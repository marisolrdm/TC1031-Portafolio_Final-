#ifndef _IP_H_
#define _IP_H_
#include <iostream>
#include <string>
using std::string;
using std::to_string;
using namespace std;

class IP{
  protected:
    int oct1, oct2, oct3, oct4, accesos;
    string puerto;
  public:
    IP();
    IP(int oct1, int oct2, int oct3, int oct4, string puerto);
    string printIP();
    int getAccesos();
    void setAccesos(int val);
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
  this->accesos = 1;
}

string IP::printIP(){
  string IPstr = to_string(oct1) + "." + to_string(oct2) + "." + to_string(oct3) + "." + to_string(oct4) + ":" + puerto;
  return IPstr;
}

int IP::getAccesos(){
  return this->accesos;
}

void IP::setAccesos(int val){
  this->accesos = val;
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
    os << to_string(ip.oct1) + "." + to_string(ip.oct2) + "." + to_string(ip.oct3) + "." + to_string(ip.oct4) + ":" + ip.puerto;
    return os;
}

#endif