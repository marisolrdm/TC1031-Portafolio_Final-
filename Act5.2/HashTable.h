#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include "IP.h"

template<class K, class T>
class HashTable {
  private:
    vector<HashNode<K,T>> table;
    int size, collisions;
    int maxSize;

  public:
    HashTable(int selectedMaxSize);
    void fillHash(vector<pair<IP,vector<IP>>>& list);
    void getIPSummary(IP ip);
    IP getIPEntry();
    vector<HashNode<K,T>> getTable();
    int getHashIndex(K keyVal);
    int getSize();
    int getCollisions();
    void print();
    void add(K keyVal, T value);
    int find(K keyVal);
    T getDataAt(int index);
    void remove(K keyVal);
};

// Compleidad: O(1)
template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) {
  maxSize = selectedMaxSize;
  size = 0;
  table = vector<HashNode<K,T>>(maxSize);
}

// Llena un objeto tipo HasTable con los datos obtenidos de la lista de adyacencia, es decir, el grafo. Compleidad: O(n)
template<class K, class T>
void HashTable<K, T>::fillHash(vector<pair<IP,vector<IP>>>& list) {
  for(int i = 0; i < list.size(); i++){
    list[i].first.setAdjIP(list[i].second);
    add(list[i].first.getVal(), list[i].first);
  }
}

// Valida la IP ingresada por el usuario y muestra sus respectivos datos, incluyendo su resumen y sus adyancencias ordenadas. Complejidad: O(n)
template<class K, class T>
void HashTable<K,T>::getIPSummary(IP ipKey){
  int index = find(ipKey.getVal());
  if(index == -1){
    cout << "La IP ingresada no existe en la bitácora.\n";
    return;
  }
  IP ip = getDataAt(index);
  ip.ordenaMerge(0, ip.getAdjIP().size()-1);
  vector<IP> adjIP = ip.getAdjIP();
  ip.getResumen().printResumen();
  cout << "\nLista de direcciones accesadas " << endl;
  for(int i = 0; i < adjIP.size(); i++){
    cout << adjIP[i] << endl;
  }
}

template<class K, class T>
IP HashTable<K,T>::getIPEntry(){
  int oct1, oct2, oct3, oct4;
  cout << "Ingresa el primer octeto (dígitos antes del primer punto): ";
  cin >> oct1;
  while(oct1 < 0 || oct1 > 255){
    cout << "Dígitos incorrectos, por favor ingresar un número del 0 al 255: ";
    cin >> oct1;
  }
  cout << "Ingresa el segundo octeto (dígitos antes del segundo punto): ";
  cin >> oct2;
  while(oct2 < 0 || oct2 > 255){
    cout << "Dígitos incorrectos, por favor ingresar un número del 0 al 255: ";
    cin >> oct2;
  }
  cout << "Ingresa el tercer octeto (dígitos antes del último punto): ";
  cin >> oct3;
  while(oct3 < 0 || oct3 > 255){
    cout << "Dígitos incorrectos, por favor ingresar un número del 0 al 255: ";
    cin >> oct3;
  }
  cout << "Ingresa el cuarto octeto (dígitos después del último punto): ";
  cin >> oct4;
  while(oct4 < 0 || oct4 > 255){
    cout << "Dígitos incorrectos, por favor ingresar un número del 0 al 255: ";
    cin >> oct4;
  }
  IP ip(oct1, oct2, oct3, oct4, "0");

  return ip;
}

template<class K, class T>
vector<HashNode<K,T>> HashTable<K, T>::getTable() {
  return table;
}

template<class K, class T>
int HashTable<K,T>::getHashIndex(K keyVal) {
  return keyVal % maxSize;
}

template<class K, class T>
int HashTable<K,T>::getSize() {
  return size;
}

template<class K, class T>
int HashTable<K,T>::getCollisions() {
  return collisions;
}

template<class K, class T>
void HashTable<K,T>::print() {
  std::cout << "Content of the hash table: " << std::endl;
  for (int i = 0; i < maxSize; i++) {
    if (table.at(i).getStatus()==1) // Cell is used
      std::cout << "Cell: " << i << " Key: " << table.at(i).getKey() << ", Value: " << table.at(i).getData() << ", Overflow.size: " << table.at(i).getOverflowSize() << std::endl;
  }
}

// Complejidad: O(k)
template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {
  if (size == maxSize) {
    throw std::out_of_range("Hash Table is full");
  }
  // Compute the index of the table using a key and a hash function
  int hashVal = getHashIndex(keyVal);
  HashNode<K, T> node = table.at(hashVal);
  // The cell in the table is not taken
  if (node.getStatus() != 1) {
    node.setKey(keyVal);
    node.setData(value);
    table.at(hashVal) = node;
  }
  else { // The cell in the table is already taken
    // Find next free space using quadratic probing
    int i = 1;
    int currentHashVal = getHashIndex(hashVal + i * i);
    HashNode<K, T> currentNode = table.at(currentHashVal);
    while (currentNode.getStatus() == 1) {
      i++;
      currentHashVal = getHashIndex(hashVal + i * i);
      currentNode = table.at(currentHashVal);
      collisions++;
    }
    currentNode.setKey(keyVal);
    currentNode.setData(value);
    node.addToOverflow(currentHashVal);
    table.at(currentHashVal) = currentNode;
    table.at(hashVal) = node;
    collisions++;
  }
  size++;
}  

template<class K, class T>
int HashTable<K,T>::find(K keyVal) {
  int hashVal = getHashIndex(keyVal); 
  HashNode<K, T> node = table.at(hashVal);
  // Cell in the table is taken
  if (node.getStatus() == 1) {
    if (node.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < node.getOverflowSize(); i++) {
      int overflowIndex = node.getOverflowAt(i);
      if (table.at(overflowIndex).getKey() == keyVal) {
        return overflowIndex;
      }
    }
    return -1;
  }
  return -1;
}

// Compleidad: O(1)
template<class K, class T>
T HashTable<K,T>::getDataAt(int index) {
  return table.at(index).getData();
}

template<class K, class T>
void HashTable<K,T>::remove(K keyVal) {
  int pos, hashVal;
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash table");
  }
  hashVal = getHashIndex(keyVal);
  if (pos != hashVal) {
    HashNode<K, T> node = table.at(hashVal);
    node.removeFromOverflow(pos);
    table.at(hashVal) = node;
  }
  table.at(pos).clearData(); 
}


#endif // __HASH_TABLE_H_

