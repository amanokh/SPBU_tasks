#include <iostream>
#include "polynom.h"
using namespace std;

int main() {
    std::list<int> a = {0};
    std::list<int> b = {4,0,0,2};


    Polynom p1 = {0};
    Polynom p2 = {0};
    Polynom p3 = {};
    Polynom p4 = {4,2};
    Polynom p5 = {8,-3};
    Polynom p6 = {-12, 2};

    (p4 - p5).print();
    cout<<(p4 - p1).size();
}
