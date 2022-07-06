#ifndef TP_3_ALGORITMOS_MTREENODE_H
#define TP_3_ALGORITMOS_MTREENODE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class MTreeNode{

public:

    MTreeNode(string name,int index);

    string name;
    int index; // índice que corresponde al nombre de la ciudad, Ej: Madrid->0
    vector<int> ancestors;
    vector<MTreeNode*> offspring;
    //vector<int> costs; // aca se almacenan los costos de viajar a cada hijo del nodo
};

#endif //TP_3_ALGORITMOS_MTREENODE_H
