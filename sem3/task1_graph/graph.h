#ifndef TASK1_GRAPH_GRAPH_H
#define TASK1_GRAPH_GRAPH_H

#include <bits/stdc++.h>
#include <graphics.h>

class clDraw{
public:
    virtual void show();
};

class clLine: public clDraw{
private:
    int a, b, weight;
    int x1, y1, x2, y2;
public:
    clLine(int start, int end, int w, int n);
    void show() override;
    int getStart();
    int getEnd();
    int getWeight();
};

class clCircle: public clDraw{
private:
    int num, d = 100000000;
    int x, y, r = 20;
    int v = 0;
public:
    clCircle(int a, int n);
    void show() override;
    int isVisited();
    int getDistance();
    void setDistance(int dist);
    void setVisited();
};

class Graph: public clDraw{
private:
    clLine** lines;
    clCircle** roots;
    int numLines = 0, numRoots = 0;
public:
    Graph(int* matrix, int n);
    void show() override;
    void dijkstra(int start);
};


#endif //TASK1_GRAPH_GRAPH_H
