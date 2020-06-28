#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "pert_cpm.h"


using namespace std;



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

vector<t_vertice> readerAtividades(string fileName) {
    ifstream fileReader(fileName);
    if (fileReader.is_open())
    {
        vector<t_vertice> atividades;
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

            int precedente = atoi(splited[2].c_str());
            atividade.Precedente[0] = precedente;

            precedente = atoi(splited[3].c_str());
            atividade.Precedente[1] = precedente;

            precedente = atoi(splited[4].c_str());
            atividade.Precedente[2] = precedente;

            precedente = atoi(splited[5].c_str());
            atividade.Precedente[3] = precedente;

            i++;
            atividades.push_back(atividade);
        }
        fileReader.close();
        return atividades;
    }
}




void le_vertice(){
    vector <t_vertice> atividades;

    cout << "Lendo arquivo..." << endl;
    atividades = readerAtividades("entrada.csv");

    cout << "Atividades \t Duracao \t Precedentes" << endl;
    for(int i = 0; i < (atividades.size() - 1); i ++)
        cout << "    " << atividades.at(i).Atividade << "\t\t    " <<  atividades.at(i).Duracao << "\t\t      " <<  atividades.at(i).Precedente[0] << "\t  "  <<  atividades.at(i).Precedente[1] <<  endl;


}
