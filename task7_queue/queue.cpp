//
// Created by amano on 31.05.2020.
//
#include <iostream>
#include "queue.h"

using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
}

void List::push(int enterTime, int id) {
    link *temp = new link;
    temp->next = nullptr;
    temp->enterTime = enterTime;
    temp->count = 0;
    temp->id = id;

    if (head != nullptr) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    } else {
        temp->prev = nullptr;
        head = tail = temp;
    }
}

void List::work(int enterTime) {
    tail->next = head;
    head = head->next;
    tail = tail->next;
    tail->next = nullptr;
    tail->count++;
    tail->enterTime = enterTime;
}

void List::pop() {
    head->count++;
    if (head->next)
        head = head->next;
    else {
        head = nullptr;
        tail = nullptr;
    }
}

int List::count() {
    int count = 1;
    if (!head)
        return 0;
    link *temp = head;
    while (temp != tail && temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

