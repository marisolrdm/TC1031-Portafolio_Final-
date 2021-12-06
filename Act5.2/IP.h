#ifndef _IP_H_
#define _IP_H_
#include <iostream>
#include <string>
#include <math.h>
#include "Resumen.h"
using namespace std;

class IP{
  protected:
    int oct1, oct2, oct3, oct4;
    long val;
    vector<IP> adjIP;
    string puerto;
    Resumen resumen;
  public:
    IP();
    IP(int oct1, int oct2, int oct3, int oct4, string puerto);
    Resumen getResumen();
    long getVal();
    void updateResumenNumOut();
    void updateResumenNumIn();
    void ordenaMerge(int l, int r);
    void merge(int l, int r, int m);
    void setAdjIP(vector<IP> adj);
    vector<IP> getAdjIP();
    void crearResumen();
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
  string IPstr = to_string(oct1) + "." + to_string(oct2) + "." + to_string(oct3) + "." + to_string(oct4);
  this->resumen = Resumen(IPstr);
  this->val = (oct1*pow(256,3)) + (oct2*pow(256,2)) + (oct3*pow(256,1)) + (oct4*pow(256,0));
}

Resumen IP::getResumen(){
  return this->resumen;
}

long IP::getVal(){
  return this->val;
}

void IP::updateResumenNumOut(){
  this->resumen.updateNumOut();
}

void IP::updateResumenNumIn(){
  this->resumen.updateNumIn();
}

void IP::merge(int l, int r, int m){ 
  int size1 = m - l + 1;
  int size2 = r - m; 
  vector<IP> leftArray, rightArray; 
  // Copias de los vectores
  for(int i = 0; i < size1; i++){ 
    leftArray.push_back(adjIP[l+i]);
  } 
  for(int j = 0; j < size2; j++){ 
    rightArray.push_back(adjIP[m+j+1]); 
  }  
  // Merge 
  int i = 0; 
  int j = 0; 
  int k = l;
  while(i < size1 && j < size2){ 
    if(leftArray[i] <= rightArray[j]){ 
      adjIP[k] = leftArray[i]; 
      i++;
    } 
    else{ 
      adjIP[k] = rightArray[j]; 
      j++; 
    } 
    k++;
  }  
  // Agregar elementos restantes
  while(j < size2){ 
  adjIP[k] = rightArray[j]; 
  j++; 
  k++;
  }
  while(i < size1){ 
    adjIP[k] = leftArray[i]; 
    i++; 
    k++;
  }  
}      

// Función para realizar el acomodo merge,  Complejidad: O(nlogn) ORDEN LINEARÍTMICO
void IP::ordenaMerge(int l, int r){ 
  if(l < r){ 
    int m = l + (r - l)/2; 
    ordenaMerge(l, m); 
    ordenaMerge(m+1,r); 
    merge(l,r,m);
  } 
}

void IP::setAdjIP(vector<IP> adj){
  this->adjIP = adj;
}

vector<IP> IP::getAdjIP(){
  return this->adjIP;
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