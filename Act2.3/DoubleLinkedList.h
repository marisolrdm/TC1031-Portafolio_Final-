#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <climits>
  #include "Node.h"
  #include "Stack.h"
  #include "Registro.h"
  using namespace std;

  template <class T>
  class DoubleLinkedList{
    private:
      Node<T>* head;
      Node<T>* tail;
      int numElements;

    public:
      DoubleLinkedList();
      ~DoubleLinkedList();
      int getNumElements();
      Node<T>* getNode(int pos);
      Registro getRegistro(int position);
      void addFirst(T value);
      void addLast(T value);
      bool deleteData(T value);
      int busquedaBinaria(int n, Fecha search);
      void quickSort();
  };

  template<class T> // Complejidad: O(1)
  DoubleLinkedList<T>::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
  
  template<class T> // Complejidad: O(n)
  DoubleLinkedList<T>::~DoubleLinkedList(){
    Node<T> *p, *q;
    p = head;
    while (p != NULL){
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
 
  template<class T> // Complejidad: O(1)
  int DoubleLinkedList<T>::getNumElements(){
    return numElements;
  }

  template<class T> // Complejidad: O(n)
  Node<T>* DoubleLinkedList<T>::getNode(int pos){
    Node<T>* result = head;
    for(int i = 0; result != NULL; i++){
      if(i == pos)
        break;
      result = result->next;
    }
    return result;
  }

  template<class T> // Complejidad: O(n)
  Registro DoubleLinkedList<T>::getRegistro(int position){
   return this->getNode(position)->data;
  }

  template<class T> // Complejidad: O(1)
  void DoubleLinkedList<T>::addFirst(T value){
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL){
      head = newNode;
      tail = newNode;
    }
    else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T> // Complejidad: O(1)
  void DoubleLinkedList<T>::addLast(T value){
    if (head == NULL){
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }
  
  template<class T> // Complejidad: O(n)
  bool DoubleLinkedList<T>::deleteData(T value){
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL)
      return false;
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value){
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL){
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL){ 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else{
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  // GeeksforGeeks. (2021). QuickSort on Doubly Linked List. Recuperado de: https://www.geeksforgeeks.org/quicksort-for-linked-list/
  template<class T> // Función que intercambia dos elementos, Complejidad: O(1)
  void swap ( T* a, T* b ){ 
    T t = *a; *a = *b; *b = t; 
  }
 
  // GeeksforGeeks. (2021). QuickSort on Doubly Linked List. Recuperado de: https://www.geeksforgeeks.org/quicksort-for-linked-list/
  template<class T> // Función que va partiendo la lista a la mitad a partir de un nodo, Complejidad: O(n)
  Node<T>* partition(Node<T> *head_, Node<T> *h){
    Fecha x = h->data.getFecha();
    Node<T> *i = head_->prev;
    for (Node<T> *j = head_; j != h; j = j->next){
      if (j->data.getFecha() <= x){
        i = (i == NULL)? head_ : i->next;
        swap(&(i->data), &(j->data));
      }
    }
    i = (i == NULL)? head_ : i->next;
    swap(&(i->data), &(h->data));;
    return i;
  }

  // GeeksforGeeks. (2021). Iterative Quick Sort. Recuperado de: https://www.geeksforgeeks.org/iterative-quick-sort/
  template<class T> // Realiza el ordenamiento iterativo por fechas utilizando un stack, Complejidad promedio: O(nlogn)
  void DoubleLinkedList<T>::quickSort(){
    Node<T>* head_ = this->head;
    Node<T>* tail_ = this->tail;
    Stack<Node<T>*> myStack;

    myStack.push(head_);
    myStack.push(tail_);

    while (!myStack.isEmpty()){
      tail_ = myStack.pop();
      head_ = myStack.pop();
      Node<T>* p = partition(head_, tail_);
      if (head_->data.getFecha() < p->data.getFecha()){
        myStack.push(head_);
        myStack.push(p->prev);
      }
      if (p->data.getFecha() < tail_->data.getFecha()){
        myStack.push(p->next);
        myStack.push(tail_);
      }
    }
  }

  // Realiza la búsqueda recibiendo una llave tipo Fecha, Complejidad worst case: O(logn)
  template<class T>
  int DoubleLinkedList<T>::busquedaBinaria(int n, Fecha search){
    int low = 0, high = n - 1;
    while (low <= high){
      int m = low + (high - low) / 2;
      if (search == this->getRegistro(m).getFecha()) 
          return m;
      else if (search < this->getRegistro(m).getFecha()) 
          high = m - 1;
      else 
          low = m + 1;
    }
    return -1;
  }

#endif // _DOUBLELINKEDLIST_H_