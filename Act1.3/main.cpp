/*
Actividad 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
El siguiente programa lee un archivo .txt correspondiente a una bitácora con registros, los cuales son ordenados por fecha (desde mes hasta segundos) de menor a mayor con el algoritmo merge sort. A partir de ese vector con los registros ordenados, se realiza una búsqueda de la posición de las 2 fechas que ingrese el usuario, se despliegan los registros desde la primer fecha indicada hasta la segunda y se genera un archivo de texto con ese despliegue.

Bandera de compilación recomendada: g++ -std=c++17 -O3 -o main *.cpp
Bandera de ejecución: ./main

Autor: Marisol Rodríguez Mejía - A01640086
Fecha: 24/09/21
*/
#include <iostream>
#include <vector> 
#include <fstream> 
#include <string> 
#include "Registro.h"
using namespace std;

void merge(vector<Registro> &arr, int l, int r, int m){ 
  int size1 = m - l + 1;
  int size2 = r - m; 
  vector<Registro> leftArray, rightArray; 
  // Copias de los vectores
  for(int i = 0; i < size1; i++){ 
    leftArray.push_back(arr[l+i]);
  } 
  for(int j = 0; j < size2; j++){ 
    rightArray.push_back(arr[m+j+1]); 
  }  
  // Merge 
  int i = 0; 
  int j = 0; 
  int k = l;
  while(i < size1 && j < size2){ 
    if(leftArray[i].getFecha() <= rightArray[j].getFecha()){ 
      arr[k] = leftArray[i]; 
      i++;
    } 
    else{ 
      arr[k] = rightArray[j]; 
      j++; 
    } 
    k++;
  }  
  // Agregar elementos restantes
  while(j < size2){ 
  arr[k] = rightArray[j]; 
  j++; 
  k++;
  }
  while(i < size1){ 
    arr[k] = leftArray[i]; 
    i++; 
    k++;
  }  
}      

// Función para realizar el acomodo merge, Complejidad: O(nlogn) ORDEN LINEARÍTMICO
void ordenaMerge(vector<Registro> &arr, int l, int r){ 
  if(l < r){ 
    int m = l + (r - l)/2; 
    ordenaMerge(arr, l, m); 
    ordenaMerge(arr,m+1,r); 
    merge(arr,l,r,m);
  } 
} 

// Realiza la búsqueda recibiendo una llave tipo Fecha, Complejidad worst case: O(logn) ORDEN LOGARÍTMICO
int busquedaBinaria(vector<Registro>& arr, int n, Fecha search){
  int low = 0, high = n - 1;
  while (low <= high){
    int m = low + (high - low) / 2;
    if (search == arr[m].getFecha()) 
        return m;
    else if (search < arr[m].getFecha()) 
        high = m - 1;
    else 
        low = m + 1;
  }
  return -1;
}

// Función para pedir ambas fechas buscadas y validar las entradas del usuario
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

int main(){
  string mes, dia0, hora0, min0, seg0, ip, puerto0, error;
  int dia, hora, min, seg, puerto, size, i, index1, index2, count = 0, check = 1;;
  vector<Registro> listaReg;
  // Lectura del archivo de entrada
  ifstream file("bitacora.txt");
  int counter = 0;
  if(file.is_open()){
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
      listaReg.push_back(reg);
    }
  }
  else
    cout << "No se encontró un archivo con ese nombre" << endl;
  ordenaMerge(listaReg, 0, listaReg.size()-1);

  while(check == 1){
    cout << endl <<"-- Ingresa los datos de la fecha de inicio de búsqueda --" << endl;
    ingresoDatos(mes, dia, hora, min, seg);
    Fecha key1(mes, dia, hora, min, seg);
    index1 = busquedaBinaria(listaReg, listaReg.size(), key1);
    cout << endl << "-- Ingresa los datos de la fecha de fin de búsqueda --" << endl;
    ingresoDatos(mes, dia, hora, min, seg);
    Fecha key2(mes, dia, hora, min, seg);
    index2 = busquedaBinaria(listaReg, listaReg.size(), key2);
    check = 2;
    if(index1 == -1 || index2 == -1){
      check = 1;
      if(index1 == -1){
        cout << endl << "Error: No se encontró la fecha de inicio buscada" << endl;
      }
      if(index2 == -1)
        cout << endl << "Error: No se encontró la fecha de fin buscada" << endl;
      cout << endl << "Ingrese 1 para volver a intentarlo y 2 para salir del programa: ";
      cin >> check;
      if (check != 1)
        cout << "\n. . . Programa finalizado . . .\n" << endl; 
        return 0;
    }
    cout << endl;
  }
  for(i = index1; i <= index2; i++){
    cout << listaReg[i].getLog() << endl;
    count++;
  }
  cout << endl << "--> " << count << " registros encontrados";

  // Escritura de archivo de salida
  ofstream salida;
  salida.open ("bitacora_ordenada.txt");
  salida << "Fecha inicial: " << listaReg[index1].getLog() << endl;
  salida << "Fecha final: " << listaReg[index2].getLog() << endl << endl;
  for(i = index1; i <= index2; i++)
    if(i == index2)
      salida << listaReg[i].getLog();
    else
      salida << listaReg[i].getLog() << endl;
  salida.close ();
  cout << ", archivo generado exitosamente." << endl;

  return 0;
}