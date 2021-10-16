#ifndef _STACK__H__
#define _STACK__H__

  #include <climits>
  #include "Node.h"

  template <class T>
  class Stack {
      private:
        Node<T>* top;
        int numElements;

      public:
        Stack();
        ~Stack();
        int getNumElements();
        void printStack();
        void push(T value);
        T pop();
        T getTop();
        bool isEmpty();   
  };

  template<class T> // Complejidad: O(1)
  Stack<T>::Stack() {
    top = NULL;
    numElements = 0;
  }
  
  template<class T> // Complejidad: O(n)
  Stack<T>::~Stack() {
    Node<T> *p, *q;
    p = top;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    top = NULL;
    numElements = 0;
  }
 
  template<class T> // Complejidad: O(1)
  int Stack<T>::getNumElements() {
    return numElements;
  }

  template<class T> // Complejidad: O(n)
  void Stack<T>::printStack() {
    Node<T> *ptr = top;
    while (ptr != NULL) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T> // Complejidad: O(1)
  void Stack<T>::push(T value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    numElements++;
  }

  template<class T> // Complejidad: O(1)
  T Stack<T>::pop() {
    //T value = -1;
    T value;
    if (top != NULL) {
      Node<T> *p = top;
      value = top->data;
      top = p->next;
      delete p;
      numElements--;
    }
    return value;
  }

  template<class T> // Complejidad: O(1)
  T Stack<T>::getTop() {
    T value = -1;
    if (top != NULL) {
      value = top->data;
    }
    return value;
  }

  template<class T> // Complejidad: O(1)
  bool Stack<T>::isEmpty() {
    bool result = false;
    if (top == NULL)
      result = true;
    return result;
  }

  #endif // _STACK__H__