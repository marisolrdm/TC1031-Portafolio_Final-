/*
Actividad 3.4 - Actividad Integral de BST (Evidencia Competencia)

El siguiente programa lee un archivo .txt correspondiente a una bitácora con registros, los cuales son ordenados por fecha (desde mes hasta segundos) de menor a mayor con el algoritmo merge sort. A partir de ese vector con los registros ordenados, se realiza una búsqueda de la posición de las 2 fechas que ingrese el usuario, se despliegan los registros desde la primer fecha indicada hasta la segunda y se genera un archivo de texto con ese despliegue.

Bandera de compilación recomendada: 
g++ -std=c++17 -O3 -o main *.cpp
Bandera de ejecución: 
./main

Autor: Marisol Rodríguez Mejía - A01640086
Fecha: 06/11/21
*/
#include <iostream>
#include <vector> 
#include <fstream>
#include <string>
#include <exception>
#include "Bitacora.h"
using std::ifstream;
using std::ofstream;

int main(){
  string mes, dia0, hora0, min0, seg0, ip, puerto, error, oct1_, oct2_, oct3_, oct4_;
  int dia, hora, min, seg, oct1, oct2, oct3, oct4, size, i, index1, index2, count = 0, check = 1, max = 0, max2 = 0, vectSize;
  vector<Registro> listaReg;
  ofstream salida, salida2;
  // Lectura del archivo de entrada
  string filename("bitacoraHeap.txt");
  int counter = 0;
  ifstream file;
  file.exceptions(ifstream::failbit | ifstream::badbit);
  try{
    file.open(filename);
  }
   catch(ifstream::failure e){
    cout << "Error: no se encontró un archivo con ese nombre." << endl;
    return 0;
  }
  while (!file.eof()){
    getline(file, mes, ' ');
    getline(file, dia0, ' ');
    getline(file, hora0, ':');
    getline(file, min0, ':');
    getline(file, seg0, ' ');
    getline(file, oct1_, '.');
    getline(file, oct2_, '.');
    getline(file, oct3_, '.');
    getline(file, oct4_, ':');
    getline(file, puerto, ' ');
    getline(file, error);

    dia = stoi(dia0);
    hora = stoi(hora0);
    min = stoi(min0);
    seg = stoi(seg0);
    oct1 = stoi(oct1_);
    oct2 = stoi(oct2_);
    oct3 = stoi(oct3_);
    oct4 = stoi(oct4_);

    Fecha fecha(mes, dia, hora, min, seg);
    IP ip(oct1, oct2, oct3, oct4, puerto);
    Registro reg(fecha, ip, error);
    listaReg.push_back(reg);
  }
  file.close();
  vectSize = listaReg.size();
  Bitacora log(listaReg);
  log.heapSort(vectSize);
  listaReg = log.getArr();
  
  MaxHeap<IP> ipHeap(vectSize);
  while(max2 < vectSize){
    max = log.contador(max2);
    listaReg[max2].setAccess(max);
    ipHeap.push(listaReg[max2].getIP());
    max2 = max + max2;
  }

  salida.open("bitacora_ordenada.txt");
  for(i = 0; i < vectSize; i++){
    salida << listaReg[i].getLog();
    if(i != vectSize-1)
      salida << endl;
  }
  salida.close ();

  salida2.open("ips_con_mayor_acceso.txt");
  for(i = 1; i <= 5; i++){
    IP temp = ipHeap.pop();
    cout << endl << temp << "\t" << temp.getAccesos() << endl;
    salida2 << temp << "\t" << temp.getAccesos();
    if(i < 5)
      salida2 << endl;
  }
  salida2.close();
  cout << endl << "--> Archivos generados exitosamente." << endl;

  return 0;
}