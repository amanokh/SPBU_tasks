#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {

    Tree tree{};

    srand(time(0));
    int count = 8;         //количество вершин
    int a = rand();
    for (int i = 0; i < count; ++i) {
        tree.push(a++ * 31 % 50);
    }

    int c, x;
    cout << "App builds a tree with 8 roots in interval from 0 to 49" << endl;
    cout << "---------" << endl;
    cout << "Controls:" << endl;
    cout << "1 - show tree" << endl;
    cout << "2 - show tree + weights" << endl;
    cout << "3 - add root" << endl;
    cout << "4 - remove root" << endl;
    cout << "5 - ind.task - show roots with only one child and weight!=0" << endl;
    cout << ">>";
    cin >> c;
    while (c != 0) {
        switch (c) {
            case 1:
                tree.show();
                break;
            case 2:
                tree.showW();
                break;
            case 3:
                cout << "Enter root to add>>";
                cin >> x;
                tree.push(x);
                break;
            case 4:
                cout << "Enter root to remove>>";
                cin >> x;
                tree.pop(x);
                break;
            case 5:
                tree.printInd();
                break;
        }
        cout << ">>";
        cin >> c;
    }
    tree.show();
}
