#include <iostream>
#include <time.h>
#include "queue.h"

using namespace std;

double fRand() {
    double f = (double) rand() / RAND_MAX;
    return f;
}

int main() {
    Queue queue{};
    srand(time(0));

    int k, m;                        // ограничения на Т1, Т2
    int tasks = 1000;                // количество заявок

    int maxDelayID, maxDelayIters;   //хранение заявки с макс. ожиданием
    double maxDelay = 0.;

    double globalTime = 0.;         //общее время "системы"
    double workingTimeOA = 0.;      //общее время ОА в состоянии обработки
    double lastEnterTime = 0.;      //время прихода последней заявки

    int enteredTasks = 0;           //кол-во пришедших заявок в "систему"
    int finishedTasks = 0;          //кол-во вышедших заявок из "системы"
    int handledTasksOA = 0;         //общее кол-во обработанных в ОА заявок

    double totalT1 = 0.;            //общее время задержки между приходами заявок
    double T1, T2;

    //принимаем данные на ввод
    cout << "Enter T1, T2: ";
    cin >> k >> m;

    //генерируем первую заявку
    T1 = fRand() * k;
    lastEnterTime += T1;
    queue.push(lastEnterTime, enteredTasks + 1, 1);
    enteredTasks++;
    totalT1 += T1;

    bool isRepeat;     //булеан - возвращать заявку обратно в очередь или нет
    while (finishedTasks < tasks) {
        //получаем данные обрабатываемой заявки
        task *currentTask = queue.getHead();
        double cTaskTime = currentTask->enterTime;
        int cTaskIters = currentTask->iters;
        int cTaskID = currentTask->id;

        isRepeat = false;

        //обрабатываем заявку
        if (cTaskTime <= globalTime) {
            T2 = fRand() * m;
            globalTime += T2;
            workingTimeOA += T2;
            handledTasksOA++;

            //определяем заявку с макс.ожиданием своей обработки
            if (globalTime - cTaskTime > maxDelay) {
                maxDelay = globalTime - cTaskTime;
                maxDelayID = cTaskID;
                maxDelayIters = cTaskIters;
            }

            //возвращаем в очередь, если обработана менее 4 раз
            if (cTaskIters < 4) isRepeat = true;
            else {
                finishedTasks++;
                if (finishedTasks % 100 == 0) {
                    cout << "***** " << finishedTasks << " completed *****" << endl;
                    cout << "Entered requests (total): " << enteredTasks << endl;
                    cout << "Queue || length: " << queue.count() - 1 << ", average delay: "
                         << workingTimeOA / finishedTasks << ", max: " << maxDelay << " (ID=" << maxDelayID << ", iter="
                         << maxDelayIters << ")" << endl << endl;
                }
            }

            queue.pop();

        } else {
            globalTime = cTaskTime; //продвигаем общее время на момент входа очередной заявки в ОА
        }

        //генерируем новые заявки, пришедшие за время обработки другой в ОА
        while (lastEnterTime <= globalTime && enteredTasks < tasks) {
            T1 = fRand() * k;
            lastEnterTime += T1;
            queue.push(lastEnterTime, enteredTasks + 1, 1);
            enteredTasks++;
            totalT1 += T1;
        }

        //возвращаем окончившую обработку заявку, если требуется
        if (isRepeat) queue.push(globalTime, cTaskID, cTaskIters + 1);
    }

    cout << "************" << endl << "Average time T1: " << totalT1 / tasks << endl;
    cout << "Time total: " << globalTime << endl << endl;
    cout << "OA time  || working: " << workingTimeOA << ", idle: "
         << globalTime - workingTimeOA << endl;
    cout << "Requests || in: " << enteredTasks << ", out: " << finishedTasks << ", total handled (in OA): " << handledTasksOA
         << endl;

}


