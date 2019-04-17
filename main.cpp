#include <iostream>
#include <stdio.h>
#include "listaDu.h"

// OBS :: Foi deixado a main aqui nessa pasta pois foram feitos todos os teste das funções, 
using namespace std;


int main()
{
ListaDup* LisAuxP  =  IniciaListadup();

cout << "Inserindo no Inicio da Lista " << endl;
printf("\n");

InserirIni(LisAuxP, 2);
InserirIni(LisAuxP, 1);
InserirIni(LisAuxP, 40);
Imprimir(LisAuxP);

printf("\n");


cout << "Inserindo no Fim da Lista " << endl;


InserirFimDaLista(LisAuxP,10);
InserirFimDaLista(LisAuxP,8);
Imprimir(LisAuxP);
printf("\n");

cout << "Função -> Remover " << endl; 
printf("\n");


Remove(LisAuxP,1);
Imprimir(LisAuxP);


    return 0;
}
