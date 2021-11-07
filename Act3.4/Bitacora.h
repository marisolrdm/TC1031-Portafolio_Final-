#ifndef _BITACORA_H_
#define _BITACORA_H_
#include <iostream>
#include <vector> 
#include <fstream> 
#include <string> 
#include "Registro.h"
#include "MaxHeap.h"
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Bitacora{
  protected:
    vector<Registro> arr;
    void heapify(int n, int i);
  public:
    Bitacora(vector<Registro> arr);
    vector<Registro> getArr();
    void heapSort(int n);
    int contador(int max);
};

Bitacora::Bitacora(vector<Registro> arr){
  this->arr = arr;
}

vector<Registro> Bitacora::getArr(){
  return arr;
}

void Bitacora::heapify(int size, int i){
  int max = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if (l < size && arr[l].getIP() > arr[max].getIP())
    max = l;
  if (r < size && arr[r].getIP() > arr[max].getIP())
    max = r;
  if (max != i){
    swap(arr[i], arr[max]);
    heapify(size, max);
  }
}
  
// Método para realizar el ordenamiento de la bitácora, Complejidad: O(nlogn) ORDEN LINEARÍTMICO (GeeksforGeeks, 2021)
void Bitacora::heapSort(int size){
  for (int i = size/2-1; i >= 0; i--)
    heapify(size, i);
    
  for (int i = size-1; i >= 0; i--){
    swap(arr[0], arr[i]);
    heapify(i, 0);
  }
}

// Realiza el conteo del número de ataques para cada IP, Complejidad worst case: O(n)
int Bitacora::contador(int max){
  IP temp = arr[max].getIP();
  int i = max+1, count = 1;
  while(temp == arr[i].getIP()){
    count++;
    i++;
  }
  return count;
}
#endif