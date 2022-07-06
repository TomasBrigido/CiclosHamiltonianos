#ifndef TP_3_ALGORITMOS_HAMILTOLECT_H
#define TP_3_ALGORITMOS_HAMILTOLECT_H
#include <bits/stdc++.h>
using namespace std;
#define IN  0
#define V 8

class hamiltoLect {
private:
    bool hasCycle;
    vector<int> pathR;
    vector<vector<int>> vectorOfVectors;

public:
    int graph1[V][V] = { {IN,IN,210,IN,300,IN,350,320},
                         {IN,IN,350,IN,150,IN,280,250},
                         {210,350,IN,100,IN,120,IN,IN},
                         {IN,IN,100,IN,200,60,IN,IN},
                         {300,150,IN,200,IN,120,IN,240},
                         {IN,IN,120,60,120,IN,60,80},
                         {350,280,IN,IN,IN,60,IN,60},
                         {320,250,IN,IN,240,80,60,IN},};
    hamiltoLect();
    bool isSafe(int,int[][V],vector<int>,int);
    void FindHamCycle(int[][V],int,vector<int>,bool[],int);
    void hamCycle(int[][V], int);
    vector<vector<int>> getVectorOfVectors();
    void QuickSort(vector<vector<int>>&, int, int);
    int particion(vector<vector<int>>& caminos,int inicio, int fin);
};


#endif
