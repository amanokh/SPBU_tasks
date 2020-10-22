#include <iostream>
#include "polynom.h"

using namespace std;

Polynom **createList(int order, int q) {
    auto polynomList = (Polynom **) malloc(q * sizeof(Polynom **));
    auto *p0 = new Polynom;
    auto *p1 = new Polynom;
    *p0 = {1};
    *p1 = {0, order};

    polynomList[0] = p0;

    if (q >= 1) {
        polynomList[1] = p1;

        for (int i = 2; i <= q; ++i) {
            Polynom multiply = {0, 2};

            auto *tmp = new Polynom;
            *tmp = (multiply * *polynomList[i - 1]) - *polynomList[i - 2];
            polynomList[i] = tmp;
        }
    }
    return polynomList;
}

int main() {
    std::list<int> a = {0};
    std::list<int> b = {4, 0, 0, 2};


    Polynom **polynomList = createList(1, 10);
    for (int i = 0; i <= 10; ++i) {
        cout << i << ": ";
        polynomList[i]->printCanonic();
    }
}
