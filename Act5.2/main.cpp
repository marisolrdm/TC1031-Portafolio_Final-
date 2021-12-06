/*
Actividad 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)
El siguiente programa lee y almacena los datos de una bitácora en en una lista de adyacencias (grafo dirigido) organizada por dirección IP. También crea una tabla hash donde se almacenará un resumen de la información de todas las IP.
Imprime en pantalla el número total de colisiones generadas al insertar la información en la tabla hash e implementa un método llamado getIPSummary().

Bandera de compilación recomendada: 
  g++ -std=c++17 -O3 -o main *.cpp
Bandera de ejecución:  
  ./main

Autor: Marisol Rodríguez Mejía - A01640086
       Luis Enrique Lemus Martínez - A01639698
Fecha: 30/11/21
*/
#include "Graph.h"

int main(){
  Graph ipGraph("bitacoraGrafos.txt");
  HashTable<long int,IP> ipHash(25411); // U = 2.72, alfa = 52%
  
  vector<pair<IP,vector<IP>>> adjList = ipGraph.getAdjList();
  
  ipHash.fillHash(adjList);

  cout << "\nTotal de colisiones: " << ipHash.getCollisions() << endl << endl;

  ipHash.getIPSummary(ipHash.getIPEntry());

  return 0;
}