#include "graph.h"
#include <graphics.h>
#include <math.h>

#define PI 3.1415

clCircle::clCircle(int a, int n) {
    num = a;
    x = 400 + 300 * cos(2 * PI * a / n);
    y = 400 + 300 * sin(2 * PI * a / n);
}

void clCircle::show() {
    ellipse(x, y, 0, 360, r, r);
    char s[10];
    itoa(num + 1, s, 10);
    outtextxy(x - 5, y - 5, s);

    char dist[10];
    itoa(d, dist, 10);
    outtextxy(x + 20, y - 20, dist);
}

int clCircle::getDistance() {return d;}

int clCircle::isVisited() {return v;}

void clCircle::setDistance(int dist) {d = dist;}

void clCircle::setVisited() {v = 1;}

clLine::clLine(int start, int end, int w, int n) {
    a = start;
    b = end;
    weight = w;
    x1 = 400 + 280 * (cos(2 * PI * a / n));
    y1 = 400 + 280 * (sin(2 * PI * a / n));
    x2 = 400 + 280 * (cos(2 * PI * b / n));
    y2 = 400 + 280 * (sin(2 * PI * b / n));
}

void clLine::show() {
    line(x1, y1, x2, y2);
    int x1rr = x2 - 20 * (0.966 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) -
                          0.258 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int y1rr = y2 - 20 * (0.258 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                          0.966 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int x1rr1 = x2 - 20 * (0.966 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                           0.258 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int y1rr1 = y2 - 20 * (-0.258 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                           0.966 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    line(x2, y2, x1rr, y1rr);
    line(x2, y2, x1rr1, y1rr1);

    char s[10];
    itoa(weight, s, 10);
    outtextxy((x2 + x1) / 2 - 20, (y2 + y1) / 2 - 20, s);
}

int clLine::getStart() {return a;}

int clLine::getEnd() {return b;}

int clLine::getWeight() {return weight;}

Graph::Graph(int *matrix, int n) {
    int roots_all[n];
    lines = new clLine *[n * n]();
    roots = new clCircle *[n]();
    for (int i = 0; i < n; ++i) roots_all[i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i * n + j]) {
                lines[numLines] = new clLine(i, j, matrix[i * n + j], n);
                roots_all[i] = 1;
                roots_all[j] = 1;
                numLines++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (roots_all[i]) {
            roots[numRoots] = new clCircle(i, n);
            numRoots++;
        }
    }
}

void Graph::show() {
    for (int i = 0; i < numRoots; ++i) roots[i]->show();
    for (int i = 0; i < numLines; ++i) lines[i]->show();
}

void Graph::dijkstra(int start) {
    int m = numLines;
    int n = numRoots;
    clLine* p[n];
    std::vector<clLine*> road;

    for (int i = 0; i < n; ++i) p[i] = nullptr;
    roots[start]->setDistance(0);

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            int a = lines[i]->getStart(), b = lines[i]->getEnd();
            int w = lines[i]->getWeight();
            if (a == start && !roots[b]->isVisited() && roots[start]->getDistance() + w < roots[b]->getDistance()) {
                roots[b]->setDistance(roots[start]->getDistance() + w);
                p[b] = lines[i];
            }
        }
        roots[start]->setVisited();

        int minD = 100000000;
        for (int v = 0; v < n; ++v) {
            if (roots[v]->getDistance() < minD && !roots[v]->isVisited()) {
                minD = roots[v]->getDistance();
                start = v;
            }
        }
    }
    for (int i = 0; i < numRoots; ++i) roots[i]->show();
    setcolor(GREEN);
    for (int i = 0; i < n; ++i) {
        if (p[i]) p[i]->show();
    }
}

void clDraw::show() {}
