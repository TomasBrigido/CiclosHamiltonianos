#include "MTree.h"

MTree::MTree(MTreeNode* root, int adjMatrix[N][N], vector<string> nameIndexes) {
    newMTree(root,adjMatrix,nameIndexes);
}

MTree::MTree() {
    root = nullptr;
}

void MTree::newMTree(MTreeNode *root, int adjMatrix[N][N], vector<string> nameIndexes){

    this->root = root;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { this->adjMatrix[i][j] = adjMatrix[i][j];  }
    }
    for (int i = 0; i < N; i++) {  this->nameIndexes.push_back(nameIndexes[i]);  }
}

void MTree::generateTree(int cityIndex, MTreeNode* city) {
    if (city->ancestors.size() == N) {     // cuando se llega al ultimo nivel, se chequea si se puede
        // volver al origen ( es decir si es un Hamiltoniano)
            if (adjMatrix[cityIndex][root->index] != IN) {
                generateNewNode(cityIndex, city, root->index);
            }
        return;
    }

    else {
        for (int j = 0; j < N; j++) {
            if (adjMatrix[cityIndex][j] != IN && contains(city->ancestors, j) == false) {

                generateNewNode(cityIndex, city,j);
            }
        }
        for (int i = 0; i < city->offspring.size(); i++) {

            MTreeNode* aux = city->offspring[i];
            generateTree(aux->index, aux);
        }
    }
}


bool MTree::contains(vector<int> A,int value) {

    bool hasValue=false;

    for (int i = 0; i < A.size(); i++) {

        if (A[i] == value) {
            hasValue = true;
            break;
        }
    }
    return hasValue;
}

void MTree::generateNewNode(int cityIndex, MTreeNode* city,int newNodeIndex) {
    MTreeNode* newNode = new MTreeNode(nameIndexes[newNodeIndex],newNodeIndex);
    newNode->index = newNodeIndex;

    // copiar todos los ancestros de la ciudad actual en el hijo
    for (int x = 0; x < city->ancestors.size(); x++) {

        if (city->ancestors[x] != -1) {
            newNode->ancestors.push_back(city->ancestors[x]);
        }
    }
    // se agrega a los ancestros del nuevo nodo el índice de la ciudad actual
    newNode->ancestors.push_back(cityIndex);
    city->offspring.push_back(newNode);
}

void MTree::print() {
    vector<vector<MTreeNode*> > ans = levelOrder(root);
    for (auto v : ans) {
        for (MTreeNode* x : v) {
            cout << x->name << "  ";
        }
        cout << endl;
    }
}

// se recorre el arbol en amplitud
vector<vector<MTreeNode*>> MTree:: levelOrder(MTreeNode* root){

    vector<vector<MTreeNode*> > ans;
    if (!root)
        cout << "El arbol no posee nodos...";
    // Crear una cola principal
    queue<MTreeNode*> main_queue;

    // Pushear la raiz en la cola principal
    main_queue.push(root);

    //Crear un vector temporal para almacenar todos los nodos
    vector<MTreeNode*> temp;

    //Correr el while hasta que la cola principal este vacia
    while (!main_queue.empty()) {

        //Obtener el primer elemento de la cola
        int n = main_queue.size();

        //Iterar a lo largo del nivel actual
        for (int i = 0; i < n; i++) {
            MTreeNode* cur = main_queue.front();
            main_queue.pop();
            temp.push_back(cur);
            for (auto u : cur->offspring) {
                main_queue.push(u);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}


vector<vector<int>> MTree::getHamiltonians() {

    vector<vector<int>> hamiltonians;

    // se obtienen los nodos del ultimo nivel(N) del árbol
    vector<MTreeNode*> lastLevel = levelOrder(root)[N];//Obtengo solo la ultima linea del vector de vectores

    for (int i = 0; i < lastLevel.size(); i++) {

        int totalCost = 0;
        vector<int> auxVector;

        // se agrega el indice de los ancestros del nodo a auxVector
        for (int k = 0; k < lastLevel[i]->ancestors.size(); k++) {

            if (lastLevel[i]->ancestors[k] == -1) { continue; }

            auxVector.push_back(lastLevel[i]->ancestors[k]);//agrego los indices de los ancestros
        }

        // se calcula el costo total del recorrido a lo largo de todos los ancestros del nodo
        for (int j = 0; j < lastLevel[i]->ancestors.size() - 2; j++) {

            totalCost += adjMatrix[auxVector[j]][auxVector[j + 1]];//acumulo el costo del recorrido
        }

        // se agrega el indice del nodo del comienzo del recorrido y el costo de ir a este nodo de inicio
        auxVector.push_back(lastLevel[i]->index);
        totalCost += adjMatrix[auxVector[auxVector.size() - 2]][auxVector[auxVector.size()-1]];

        // se agrega el hamiltoniano con su costo a hamiltonians
        auxVector.push_back(totalCost);
        hamiltonians.push_back(auxVector);
    }
    return hamiltonians;
}

void MTree::printHamiltonians(vector<vector<int>> hamiltonians) {

    int totalAmount = 0;

    for (int i = 0; i < hamiltonians.size(); i++) {

        for (int j = 0; j < N + 2; j++) {

            if (hamiltonians[i][j] >= 0 && hamiltonians[i][j] <= N - 1) {

                cout << nameIndexes[hamiltonians[i][j]] <<" ,";
            }
            else {
                cout << "Costo total: " << hamiltonians[i][j];
            }
        }
        cout << endl;
        totalAmount++;
    }
    cout << "TOTAL HAMILTONIANOS: " << totalAmount << endl;
}


int MTree::partition(vector<vector<int>>& paths, int start, int end) {
    int pivot = paths[start][9];
    int i = start + 1;
    for (int j = i; j <= end; j++) {
        if (paths[j][9] < pivot) {
            swap(paths[i], paths[j]);
            i++;
        }
    }
    swap(paths[start], paths[i - 1]);
    return i - 1;
}

void MTree::sortHamiltonians(vector<vector<int>>& caminos, int start, int end) {
    if (start < end) {
        int pivot = partition(caminos, start, end);
        sortHamiltonians(caminos, start, pivot - 1);
        sortHamiltonians(caminos, pivot + 1, end);
    }
}