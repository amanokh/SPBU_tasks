#include "stack.h"
#include "link.h"
#include <iostream>
#include <cmath>

template<class T>
Stack<T>::Stack(){
    a = new List<T>;
    a->data = NULL;
    a->next = nullptr;
}

template<class T>
void Stack<T>::push(T num) {
    auto *tmp = new List<T>;
    tmp->data = num;
    tmp->next = a;
    a = tmp;
}

template<class T>
T Stack<T>::pull() {
    List<T> *b = a;
    T data = a->data;
    a = a->next;
    delete b;
    return data;
}

template<class T>
T Stack<T>::get() {
    return a->data;
}

template<class T>
void Stack<T>::pop() {
    List<T> *b = a;
    a = a->next;
    delete b;
}

template<class T>
void Stack<T>::print() {
    List<T> *b = a;
    while (b) {
        std::cout << b->data << " ";
        b = b->next;
    }
    std::cout << std::endl;
}

link* connect(link *a, link *b, char operation) {
    link *tmp = new link;
    switch (operation) {
        case '+':
            tmp->key = operation;
            tmp->left = a;
            tmp->right = b;
            return tmp;
        case '*':
            tmp->key = operation;
            tmp->left = a;
            tmp->right = b;
            return tmp;
        case '!':
            tmp->key = operation;
            tmp->left = a;
            tmp->right = nullptr;
            return tmp;
        default:
            return nullptr;
    }
};
