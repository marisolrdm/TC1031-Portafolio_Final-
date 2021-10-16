/*
Actividad 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
El siguiente programa lee un archivo .txt correspondiente a una bitácora con registros, los cuales son guardados en una lista doblemente ligada y posteriormente se ordenan por fecha (desde mes hasta segundos) de menor a mayor con el algoritmo quick sort. Dicho algoritmo es implementado iterativamente utilizando stacks. A partir de la lista doblemente ligada con los registros ordenados, se realiza una búsqueda de la posición de las 2 fechas que ingrese el usuario, se despliegan los registros desde la primer fecha indicada hasta la segunda y se genera un archivo de texto con ese despliegue.

Bandera de compilación recomendada: 
g++ -std=c++17 -O3 -o main *.cpp
Bandera de ejecución: 
./main

Autor: Marisol Rodríguez Mejía - A01640086
Fecha: 15/10/21
*/
#include <iostream>
#include <vector> 
#include <fstream>
#include <string>
#include <exception>
#include "DoubleLinkedList.h"
using namespace std;

int main(){
  string mes, dia0, hora0, min0, seg0, ip, puerto0, error;
  int dia, hora, min, seg, puerto, size, i, j, index1, index2, count = 0, check = 1;
  DoubleLinkedList<Registro> listaReg;

  // Lectura del archivo de entrada
  string filename("bitacora.txt");
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
    getline(file, ip, ':');
    getline(file, puerto0, ' ');
    getline(file, error);

    dia = stoi(dia0);
    hora = stoi(hora0);
    min = stoi(min0);
    seg = stoi(seg0);
    puerto = stoi(puerto0);

    Fecha fecha(mes, dia, hora, min, seg);
    Registro reg(fecha, ip, puerto, error);
    listaReg.addLast(reg);
  }
  file.close();
  listaReg.quickSort();

  while(check == 1){
    cout << endl <<"-- Ingresa los datos de la fecha de inicio de búsqueda --" << endl;
    ingresoDatos(mes, dia, hora, min, seg);
    Fecha key1(mes, dia, hora, min, seg);
    index1 = listaReg.busquedaBinaria(listaReg.getNumElements(), key1);
    cout << endl << "-- Ingresa los datos de la fecha de fin de búsqueda --" << endl;
    ingresoDatos(mes, dia, hora, min, seg);
    Fecha key2(mes, dia, hora, min, seg);
    index2 = listaReg.busquedaBinaria(listaReg.getNumElements(), key2);
    check = 2;
    if(index1 == -1 || index2 == -1){
      check = 1;
      if(index1 == -1){
        cout << endl << "Error: No se encontró la fecha de inicio buscada" << endl;
      }
      if(index2 == -1)
        cout << endl << "Error: No se encontró la fecha de fin buscada" << endl;
      cout << endl << "Ingrese 1 para volver a intentarlo o cualquier otro caracter para salir del programa: ";
      cin >> check;
      if (check != 1){
        cout << "\n. . . Programa finalizado . . .\n" << endl; 
        return 0;
      }
    }
    cout << endl;
  }
  // Escritura del archivo de salida de la búsqueda y despliegue en pantalla
  ofstream salida;
  salida.open("resultado_busqueda.txt");
  salida << "Fecha inicial: " << listaReg.getRegistro(index1).getLog() << endl;
  salida << "Fecha final: " << listaReg.getRegistro(index2).getLog() << endl << endl;

  for(i = index1; i <= index2; i++){
    string out = listaReg.getRegistro(i).getLog();
    cout << out << endl;
    count++;
    if(i == index2)
      salida << out;
    else
      salida << out << endl;
  }
  cout << endl << "--> " << count << " registros encontrados.";
  salida.close ();

  // Escritura del archivo de salida de bitácora ordenada
  ofstream salida2;
  salida2.open("bitacora_ordenada.txt");
  for(j = 0; j < listaReg.getNumElements(); j++)
      salida2 << listaReg.getRegistro(j).getLog() << endl;
  salida2.close ();
  cout << endl << "\tArchivos generados exitosamente." << endl;
  return 0;
}