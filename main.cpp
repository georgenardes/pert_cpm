#include <iostream>
#include "PERT_CPM.h"


using namespace std;

void menu(){
    int op;
    do{

        cout << "\n ------------ MENU ------------ \n\n";
        cout << "1 - Calcula PERT/CPM:" << endl;
        cout << "2 - Desenvolvedores:" << endl;
        cout << "3 - Instrucoes:" << endl;
        cout << "0 - Finaliza programa:" << endl;
        cout << "Informe a opcao desejada:"<< endl;

        cin >> op;
        system("CLS");

		switch (op) {
            case 0:{
                cout << "\nPrograma finalizado!\n\n\n";
                system("pause");
                break;
            }
            case 1:{
                le_vertice();
                system("CLS");
                break;

            }
            case 2:{
                system("CLS");
                cout << "-------Desenvolvedores------\n" <<endl;
                cout << "Diogo Marchi" << endl;
                cout << "George de Borba" << endl;
                cout << "Leonardo Grando" << endl << endl << endl;
                system("pause");
                break;
            }
            case 3:{
                system("CLS");
                cout << "-------Instrucoes------\n" <<endl;
                cout << "Para fazer sua tabela de entrada, devera entrar no arquivo com o nome 'entrada'" << endl;
                cout << "Primeira coluna e o numero da atividade" << endl;
                cout << "Segunda coluna e a duracao dessa atividade" << endl;
                cout << "Terceira coluna e o precedente dessa atividade" << endl;
                cout << "As colunas sao separadas por ponto e virgula" << endl;
                cout << "Se preferir, abra este arquivo no excel" << endl;
                cout << "Se haver mais de um precedente, nesta linha devera colocar com mais uma coluna" << endl << endl << endl;
                system("pause");
                break;
            }
            default: {

                }
        }
		system("CLS");

	}while(op!=0);

}

int main()
{

   menu();
   return 0;
}
