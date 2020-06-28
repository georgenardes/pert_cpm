#ifndef PERT_CPM_H_INCLUDED
#define PERT_CPM_H_INCLUDED

#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>

typedef struct {
    int Atividade;
    int Duracao;
    int Precedente[3];
    int Ida_inicio;
    int Ida_fim;
    int Volta_inicio;
    int Volta_fim;
    int Folga;
}t_vertice;

void le_vertice();

#endif // PERT_CPM_H_INCLUDED
