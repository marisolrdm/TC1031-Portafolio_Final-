#ifndef __GRAPH_H_
#define __GRAPH_H_
#include <vector>
#include <fstream>
#include <utility> 
#include <exception>
#include "IP.h"
#include "HashTable.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    vector<pair<IP,vector<IP>>> adjList;
    void loadDirectedGraph(string filename);
    void heapify(int n, int i);
    void heapSort();
    int busquedaBinaria(IP search);
    
  public:
    Graph(string filename);
    ~Graph();
    vector<pair<IP,vector<IP>>> getAdjList();
};

// Complejidad: O(n)
Graph::Graph(string filename) {
    loadDirectedGraph(filename);
}

// Complejidad: O(n)
Graph::~Graph() {
  adjList.clear();
}

// Lee el archivo de entrada, lo almacena en la lista de adyancencia y manda a llamar a heapSort() para después hacer una búsqueda binaria de las IPs, Complejidad: O(n)
void Graph::loadDirectedGraph(string filename) {
  string mes, dia0, hora0, min0, seg0, puerto, error, oct1_, oct2_, oct3_, oct4_, octa1_, octa2_, octa3_, octa4_, puerto2;
  int oct1, oct2, oct3, oct4, octa1, octa2, octa3, octa4, i = 0;
  string numEdges_;
  string numNodes_;
  vector<IP> adj;
  ifstream file;
  file.exceptions(ifstream::failbit | ifstream::badbit);
  try{
    file.open(filename);
  }
   catch(ifstream::failure e){
    cout << "Error: no se encontró un archivo con ese nombre." << endl;
    return;
  }
  while (!file.eof()){
    if(i == 0){
      getline(file, numNodes_, ' ');
      getline(file, numEdges_, '\n');
      this->numNodes = stoi(numNodes_);
      this->numEdges = stoi(numEdges_);
      i++;
      continue;
    }
    if(i <= numNodes){
      getline(file, oct1_, '.');
      getline(file, oct2_, '.');
      getline(file, oct3_, '.');
      getline(file, oct4_, '\n');
      oct1 = stoi(oct1_);
      oct2 = stoi(oct2_);
      oct3 = stoi(oct3_);
      oct4 = stoi(oct4_);
      IP ip(oct1,oct2,oct3,oct4,"0");
      adjList.push_back(make_pair(ip,adj));
      i++;
      continue; 
    }
    if(i == numNodes+1){
      heapSort();
    }
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
    getline(file, octa1_, '.');
    getline(file, octa2_, '.');
    getline(file, octa3_, '.');
    getline(file, octa4_, ':');
    getline(file, puerto2, ' ');
    getline(file, error);

    oct1 = stoi(oct1_);
    oct2 = stoi(oct2_);
    oct3 = stoi(oct3_);
    oct4 = stoi(oct4_);
    octa1 = stoi(octa1_);
    octa2 = stoi(octa2_);
    octa3 = stoi(octa3_);
    octa4 = stoi(octa4_);

    IP ip1(oct1, oct2, oct3, oct4, puerto);
    IP ip2(octa1, octa2, octa3, octa4, puerto2);

    int pos = busquedaBinaria(ip1);
    int pos2 = busquedaBinaria(ip2);
    adjList[pos].second.push_back(ip2);
    adjList[pos].first.updateResumenNumOut();
    adjList[pos2].first.updateResumenNumIn();
    
    i++;
  }
  file.close();
}
// Compleidad: O(1)
vector<pair<IP,vector<IP>>> Graph::getAdjList(){
  return this->adjList;
}

void Graph::heapify(int size, int i){
  int max = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if (l < size && adjList[l].first > adjList[max].first)
    max = l;
  if (r < size && adjList[r].first > adjList[max].first)
    max = r;
  if (max != i){
    swap(adjList[i], adjList[max]);
    heapify(size, max);
  }
}
  
// Método para realizar el ordenamiento de la bitácora, Complejidad: O(nlogn)
void Graph::heapSort(){
  int size = numNodes;
  for (int i = size/2-1; i >= 0; i--)
    heapify(size, i);
    
  for (int i = size-1; i >= 0; i--){
    swap(adjList[0], adjList[i]);
    heapify(i, 0);
  }
}

// Realiza la búsqueda recibiendo una llave tipo IP, Complejidad worst case: O(logn)
int Graph::busquedaBinaria(IP search){
  int low = 0, high = numNodes - 1;
  while (low <= high){
    int m = low + (high - low) / 2;
    if (search == adjList[m].first) 
        return m;
    else if (search < adjList[m].first) 
        high = m - 1;
    else 
        low = m + 1;
  }
  return -1;
}



#endif // __GRAPH_H_