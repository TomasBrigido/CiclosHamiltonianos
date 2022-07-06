#ifndef TP_3_ALGORITMOS_LAUNCHER_H
#define TP_3_ALGORITMOS_LAUNCHER_H
#include <string>
#include <iostream>
#include "hamiltoLect.h"
#include "MTree.h"
#include "MTreeNode.h"

using namespace std;

class Launcher {
private:
    int grapheno[8][8] = { {IN,IN,210,IN,300,IN,350,320},
                         {IN,IN,350,IN,150,IN,280,250},
                         {210,350,IN,100,IN,120,IN,IN},
                         {IN,IN,100,IN,200,60,IN,IN},
                         {300,150,IN,200,IN,120,IN,240},
                         {IN,IN,120,60,120,IN,60,80},
                         {350,280,IN,IN,IN,60,IN,60},
                         {320,250,IN,IN,240,80,60,IN},};
    hamiltoLect vectorH;
    vector<string> nameIndexes{ "MA","RO", "PA", "AM","ZU","BE","VA","VI"};
    MTree* test = new MTree();

public:
    Launcher();
    void interactiveMenu();
    void orderedVectorQS(bool complete);
    void orderedTreeQS(bool complete);
    void printTreeComplete(bool order);
    void selectorCiry(string);
    void convertLower(string&);
    void convertHigh(string&);
    void printComands();
    void exitLauncher();
    void printOrderQS(bool,vector<vector<int>>);
    string getName(int);
};
#endif //TP_3_ALGORITMOS_LAUNCHER_H
