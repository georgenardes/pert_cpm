
/*
 * File:   keyboard.h
 * Author: George
 *
 * Created on 28 de Junho de 2020, 14:35
 */
#ifndef PERT_CPM_H_INCLUDED
#define PERT_CPM_H_INCLUDED

typedef struct {
    int Duracao;
    char Precedente;
    int Ida_inicio;
    int Ida_fim;
    int Volta_inicio;
    int Volta_fim;
}t_vertice;



void le_vertice();

int *Alocar_vetor_real(int qtd_vert);

void zera_vetor(int *vertices, int ordem);

#endif // PERT_CPM_H_INCLUDED
