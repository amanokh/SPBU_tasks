//
// Created by amano on 17.03.2020.
//

#ifndef SPBUTASKS2020_TASK6_H
#define SPBUTASKS2020_TASK6_H
#include <iostream>
#include <cmath>


template <class T>
struct List {
    T data;
    List *next;
};

template <class T>
class Stack{
    List<T> *a;
public:
    Stack(){
        a = new List<T>;
        a = nullptr;
        auto *tmp = new List<T>;
        tmp->data = NULL;
        tmp->next = a;
        a = tmp;
    }
    void push(T num){
        auto *tmp = new List<T>;
        tmp->data = num;
        tmp->next = a;
        a = tmp;
    }
    T pull(){
        T data = a->data;
        a = a->next;
        return data;
    }
    T get(){
        return a->data;
    }
    void pop(){
        a = a->next;
    }
    void print(){
        List<T> *b = a;
        while (b){
            std::cout << b->data << " ";
            b = b->next;
        }
        std::cout << std::endl;
    }

};

double calculate(double b, double a, char operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Division by zero! Aborting...";
                exit(-1);
            }
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
};
#endif //SPBUTASKS2020_TASK6_H
