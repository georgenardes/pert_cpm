#include <iostream>
#include <vector>
#include <fstream>
#include "pert_cpm.h"


using namespace std;


int **Alocar_matriz_real (int qtdVert){
    int **matriz = new int*[qtdVert];

    for (int i = 0; i < qtdVert; ++i)
        matriz[i] = new int[qtdVert];

    return (matriz);
}

void zeraMatriz(int **mat, int ordem){// zerando matriz
    for (int i = 0; i < ordem; i++)
        for (int j = 0; j < ordem; j++)
            mat[i][j] = 0;
}


void printMatriz(int **mat, int qtd){
    for(int i = 0; i < qtd; i ++){
        for(int j = 0; j < qtd; j ++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void printVertice(vector<t_vertice> &atividades){
    cout << endl << endl;
    for(int i = 0; i < atividades.size(); i ++){
        cout << "Atividade:\t" << atividades.at(i).Atividade << endl;
        cout << "Ida inicio:\t" << atividades.at(i).Ida_inicio << endl;
        cout << "Ida fim:\t" << atividades.at(i).Ida_fim << endl;
        cout << "Volta fim:\t" << atividades.at(i).Volta_fim << endl;
        cout << "Volta inicio:\t" << atividades.at(i).Volta_inicio << endl;
        cout << "Precedente:\t";
        for(int j = 0; j < atividades.at(i).Precedente.size(); j ++)
            cout << atividades.at(i).Precedente.at(j) << "\t";
        cout << endl;
        cout << "Folga:\t\t" << atividades.at(i).Folga << endl << endl;
    }
}

void calculaCaminhoCritico(vector<t_vertice> &atividades){
    cout << "Caminho critico: " << endl;
    for(int i = 0; i < atividades.size(); i ++){
        if(atividades.at(i).Folga == 0)
            cout << atividades.at(i).Atividade << "\t";
    }
    cout << endl << endl;
    system("pause");
}

void preencheFolga(int **matrizAdjacencia,vector<t_vertice> &atividades){
    for(int i = 0; i < atividades.size(); i ++){
        atividades.at(i).Folga = atividades.at(i).Volta_fim - atividades.at(i).Ida_fim;
    }
    printVertice(atividades);
    system("pause");
    system("cls");
    calculaCaminhoCritico(atividades);

}

void preencheVolta(int **matrizAdjacencia,vector<t_vertice> &atividades){

    //achar o maior fim
    int fim_maior = 0;
    for(int i = 0; i < atividades.size(); i ++){
        for( int j = 0; j < atividades.size(); j ++){
            if(atividades.at(i).Ida_fim > fim_maior) //procura maior valor de fim
                fim_maior = atividades.at(i).Ida_fim;
        }
    }

    for(int i = atividades.size()-1; i >= 0 ; i --){
        atividades.at(i).Volta_fim = fim_maior;
    }
    atividades.at(atividades.size()-1).Volta_inicio = fim_maior;

    for(int i = atividades.size()-1; i >= 0 ; i --){
        for( int j = 0; j < atividades.size(); j ++){
            if(matrizAdjacencia[i][j] == 1){ //procura maior valor de fim
                if((atividades.at(i).Volta_inicio - 1) < atividades.at(j).Volta_fim){
                    atividades.at(j).Volta_fim = atividades.at(i).Volta_inicio - 1;
                    atividades.at(j).Volta_inicio = atividades.at(j).Volta_fim - atividades.at(j).Duracao + 1;
                }
            }
        }
    }
    preencheFolga(matrizAdjacencia, atividades);
}

void preencheIda(int **matrizAdjacencia,vector<t_vertice> &atividades){
    atividades.at(0).Ida_inicio = 1;//inserindo valores iniciais, ja que o primeiro nao tem precedentes
    atividades.at(0).Ida_fim = (atividades.at(0).Ida_inicio + atividades.at(0).Duracao - 1);

    for(int i = 0; i < atividades.size(); i ++){
        for( int j = 0; j < atividades.size(); j ++){
            if(matrizAdjacencia[i][j] == 1){//se tiver precedente, continua do valor anterior
                if(atividades.at(i).Ida_inicio < (atividades.at(j).Ida_fim + 1)){
                    atividades.at(i).Ida_inicio = (atividades.at(j).Ida_fim + 1);
                    atividades.at(i).Ida_fim = (atividades.at(i).Ida_inicio + atividades.at(i).Duracao - 1);
                }
            }
        }
    }
    preencheVolta(matrizAdjacencia, atividades);
}

void adjacencia(vector<t_vertice> &atividades){
    int **matrizAdjacencia;
    matrizAdjacencia = Alocar_matriz_real(atividades.size());
    zeraMatriz(matrizAdjacencia, atividades.size());

    for(int i = 0; i < atividades.size(); i ++){
        for(int j = 0; j < atividades.size(); j ++){
            for(int k = 0; k < atividades.at(i).Precedente.size(); k++){
                if(atividades.at(i).Precedente.at(k) == (j+1))
                    matrizAdjacencia[i][j] = 1;
            }
        }
    }
    cout << endl << endl;
    cout << "Imprimindo matriz adjacencia" << endl << endl;
    printMatriz(matrizAdjacencia, atividades.size());
    system("pause");
    system("cls");
    preencheIda(matrizAdjacencia, atividades);
}


vector<string> splitString(string str, char delimitador){
    vector<string> tokens;
    string token = "";
    for(unsigned int i = 0; i < str.size(); i++)
    {
        if(str.at(i) == delimitador)
        {
            tokens.push_back(token);
            token = "";
        }
        else
        {
            token.push_back(str.at(i));
        }
        if(i == str.size()-1)
        {
            tokens.push_back(token);
        }
    }
    return tokens;
}

vector<t_vertice> readerAtividades(string fileName){
    ifstream fileReader(fileName);
    vector<t_vertice> atividades;

    if (fileReader.is_open())
    {
        t_vertice atividade;
        vector<string> splited;
        string line;
        int i = 0;

        while (getline(fileReader, line) ) {
            splited = splitString(line, ';');

            int At = atoi(splited[0].c_str());
            atividade.Atividade = At;

            int duracao = atoi(splited[1].c_str());
            atividade.Duracao = duracao;

            // pega todos os precedentes
            for(int j = 2; j < splited.size();  j++)
                atividade.Precedente.push_back(atoi(splited[j].c_str()));

            i++;
            atividades.push_back(atividade);
            atividade.Precedente.clear();
        }

        cout << "Arquivo lido, fechando arquivo!" << endl;

        fileReader.close();
        return atividades;
    } else {
        cout << "Nao foi possivel abrir o arquivo!" << endl;
        return atividades;
    }
}

void le_vertice(){
    vector <t_vertice> atividades;

    cout << "Lendo arquivo..." << endl;
    system("pause");
    atividades = readerAtividades("entrada.csv");

    cout << "Atividades \t Duracao \t Precedentes" << endl;
    for(unsigned int i = 0; i < atividades.size(); i ++){
        cout << "    " << atividades.at(i).Atividade << "\t\t    " <<  atividades.at(i).Duracao << "\t\t      " ;
        for(int j = 0; j < atividades.at(i).Precedente.size(); j++)
            cout <<  atividades.at(i).Precedente.at(j) << "\t  ";
        cout << endl;
    }
    system("pause");
    adjacencia(atividades);
}
