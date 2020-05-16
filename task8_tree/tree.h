#include <iostream>
#include <iomanip>

#ifndef SPBUTASKS2020_TASK8_H
#define SPBUTASKS2020_TASK8_H

#endif //SPBUTASKS2020_TASK8_H

using namespace std;

struct link {
    int key;
    int weight;
    link *left, *right;
};

class Tree {
    link *head = nullptr;
public:
    Tree() = default;

    void push(int x);
    void pop(int x);
    void show();
    void showW();
    void print();
    void printInd();

private:
    link *max(link *a);
    link *min(link *a);

    void pushInternal(link **a, int x, int level);
    link *popInternal(link *a, int x);

    void printInternal(link *a);
    void printInternalInd(link *a);
    void showInternal(link *a, int n);
    void showInternalW(link *a, int n);
};
