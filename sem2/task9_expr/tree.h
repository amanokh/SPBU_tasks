#include <iostream>
#include <iomanip>
#include "link.h"

#ifndef SPBUTASKS2020_TASK8_H
#define SPBUTASKS2020_TASK8_H

#endif //SPBUTASKS2020_TASK8_H

using namespace std;

class Tree {
    link *head = nullptr;
public:
    Tree(link *a);

    void show();            //вывод дерева в консоль
    void print();           //печать ОПН обходом post-order
    int solve();            //решение выражения рекурсивным обходом по дереву

private:
    void showInternal(link *a, int n);
    void printInternal(link *a);
    int solveInternal(link *a);
};
