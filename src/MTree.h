#ifndef TP_3_ALGORITMOS_MTREE_H
#define TP_3_ALGORITMOS_MTREE_H
#include <iostream>
#include <vector>
#include <string>
#include "MTree.h"
#include <queue>
#include "MTreeNode.h"

using namespace std;
int const N = 8;
#define IN  9000

class MTree{
public:
    MTreeNode* root;
    int adjMatrix[N][N]{};
    vector<string> nameIndexes{};  // acá se almacena los nombres correspondientes a cada indice
    // de las filas de la matriz de adjacencia Ej: Madrid-->0

    MTree(MTreeNode* root, int adjMatrix[N][N], vector<string> nameIndexes);
    MTree();

    void newMTree(MTreeNode* root,int adjMatrix[N][N], vector<string> nameIndexes);
    void generateTree(int cityIndex,MTreeNode* city);
    void generateNewNode(int cityIndex, MTreeNode* city,int newNodeIndex);
    bool contains(vector<int> A,int value);
    void print();
    vector<vector<int>> getHamiltonians();
    void printHamiltonians(vector<vector<int>> hamiltonians);
    void sortHamiltonians(vector<vector<int>>& caminos, int inicio, int fin);
    int partition(vector<vector<int>>& caminos, int inicio, int fin);
    vector<vector<MTreeNode*>> levelOrder(MTreeNode* root);
};


#endif //TP_3_ALGORITMOS_MTREE_H
