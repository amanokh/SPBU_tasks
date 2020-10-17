#include "polynom.h"
#include <iostream>

Polynom::Polynom(int order, int n) {
    if (n == 0) {
        degrees.emplace_back(1);
    } else if (n == 1) {
        degrees.emplace_back(1);
        degrees.emplace_back(order);
    } else {
        int deg_1[n + 1];
        int deg_2[n + 1];
        deg_1[0] = 1;
        deg_2[1] = order;

        for (int i = 2; i <= n; ++i) {
        }
    }
}

Polynom::~Polynom() {

}

Polynom operator+(const Polynom &a, const Polynom &b) {
    std::vector<int> tmp;

    auto f1 = a.degrees.begin();
    auto f2 = b.degrees.begin();

    for (; (f1 != a.degrees.end()) && (f2 != b.degrees.end()); ++f1, ++f2) {
        tmp.emplace_back(*f1 + *f2);
    }
    while (f1 != a.degrees.end()) {
        tmp.emplace_back(*f1);
        f1++;
    }
    while (f2 != b.degrees.end()) {
        tmp.emplace_back(*f2);
        f2++;
    }

    return Polynom(tmp);
}

Polynom operator*(const Polynom &a, const Polynom &b) {
    std::vector<int> tmp;
    tmp.resize(a.size() + b.size());

    for (auto f1 = a.degrees.begin(); f1 != a.degrees.end(); ++f1){
        for (auto f2 = b.degrees.begin(); f2 != b.degrees.end(); ++f2){
            tmp[f1 - a.degrees.begin() + f2 - b.degrees.begin()] += *f1 * *f2;
        }
    }
    return Polynom(tmp);
}

Polynom operator-(const Polynom &a, const Polynom &b) {
    Polynom minus = {-1};
    return Polynom(a + minus * b);
}

int Polynom::size() const {
    return n;
}


void Polynom::print() {
    for (auto &i : degrees) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

Polynom::Polynom(std::vector<int> &list) {
    while (!list.empty() && list.back() == 0) list.resize(list.size() - 1);

    std::swap(list, degrees);
    n = list.size();
}

Polynom::Polynom(std::initializer_list<int> list) {
    // delete all zero coeffs in master degrees
    auto last_pos = list.end();
    while (last_pos != list.begin() && *(last_pos - 1) == 0) last_pos--;

    if (last_pos != list.begin()){
        degrees.insert(degrees.end(), list.begin(), last_pos);
        n = last_pos - list.begin();
    } else n = 0;
}

