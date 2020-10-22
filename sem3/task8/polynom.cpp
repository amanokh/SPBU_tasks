#include "polynom.h"
#include <iostream>


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

    for (auto f1 = a.degrees.begin(); f1 != a.degrees.end(); ++f1) {
        for (auto f2 = b.degrees.begin(); f2 != b.degrees.end(); ++f2) {
            tmp[f1 - a.degrees.begin() + f2 - b.degrees.begin()] += *f1 * *f2;
        }
    }
    return Polynom(tmp);
}

Polynom operator*(int a, const Polynom &b) {
    std::vector<int> tmp;

    for (int degree : b.degrees) {
        tmp.push_back(a * degree);
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

void Polynom::printCanonic() {
    bool isFirst = true;

    for (int i = degrees.size() - 1; i >= 0; i--) {
        std::string sgn = (degrees[i] > 0 && !isFirst) ? "+ " : "";
        if (degrees[i]) {
            if (i == 0) std::cout << sgn << degrees[i];
            else if (i == 1) std::cout << " " << sgn << degrees[i] << "x";
            else std::cout << " " << sgn << degrees[i] << "x^" << i;
            isFirst = false;
        }
    }
    std::cout << std::endl;
}

Polynom::Polynom(std::vector<int> &list) {
    while (!list.empty() && list.back() == 0) list.resize(list.size() - 1);
    n = list.size();

    std::swap(list, degrees);
}

Polynom::Polynom(std::initializer_list<int> list) {
    // delete all zero coeffs in master degrees

    auto last_pos = list.end();
    while (last_pos != list.begin() && *(last_pos - 1) == 0) last_pos--;

    if (last_pos != list.begin()) {
        degrees.insert(degrees.end(), list.begin(), last_pos);
        n = last_pos - list.begin();
    } else n = 0;
}

Polynom::Polynom() {

}

bool operator==(const Polynom &a, const Polynom &b) {
    bool isEqual = true;
    if (a.size() == b.size()){
        int i = 0;
        while (i < a.size() and a.degrees[i] == b.degrees[i]) ++i;
        if (i != a.size()) isEqual = false;
    } else {
        isEqual = false;
    }
    return isEqual;
}

