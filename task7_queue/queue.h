//
// Created by amano on 31.05.2020.
//

#ifndef TASK7_QUEUE_H
#define TASK7_QUEUE_H
struct link {
    int count;
    int enterTime;
    int id;
    link *next, *prev;
};

class List {
public:
    link *head, *tail;
    List();

    void push(int, int);
    void work(int);
    void pop();
    int count();
};

#endif //TASK7_QUEUE_H
