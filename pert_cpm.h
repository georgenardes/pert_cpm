#ifndef PERT_CPM_H_INCLUDED
#define PERT_CPM_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

typedef struct {
    int Atividade;
    int Duracao;
    std::vector<int> Precedente;
    int Ida_inicio = 0;
    int Ida_fim = 0;
    int Volta_inicio = 0;
    int Volta_fim = 0;
    int Folga = 0;
}t_vertice;

void le_vertice();

int **Alocar_matriz_real (int qtdVert);

void zeraMatriz(int **mat, int ordem);

void printMatriz(int **mat, int qtd);

//vector<string> splitString(string str, char delimitador);

//vector<t_vertice> readerAtividades(string fileName);

//void adjacencia(vector<t_vertice> atividades);

#endif // PERT_CPM_H_INCLUDED
