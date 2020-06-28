#include "PERT_CPM.h"
#include <iostream>
using namespace std;

int *Alocar_vetor_real( int qtd_vert){
    int *color = new int [qtd_vert];
    return (color);
}

void zera_vetor(int *vertices, int ordem){
    for (int i = 0; i < ordem; i++)
        vertices[i] = 0;
}

void le_vertice(){
    int qtd_vert = 0;
    cout << "Digite a quantidade de vertices: ";
    cin >> qtd_vert;
    t_vertice vertice[qtd_vert];

    char precedente = ' ';
    int duracao = 0;

    for(int i = 0; i < qtd_vert; i ++){
        cout << "Digite o precedente do vertice[" << i << "] = " << endl;
        cin >> precedente;
        vertice[i]->Precedente = precedente;

        cout << "Digite a duracao do vertice[" << i << "] = " << endl;
        cin >> duracao;
        vertice[i]->Duracao = duracao;
    }



   vertice->Duracao = 0;

}
