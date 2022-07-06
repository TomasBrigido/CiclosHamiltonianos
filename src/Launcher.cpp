#include "Launcher.h"
Launcher::Launcher() {
    interactiveMenu();
}

void Launcher::interactiveMenu() {
    bool counterOne = false;
    bool flag = false;
    string word;
    system("color 6");
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "                                PARCIAL 3 - AyEDD" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    printComands();

    selectorCiry("MA");

    while(!counterOne){
        cout << "       Metodo a Testear: ";
        getline(cin,word);
        cout << "\n";
        convertLower(word);
        if(word == "exit"){
            exitLauncher();
            break;
        } else if(word == "qsciudad"){
            orderedVectorQS(true);
        } else if(word == "qsnumero"){
            orderedVectorQS(false);
        } else if(word == "treeciudad"){
            orderedTreeQS(true);
        } else if(word == "treenumero"){
            orderedTreeQS(false);
        } else if(word == "treecompleto"){
            printTreeComplete(true);
        } else if(word == "treeso"){
            printTreeComplete(false);
        }else if(word == "comandos"){
            printComands(); //lelo
        }else if(word == "ciudad"){
            while (!flag){
                cout << "Ingrese la ciudad de salida - SIN ESPACIOS (Opciones de ciudades de Origen: MA, RO, PA, AM, ZU, BE, VA, VI): ";
                string city;
                getline(cin,city);
                convertHigh(city);
                if(city == "MA" || city == "RO" || city == "PA" || city == "AM" || city == "ZU" || city == "BE" || city == "VA" || city == "VI"){
                    selectorCiry(city);
                    cout << "               Ciudad ingresada correctamente! :) " << endl;
                    cout << "\n";
                    flag = true;
                }else {
                    cout << "\n";
                    cout << "*** ERROR 404 (VERSION AyEDD): CIUDAD NO ENCONTRADA, INTENTE NUEVAMENTE ***" << endl;
                    cout << "\n";
                }
            }
            flag = false;
        }
        else {
            cout << "         */*/*---  COMANDO NO RECONOCIDA, INTENTE NUEVAMENTE  ---*/*/*" << endl;
            cout << "\n";
        }
    }
}

void Launcher::orderedVectorQS(bool complete){
    vector<vector<int>> era_una_vez = vectorH.getVectorOfVectors();
    vectorH.QuickSort(era_una_vez,0,era_una_vez.size()-1);
    printOrderQS(complete,era_una_vez);
}

void Launcher::orderedTreeQS(bool complete) {
    vector<vector<int>> era_una_vez = test->getHamiltonians();
    vectorH.QuickSort(era_una_vez,0,era_una_vez.size()-1);
    printOrderQS(complete,era_una_vez);
}

void Launcher::printOrderQS(bool complete, vector<vector<int>> era_una_vez) {
    if(complete){
        for(int i = 0; i < era_una_vez.size(); i++){
            cout << "               ";
            for(int j = 0; j < 10; j++){
                if(j != 9){
                    cout << getName(era_una_vez[i][j]) << " ";
                }else{
                    cout << " costo total: "<<  era_una_vez[i][j] << " ";
                }
            }
            cout << endl;
        }
    }else{
        for(int i = 0; i < era_una_vez.size(); i++){
            cout << "               ";
            for(int j = 0; j < 10; j++){
                if(j!=9){
                    cout << era_una_vez[i][j] << " ";
                }else{
                    cout << " costo total: " <<  era_una_vez[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}

void Launcher::printTreeComplete(bool order) {
    if(order){
        test->print();
    }else{
        test->printHamiltonians(test->getHamiltonians());
    }
}

string Launcher::getName(int name) {
    return nameIndexes[name];
}

void Launcher::convertLower(string &s) {
    for(int i = 0; i<s.length();i++){
        s[i] = towlower(s[i]);
    }
}
void Launcher::convertHigh(string &s) {
    for(int i = 0; i<s.length();i++){
        s[i] = toupper(s[i]);
    }
}

void Launcher::selectorCiry(string origin) {
    int originIndex=0;
    for (int i = 0; i < nameIndexes.size(); i++) {

        if (origin == nameIndexes[i]) {

            originIndex = i;
            break;
        }
    }

    MTreeNode* treeRootTest = new MTreeNode(origin,originIndex);

    test->newMTree(treeRootTest, grapheno, nameIndexes); //se carga con la matriz de Launcher, porque con el llamado a la de hamiltoLect
    test->generateTree(originIndex,treeRootTest);
}

void Launcher::printComands() {
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "  Comandos de uso (TODO JUNTO, SIN ESPACIOS, MAYUSCULAS O MINUSCULAS ES INDISTINTO): " << endl;
    cout << "\n";
    cout << "   - Impresion del Arbol cargado  = treecompleto" <<endl;
    cout << "   - Impresion de los Datos previo a ser ordenados = treeso" <<endl;
    cout << "   - Lectura y ordenamiento QS VECTOR POR CIUDAD = qsciudad" <<endl;
    cout << "   - Lectura y ordenamiento QS VECTOR POR NUMERO DE MATRIZ = qsnumero" <<endl;
    cout << "   - Lectura y ordenamiento QS ARBOL POR CIUDAD = treeciudad" <<endl;
    cout << "   - Lectura y ordenamiento QS ARBOL POR NUMERO DE MATRIZ = treenumero" <<endl;
    cout << "   - Listar los comandos posibles = comandos"<<endl;
    cout << "   - Cambio de ciudad de Origen = ciudad"<<endl;
    cout << "   - Terminacion del Programa = exit" <<endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
}

void Launcher::exitLauncher() {
    cout << "         **********************************************" << endl;
    cout << "            FIN DEL PROGRAMA, GRACIAS POR PROBARLO!" << endl;
    cout << "         **********************************************" << endl;
    cout << "\n";
    cout << "                                9999999999\n"
            "                             99           99\n"
            "               99999       99               99\n"
            "              9     9    99     ||    ||      99\n"
            "              9     9   99      ||    ||       99\n"
            "              9     9  99       ||    ||        99\n"
            "               9   9   9                         99\n"
            "             999999999999                         99\n"
            "            9            9  99              99    99\n"
            "           99            9   99            99     99\n"
            "          99   99999999999     99        99      99\n"
            "          9               9      99999999       99\n"
            "          99              9                    99\n"
            "           9   999999999999                   99\n"
            "           99           9  99                99\n"
            "            999999999999     99            99\n"
            "                               999999999999"<< endl;
}