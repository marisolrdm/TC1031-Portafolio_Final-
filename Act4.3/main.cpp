/* Wenas
Actividad 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
Hola
El siguiente programa lee un archivo .txt correspondiente a una bitácora con registros, los cuales son ordenados por fecha (desde mes hasta segundos) de menor a mayor con el algoritmo merge sort. A partir de ese vector con los registros ordenados, se realiza una búsqueda de la posición de las 2 fechas que ingrese el usuario, se despliegan los registros desde la primer fecha indicada hasta la segunda y se genera un archivo de texto con ese despliegue.

Bandera de compilación recomendada: 
  g++ -std=c++17 -O3 -o main *.cpp
Bandera de ejecución:  
  ./main

Autor: Marisol Rodríguez Mejía - A01640086
       Luis Enrique Lemus Martínez - A01639698
Fecha: 23/11/21
*/
#include "Graph.h"

int main(){
  Graph ipGraph("bitacoraGrafos.txt");
  ipGraph.escribirGrados();
  ipGraph.generarTopFive();
  cout << endl;
  return 0;
}