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

    T pull();
    T get();

    void push(T num);
    void pop();
    void print();

};

double calculate(int a, int b, char operation);

#include "stack.inc"
#endif
