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

    explicit Polynom(std::vector<int> &deg);

    Polynom(std::initializer_list<int> list);

    Polynom(const std::vector<int> &a);

    [[nodiscard]] int size() const;

    void print();

    void printCanonic();

    ~Polynom();

    friend Polynom operator+(const Polynom &a, const Polynom &b);

    friend Polynom operator*(const Polynom &a, const Polynom &b);

    friend Polynom operator-(const Polynom &a, const Polynom &b);

    friend bool operator==(const Polynom &a, const Polynom &b);

    friend Polynom operator*(int a, const Polynom &b);

    Polynom();
};



#endif //TASK8_POLYNOM_H
