//
// Created by amano on 17.03.2020.
//
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cmath>


template <class T>
struct List {
    T data;
    List *next;
};

template <class T>
class Stack {
private:
    List<T> *a;
public:
    Stack();

    T pull();               //получить элемент и удалить
    T get();                //получить элемент

    void push(T num);
    void pop();
    void print();

};

link *connect(link *a, link *b, char operation);  //создать поддерево, где вершина - операция

#include "stack.inc"
#endif
