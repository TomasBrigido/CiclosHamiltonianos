#include "MTreeNode.h"

MTreeNode::MTreeNode(string name,int index) {
    this->name = name;
    this->index = index;         // por defecto se asume que el nuevo nodo tiene el índice de la raiz
    ancestors.push_back(-1); // se asigna -1 por defecto para que se  no produzca una excepción en generateTree()
}