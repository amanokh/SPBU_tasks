//
// Created by amano on 08.06.2020.
//

#ifndef TASK7_QUEUE_H
#define TASK7_QUEUE_H
struct task {
    int iters;
    double enterTime;
    int id;
    task *next, *prev;
};

class Queue {
private:
    task *head, *tail;
public:
    Queue();

    void push(double enterTime, int id, int iters);
    void pop();
    task* getHead();
    int count();
};
#endif //TASK7_QUEUE_H
