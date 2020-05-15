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
    Tree() {}

    void push(int x) {
        pushInternal(&head, x, 0);
    }

    void pop(int x) {
        popInternal(head, x);
    }

    void print() {
        printInternal(head);
    }

    int getMax() {
        return max(head)->key;
    }

    void show() {
        showInternal(head, 0);
    }

    void showW() {
        showInternalW(head, 0);
    }

    void printInd() {
        printInternalInd(head);
        cout << endl;
    }

private:
    link *max(link *a) {
        if (a->right) return max(a->right);
        else return a;
    }

    link *min(link *a) {
        if (a->left) return min(a->left);
        else return a;
    }

    void pushInternal(link **a, int x, int level) {
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

    link *popInternal(link *a, int x) {
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

    void printInternal(link *a) {
        if (a) {
            cout << a->key << " ";
            printInternal(a->left);

            printInternal(a->right);
        }
    }

    void printInternalInd(link *a) {
        if (a) {
            printInternalInd(a->left);
            int l = a->left ? 1 : 0;
            int r = a->right ? 1 : 0;

            if (a->weight && (l + r) == 1) cout << a->key << "(" << a->weight << ") ";
            printInternalInd(a->right);
        }
    }

    void showInternal(link *a, int n) {
        if (a) {
            showInternal(a->left, n + 1);
            cout << setw(n * 3) << a->key << endl;
            showInternal(a->right, n + 1);
        }
    }

    void showInternalW(link *a, int n) {
        if (a) {
            showInternalW(a->left, n + 1);
            cout << setw(n * 5) << a->key << "(" << a->weight << ")" << endl;
            showInternalW(a->right, n + 1);
        }
    }
};
