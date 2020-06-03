#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "queue.h"

using namespace std;

double fRand() {
    double f = (double) rand() / RAND_MAX;
    return f;
}

int main() {
    List list{};
    srand(time(0));

    int k,m;                        // ограничения на Т1, Т2
    int requests = 1000;            // количество заявок

    cout << "Enter T1, T2: ";
    cin >> k >> m;

    int T1 = fRand() * k;
    int T2;

    int currTime = 0;               // текущее время

    int countFinished = 0;          // количество вышедших заявок
    int maxDelay = -1;              // максимальное время ожидания
    int works = 0;                  // количество обработанных заявок в ОА
    unsigned long pendingTime = 0;  // общее время ожидания ОА
    unsigned long workTime = 0;     // общее время ожидания перед ОА
    unsigned long delayTime = T1;   //общее время ожидания Т1

    link *maxID = nullptr;          //заявка с макс. временем ожидания

    int id = 0;
    int empty = 1;                  // пустой ли список


    while (countFinished < requests) {
        //Генерируем Т2, если очередь не пуста
        if (empty && list.count() > 0) {
            T2 = fRand() * m;
            pendingTime += T2;
            empty = 0;
        }

        //Генерируем заявку, ставим в очередь
        while (T1 == 0) {
            list.push(currTime, id);
            id++;

            T1 = fRand() * k;
            delayTime += T1;
        }

        //Обрабатываем заявки в ОА -> перемещаем отработанные в конец очереди -> снова генеириуем Т2
        while (T2 == 0) {
            //ищем ячейку с макс. ожиданием
            if (currTime - list.head->enterTime > maxDelay) {
                maxID = list.head;
                maxDelay = currTime - list.head->enterTime;
            }

            //обновляем счетчики
            works++;
            workTime += currTime - list.head->enterTime;

            //проверяем, отработала ли заявка 4 раза
            if (list.head->count < 3) list.work(currTime);
            else {
                countFinished++;
                if (currTime - list.head->enterTime > maxDelay) {
                    maxID = list.head;
                    maxDelay = currTime - list.head->enterTime;
                }
                list.pop();
                if (countFinished % 100 == 0) {
                    cout << "*****" << countFinished << "*****" << endl;
                    cout << "Entered requests (total): " << id << endl;
                    cout << "Request ID with max delay: " << maxID->id << endl;
                    cout << "Queue || length: " << list.count() << ", max time in queue: " << maxDelay << ", average: "
                         << workTime / works << endl;
                }
            }

            if (list.count() == 0) {
                T2 = -1;
                empty = 1;
            } else {
                T2 = fRand() * m;
                pendingTime += T2;
            }
        }

        //тикаем время
        currTime++;
        if (id < requests) T1--;
        if (!empty) T2--;
    }

    cout << "************" << endl << "Average time T1: " << delayTime / id << endl;
    cout << "Time     || building: " << currTime << ", idle: " << currTime - pendingTime << endl;
    cout << "Requests || in: " << id << ", out: " << countFinished << ", total handled: " << works << endl;
}


