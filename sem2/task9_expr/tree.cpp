#include <iostream>
#include <iomanip>
#include "tree.h"

//public functions
Tree::Tree(link *a){
    head = a;
}

void Tree::print() {
    printInternal(head);
}

void Tree::show() {
    showInternal(head, 0);
}

int Tree::solve() {
    return solveInternal(head);
}

//private functions

void Tree::printInternal(link *a) {
    if (a) {
        printInternal(a->left);
        printInternal(a->right);
        cout << a->key << " ";
    }
}

void Tree::showInternal(link *a, int n) {
    if (a) {
        showInternal(a->left, n + 1);
        cout << setw(n * 2) << a->key << endl;
        showInternal(a->right, n + 1);
    }
}
int Tree::solveInternal(link *a){
    if (a->left) {                  //проверяем, является ли вершина операцией
        switch (a->key){
            case '!':
                return (!solveInternal(a->left));
            case '+':
                return (solveInternal(a->left) || solveInternal(a->right));
            case '*':
                return (solveInternal(a->left) && solveInternal(a->right));
        }
    } else return (a->key - '0');
    return 0;
}


