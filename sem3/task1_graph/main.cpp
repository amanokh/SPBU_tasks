#include <bits/stdc++.h>
#include <graphics.h>
#include "graph.h"
using namespace std;
#define PI 3.1415

void drawEdges(int n){
    for (int i = 1; i < n + 1; ++i) {
        setcolor(WHITE);
        int x = 400 + 300 * cos(PI * 2 * i / n);
        int y = 400 + 300 * sin(PI * 2 * i / n);
        ellipse(x, y, 0, 360, 20, 20);
        char a[10];
        char w[10];
        outtextxy(x - 5, y - 5, a);
        setcolor(3);
        outtextxy(x + 25, y - 5, w);
    }
}
void drawArrow(int b, int n, int *p){
    setcolor(3);
    while (p[b]!=-1){
        int xa = 400 + 280 * cos(PI * 2 * p[b] / n);
        int ya = 400 + 280 * sin(PI * 2 * p[b] / n);
        int xb = 400 + 280 * cos(PI * 2 * b / n);
        int yb = 400 + 280 * sin(PI * 2 * b / n);
        line(xa,ya,xb,yb);
        int xarr = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) -
                              0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int yarr = yb - 20 * (0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                              0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int xarr1 = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                               0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int yarr1 = yb - 20 * (-0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                               0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        line(xb,yb,xarr,yarr);
        line(xb,yb,xarr1,yarr1);
        b=p[b];
    }
}
void drawArrowAll(int n, int *p){
    setcolor(WHITE);
    for (int i = 1; i < n + 1; ++i) {
        int b = i;
        while (p[b] != -1) {
            int xa = 400 + 280 * cos(PI * 2 * p[b] / n);
            int ya = 400 + 280 * sin(PI * 2 * p[b] / n);
            int xb = 400 + 280 * cos(PI * 2 * b / n);
            int yb = 400 + 280 * sin(PI * 2 * b / n);
            line(xa, ya, xb, yb);
            int xarr = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) -
                                  0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
            int yarr = yb - 20 * (0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                                  0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
            int xarr1 = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                                   0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
            int yarr1 = yb - 20 * (-0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                                   0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
            line(xb, yb, xarr, yarr);
            line(xb, yb, xarr1, yarr1);
            b = p[b];
        }
    }
}
void drawArrows(int m, int n, pair<int,int> *edges){
    setcolor(GREEN);
    for (int i = 0; i < m; ++i) {
        int a = edges[i].first;
        int b = edges[i].second;
        int xa = 400 + 280 * cos(PI * 2 * a / n);
        int ya = 400 + 280 * sin(PI * 2 * a / n);
        int xb = 400 + 280 * cos(PI * 2 * b / n);
        int yb = 400 + 280 * sin(PI * 2 * b / n);
        line(xa, ya, xb, yb);
        int xarr = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) -
                              0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int yarr = yb - 20 * (0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                              0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int xarr1 = xb - 20 * (0.966 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                               0.258 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        int yarr1 = yb - 20 * (-0.258 * (xb - xa) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
                               0.966 * ((yb - ya) / sqrt(pow(yb - ya, 2) + pow(xb - xa, 2))));
        line(xb, yb, xarr, yarr);
        line(xb, yb, xarr1, yarr1);
    }
}

void dijkstra(int* matrix, int start, int end, int n){
    int d[n];
    int v[n];
    for (int i = 0; i < n; ++i) {
        d[n] = 1000000;
        v[n] = 0;
    }

    v[start] = 1;
    int curr = start;
    while (!v[end]){
        int temp[n];
        for (int i = 0; i < n; ++i) temp[i] = matrix[curr * n + i];
    }

}

int main(int argc, char **argv) {
    freopen("task1.txt", "r", stdin);

    int n, start;
    cin >> n >> start;
    int *matrix = new int[n*n]();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            matrix[i*n+j] = c;
        }
    }
    cout << "matrix initialized" << endl;

    Graph graph = Graph(matrix, n);

    cout << "graph initialized" << endl;


    int gd = CUSTOM;
    int gm = CUSTOM_MODE(800,800);
    initgraph(&gd, &gm, "");
    graph.show();
    readkey();

    clearviewport();
    graph.dijkstra(start - 1);
    readkey();


}

