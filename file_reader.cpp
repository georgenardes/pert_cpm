#include "pert_cpm.h"

using namespace std;

typedef struct {
    int Atividade;
    int Duracao;
    int Precedente;
    int Ida_inicio;
    int Ida_fim;
    int Volta_inicio;
    int Volta_fim;
    int Folga;
}t_vertice;


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
    std::ifstream fileReader(fileName);
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

            int precedente = atoi(splited[1].c_str());
            atividade.Precedente = precedente;

            int duracao = atoi(splited[2].c_str());
            atividade.Duracao = duracao;

            i++;
            atividades.push_back(atividade);
        }
        fileReader.close();
        return atividades;
    }
}

