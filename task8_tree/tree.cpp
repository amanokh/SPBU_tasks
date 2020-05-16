#include <iostream>
#include <iomanip>
#include "tree.h"

//public functions

void Tree::push(int x) {
    pushInternal(&head, x, 0);
}

void Tree::pop(int x) {
    popInternal(head, x);
}

void Tree::print() {
    printInternal(head);
}

void Tree::show() {
    showInternal(head, 0);
}

void Tree::showW() {
    showInternalW(head, 0);
}

void Tree::printInd() {
    printInternalInd(head);
    cout << endl;
}

//private functions

link *Tree::max(link *a) {
    if (a->right) return max(a->right);
    else return a;
}

link *Tree::min(link *a) {
    if (a->left) return min(a->left);
    else return a;
}

void Tree::pushInternal(link **a, int x, int level) {
    link *b = *a;
    if (b) {
        if (x < b->key) {
            pushInternal(&b->left, x, ++level);
        } else {
            pushInternal(&b->right, x, ++level);
        }
    } else {
        *a = new link;
        (*a)->key = x;
        (*a)->weight = rand() % 3 - 1;
        (*a)->left = nullptr;
        (*a)->right = nullptr;
    }
}

link *Tree::popInternal(link *a, int x) {
    if (!a) return nullptr;
    if (a->key < x) a->right = popInternal(a->right, x);
    else if (a->key > x) a->left = popInternal(a->left, x);
    else {
        if (a->left && a->right) {
            a->key = max(a->left)->key;
            a->weight = max(a->left)->weight;
            a->left = popInternal(a->left, a->key);
        } else if (a->left) return a->left;
        else if (a->right) return a->right;
        else return nullptr;
    }
    return a;
}

void Tree::printInternal(link *a) {
    if (a) {
        cout << a->key << " ";
        printInternal(a->left);
        printInternal(a->right);
    }
}

void Tree::printInternalInd(link *a) {
    if (a) {
        printInternalInd(a->left);
        int l = a->left ? 1 : 0;
        int r = a->right ? 1 : 0;
        if (a->weight && (l + r) == 1) cout << a->key << "(" << a->weight << ") ";
        printInternalInd(a->right);
    }
}

void Tree::showInternal(link *a, int n) {
    if (a) {
        showInternal(a->left, n + 1);
        cout << setw(n * 3) << a->key << endl;
        showInternal(a->right, n + 1);
    }
}

void Tree::showInternalW(link *a, int n) {
    if (a) {
        showInternalW(a->left, n + 1);
        cout << setw(n * 5) << a->key << "(" << a->weight << ")" << endl;
        showInternalW(a->right, n + 1);
    }
}

