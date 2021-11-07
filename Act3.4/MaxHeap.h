#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include<vector>
  #include<iostream>
  #include <stdexcept>
  #include "IP.h"
  using namespace std;

  template<class T>
  class MaxHeap {
    private:
      // contiene los elementos del heap
      vector<T> data;
      int maxSize;
      int sizeH;
      int parent(int i);
      int left(int i);
      int right(int i);
      void down(int i);

    public:
      MaxHeap(int capacity);
      ~MaxHeap();
      bool empty();
      int size();
      int getCapacity();
      void printMaxHeap();
      void push(T key);
      T top();
      T pop();
  };

  template <class T> // Complejidad: O(n)
  MaxHeap<T>::MaxHeap(int capacity) {
      sizeH = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> // Complejidad: O(n)
  MaxHeap<T>::~MaxHeap() {
      data.clear();
  }
  
  template <class T> // Complejidad: O(1)
  bool MaxHeap<T>::empty() {
    return (sizeH <= 0);
  }

  template <class T> // Complejidad: O(1)
  int MaxHeap<T>::size() {
    return sizeH;
  }

  template <class T> // Complejidad: O(1)
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T> // Complejidad: O(n)
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < sizeH; i++)
      cout << data[i] << " ";
    cout << endl;
  }

  template <class T> // Complejidad: O(1)
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> // Complejidad: O(1)
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> // Complejidad: O(1)
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T> // Inserta un elemento en el heap, Complejidad: O(logn)
  void MaxHeap<T>::push(T key) {
    if (sizeH == maxSize) {
        cout << "Overflow: no se puede insertar la llave " << key << endl;
        return;
    }
    int i = sizeH;
    data[i] = key;
    sizeH++;
    while (i != 0 && data[parent(i)].getAccesos() < data[i].getAccesos()) {
       swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }

  template <class T> // Complejidad: O(1)
  T MaxHeap<T>::top() {
    IP ip;
    T result = ip;
    if (empty()) {
        cout << "El MaxHeap está vacio" << endl;
        return result;
    }
    return data[0];
  }

  template <class T> // Acomoda el arreglo recursivamente, Complejidad: O(logn)
  void MaxHeap<T>::down(int i){
    int maxPos = i;
    if(left(i) <= sizeH && data[left(i)].getAccesos() > data[maxPos].getAccesos()){
      maxPos = left(i);
    }
    if(right(i) <= sizeH && data[right(i)].getAccesos() > data[maxPos].getAccesos())
      maxPos = right(i);
    if (i != maxPos){
      swap(data[i], data[maxPos]);
      down(maxPos);
    }
  }

  template <class T> // Regresa y elimina la raíz, Complejidad: O(logn)
  T MaxHeap<T>::pop(){
    if(empty())
      cout << "El MaxHeap está vacio" << endl;
    T final = data[0];
    data[0] = data[sizeH - 1];
    sizeH = sizeH - 1;
    down(0);
    return final;
  }

#endif // __MAXHEAP_H_