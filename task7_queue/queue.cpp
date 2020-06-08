//
// Created by amano on 08.06.2020.
//
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

void Queue::push(double enterTime, int id, int iters) {
    task *temp = new task;
    temp->next = tail;
    temp->prev = nullptr;
    temp->enterTime = enterTime;
    temp->iters = iters;
    temp->id = id;

    if (!head) {
        head = temp;
        tail = temp;
    } else {
        tail->prev = temp;
        tail = temp;
    }
}

void Queue::pop() {
    if (head->prev){
        task *temp = head;
        head = head->prev;
        head->next = nullptr;
        delete(temp);
    } else {
        delete(head);
        head = nullptr;
        tail = nullptr;
    }
}

int Queue::count() {
    int count = 0;
    task *temp = head;

    while (temp) {
        temp = temp->prev;
        count++;
    }
    return count;
}

task *Queue::getHead() {
    return head;
}

