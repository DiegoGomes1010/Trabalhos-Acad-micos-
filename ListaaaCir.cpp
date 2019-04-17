#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ListaDuCir.h"


using namespace std;


NoDaListaCir* InicializaNoDaLis(int num)
{
    NoDaListaCir* AuxiP = (NoDaListaCir*)calloc(1,sizeof(NoDaListaCir)); // 
    // Inicializando o Nó da Lista , Onde meu POnteiro auxiliar vai aponta pra ele mesmo 
    AuxiP->num = num;
    AuxiP->prox = AuxiP;
    AuxiP->ant =  AuxiP;

    return AuxiP;  

}


ListaDuCir* InicializaListaCir()
{
    // Inicializando a Lista , Onde os ponteiros vão apontar para NULL
    ListaDuCir* AuxiPLis = (ListaDuCir*) calloc (1, sizeof(ListaDuCir));
     AuxiPLis->InicioDaLista = NULL;
     AuxiPLis->FimDaLista = NULL;

}

void Destroi(NoDaListaCir* AuxiP)
{
    free(AuxiP->ant);
    free(AuxiP->prox);
    free(AuxiP);

}


// Função que vai verificar se minha lista esta vazia
int ListaDuCirVazia(ListaDuCir* AuxiPLis)
{
    return (AuxiPLis->InicioDaLista == NULL);
}

// Função para inserir ELementos no inicio da lista

void Inserir(ListaDuCir* AuxiPLis,int num)
{
    NoDaListaCir* AuxiP = InicializaNoDaLis( num);

        if(ListaDuCirVazia(AuxiPLis)) // Inserindo um elemento em uma lista vazia 
        {
           AuxiPLis->InicioDaLista = AuxiP;
           AuxiPLis->FimDaLista = AuxiP;

        }else
        {
            AuxiP->prox = AuxiPLis->InicioDaLista; // Ponteiro auxiliar  aponta pro inicio da lista
            AuxiPLis->InicioDaLista->ant = AuxiP; // como o ponteiro auxiliar foi atualizado, agora ele aponta pro anterior  A -> B , B-> A
            AuxiPLis->InicioDaLista = AuxiP; // atualiza

            AuxiPLis->InicioDaLista->ant = AuxiPLis->FimDaLista; // Ultimo lugar onde o ponteiro estava (Inicio), o anterior aponta pro final
            AuxiPLis->FimDaLista->prox = AuxiPLis->InicioDaLista; // Com isso é só fazer volta, ponteiro do fim , aponta pro inicio

        }
        
}

void InserirFim(ListaDuCir* AuxiPLis,int num)
{

    NoDaListaCir* AuxiP = InicializaNoDaLis( num);

        if(ListaDuCirVazia(AuxiPLis)) // Verificando se a lista esta vazia 
        {
           AuxiPLis->InicioDaLista = AuxiP;
           AuxiPLis->FimDaLista = AuxiP;

        }else
        {
            NoDaListaCir* AuxiP = InicializaNoDaLis( num);

            AuxiPLis->FimDaLista->prox = AuxiP; // Diferencia um pouco de inserir no inicio
            AuxiP->ant = AuxiPLis->FimDaLista;
            AuxiPLis->FimDaLista = AuxiP;
            AuxiPLis->InicioDaLista->ant = AuxiPLis->FimDaLista;
            AuxiPLis->FimDaLista->prox = AuxiPLis->InicioDaLista;

        }


}


void Remove(ListaDuCir* AuxiPLis , int num)
{

   if(ListaDuCirVazia( AuxiPLis) == 0) // Primeiro verificando se a lista esta vazia 
    {
        NoDaListaCir* aux = AuxiPLis->InicioDaLista;
        
        if(AuxiPLis->InicioDaLista->num == num){
            if(AuxiPLis->InicioDaLista == AuxiPLis->FimDaLista){
                AuxiPLis->InicioDaLista = NULL;
                AuxiPLis->FimDaLista = NULL;
            }
            else{
                AuxiPLis->InicioDaLista = aux->prox;
                AuxiPLis->FimDaLista->prox = AuxiPLis->InicioDaLista;
                AuxiPLis->InicioDaLista->ant = AuxiPLis->FimDaLista;
            }
            free(aux);
        }

        else
        {
            aux = aux->prox;
            while(aux != AuxiPLis->InicioDaLista &&  aux->num != num)
                aux = aux->prox;
            
            if(aux != AuxiPLis->InicioDaLista){
                if(aux == AuxiPLis->FimDaLista)
                    AuxiPLis->FimDaLista = aux->ant;

                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
            }
            
        }

    }

}


void Imprimir (ListaDuCir* AuxiPLis)
{
    if(!ListaDuCirVazia(AuxiPLis))
    {
        NoDaListaCir* AuxiP = AuxiPLis->InicioDaLista; // Ponteiro apontando pro inicio da Lista

        do
        {
            cout << "Os Elementos contidos na Lista são  :: " << AuxiP->num << endl;
            AuxiP = AuxiP->prox;

        } while (AuxiP!= AuxiPLis->InicioDaLista); 
        // Quando o ponteiro percorrer toda a lista e imprimir no display, ele vai retornar pro primeiro elemento 
        // chegando na condição de parada e saindo.
        
        cout << endl;
    }

          
}
    


