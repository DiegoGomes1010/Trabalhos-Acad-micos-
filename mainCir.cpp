#include <iostream>
#include <stdio.h>
#include "ListaDuCir.h"

using namespace std;

// OBS :: Foi deixado a main aqui nessa pasta pois foram feitos todos os teste das funções, 

int main()

{
    ListaDuCir*  AuxiPLis = InicializaListaCir();
  
        cout << "Inserindo elementos na Lista " << endl; 
        cout << endl;

    Inserir(AuxiPLis,11);
    Inserir(AuxiPLis,10);
    Inserir(AuxiPLis,4);
    Imprimir(AuxiPLis);

    cout << "Removendo Elementos Impares" << endl;
    printf("\n");

    Remove(AuxiPLis,11);
    Imprimir(AuxiPLis);

    cout << "Inserindo no fim da lista" << endl;

    InserirFim(AuxiPLis,12);
    InserirFim(AuxiPLis,14);
    Imprimir(AuxiPLis);
    
    return 0;
}