#ifndef TASK8_POLYNOM_H
#define TASK8_POLYNOM_H


#include <list>
#include <vector>

class Polynom {

private:
    std::vector<int> degrees;
    int n;
public:
    Polynom(int order, int n);

    Polynom(std::vector<int> &deg);

    Polynom(std::initializer_list<int> list);

    Polynom(const std::vector<int> &a);

    int size() const;

    void print();

    ~Polynom();

    friend Polynom operator+(const Polynom &a, const Polynom &b);

    friend Polynom operator*(const Polynom &a, const Polynom &b);

    friend Polynom operator-(const Polynom &a, const Polynom &b);
};



#endif //TASK8_POLYNOM_H
