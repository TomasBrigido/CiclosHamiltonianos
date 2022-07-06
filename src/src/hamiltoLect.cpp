#include "hamiltoLect.h"
hamiltoLect::hamiltoLect() {
    hamCycle(graph1, 8); //creacion de todos los posibles hamiltoneanos, en vector de vectores
}

bool hamiltoLect::isSafe(int v, int graph[][8], vector<int> path, int pos){
    // If the vertex is adjacent to the vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // If the vertex has already been included in the path
    for (int i = 0; i < pos; i++){
        if (path[i] == v) {
            return false;
        }
    }
    // Both the above conditions are not true, return true
    return true;
}

void hamiltoLect::FindHamCycle(int graph[][8], int pos, vector<int> path, bool visited[], int N){
    int costCounter = 0; //Contador del costo de los caminos
    int almacenando = 0;
    // If all vertices are included in Hamiltonian Cycle
    if (pos == N) {

        // If there is an edge from the last vertex to the source vertex
        if (graph[path[path.size() - 1]][path[0]] != 0) {

            // Include source vertex into the path and print the path
            path.push_back(0);
            for (int i = 0; i < path.size(); i++) {
                costCounter += graph1[path[i]][almacenando]; //contador del costo de viajes
                almacenando = path[i]; //almaceno referencia para despues seguir recorriendo
                pathR.push_back(path[i]); //almaceno el valor en el vector, para despues pasarlo al 'vector de vectores'
            }

            pathR.push_back(costCounter);  // almaceno el valor total del recorrido
            vectorOfVectors.push_back(pathR); // paso el vector al 'vector de vectores'
            pathR.clear(); //limpio al vector

            // Remove the source vertex added
            path.pop_back();

            // Update the hasCycle as true
            hasCycle = true;
        }
        return;
    }

    // Try different vertices as the next vertex
    for (int v = 0; v < N; v++) {

        // Check if this vertex can be added to Cycle
        if (isSafe(v, graph, path, pos) && !visited[v]) {

            path.push_back(v);
            visited[v] = true;

            // Recur to construct rest of the path
            FindHamCycle(graph, pos + 1, path, visited, N);

            // Remove current vertex from path and process other vertices
            visited[v] = false;
            path.pop_back();
        }
    }
}

void hamiltoLect::hamCycle(int graph[][8], int N) {
    // Initially value of boolean flag is false
    hasCycle = false;

    // Store the resultant path
    vector<int> path;
    path.push_back(0);

    // Keeps the track of the visited vertices
    bool visited[N];

    for (int i = 0; i < N; i++){
        visited[i] = false;
    }

    visited[0] = true;

    // Function call to find all hamiltonian cycles
    FindHamCycle(graph, 1, path, visited, N);

    if (!hasCycle) {
        // If no Hamiltonian Cycle is possible for the given graph
        cout << "No Hamiltonian Cycle" << "possible " << endl;
        return;
    }
}

vector<vector<int>> hamiltoLect::getVectorOfVectors() {
    return vectorOfVectors;
}

int hamiltoLect::particion(vector<vector<int>>& caminos,int inicio, int fin){
    int pivote = caminos[inicio][9];
    int i = inicio + 1;
    for(int j = i; j <= fin; j++){
        if(caminos[j][9] < pivote){
            swap(caminos[i],caminos[j]);
            i++;
        }
    }
    swap(caminos[inicio],caminos[i-1]);
    return i-1;
}

void hamiltoLect::QuickSort(vector<vector<int>>& caminos, int inicio, int fin) {
    if(inicio < fin){
        int pivote = particion(caminos,inicio,fin);
        QuickSort(caminos,inicio,pivote-1);
        QuickSort(caminos,pivote+1,fin);
    }
};