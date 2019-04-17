#include <iostream>
#include "listaDu.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

ListaDup* IniciaListadup() { // Inicializando uma Lista, abrindo espaço na memória


    ListaDup* LisAuxP = (ListaDup*) calloc (1, sizeof(ListaDup)); // // o ponteiro deve apontar pra nulL, NO INIC E FIM
    LisAuxP->Inic = NULL;
    LisAuxP->Fim = NULL;
    return LisAuxP;
}


NodaLista* IniciaNodup(int num) {  // Inicializando os nós que estaram contidos na Lista

    NodaLista* Auxp = (NodaLista*) calloc(1, sizeof(NodaLista));
    Auxp->num = num;
    Auxp->prox = NULL;  // o ponteiro deve apontar pra null,tanto prox quanto anteri
    Auxp->anter =NULL;

    return Auxp;

}


int ListaVazia(ListaDup* LisAuxP)
{

    return (LisAuxP->Inic == NULL);

}

void Destroi(NodaLista** Auxp ) // Ponteiro de ponteiro que aponta pra conteudo do no, e usa ref pra apontar pro conteudo dou free , depois atualizo o ponteiro pra null
{

    NodaLista* REF = *Auxp;
        if (REF!=NULL) {
            free(REF);
            *Auxp = NULL;

	}
}

void InserirIni(ListaDup* LisAuxP, int num) // Função que insere pro inicio da Lista
{
    NodaLista* Auxp = IniciaNodup(num);

    if(ListaVazia(LisAuxP)) // Quando a lista estiver vazia , tanto a lista apontar sempre pra NULL
    {
      LisAuxP->Inic = Auxp;
      LisAuxP->Fim = Auxp;
    } else
    {
        Auxp->prox = LisAuxP->Inic; // Ponteiro auxiliar  aponta pro inicio da lista
        Auxp->prox->anter = Auxp; // como o ponteiro auxiliar foi atualizado, agora ele aponta pro anterior  A -> B , B-> A
        LisAuxP->Inic = Auxp; // atualiza
    }    
}


void InserirFimDaLista(ListaDup* LisAuxP, int num)
{

    NodaLista* Auxp = IniciaNodup(num);
// VErificando se a lista esta vazia
        if (ListaVazia(LisAuxP)) {
            LisAuxP->Inic = Auxp;
            LisAuxP->Fim = Auxp;
        }
// Para n ELementos
        else
        {
                NodaLista* Auxp = IniciaNodup(num);

                    LisAuxP->Fim->prox = Auxp;
                    Auxp->anter = LisAuxP->Fim;
                    LisAuxP->Fim = Auxp;
                
        }
        

}

// Função que remove qualquer elemento da lista
void Remove(ListaDup* LisAuxP, int num)
{

    if(ListaVazia(LisAuxP) == 0) // Primeiro verificando se a lista esta vazia 
    {
        NodaLista* Auxp= LisAuxP->Inic;
         
         while(Auxp != NULL && Auxp->num != num )  // Condição que percorre a lista
         	Auxp = Auxp->prox;

	if( Auxp != NULL ){ 
         
            if(Auxp == LisAuxP->Inic) // ponteiro Lis aponta para o inicio da lista e remove, agora precisamos atualizar os ponteiros /**/
            {
                LisAuxP->Inic = Auxp->prox; // ATUALIZANDO OS PONTEIROS
                LisAuxP->Inic->anter = NULL; 
                free(Auxp);
                
            }
                else if(LisAuxP->Fim == Auxp)   // Ponteiro auxiliar verificando se chegou a fim da lista
                {
                    LisAuxP->Fim = Auxp->anter; 
                    LisAuxP->Fim->prox = NULL; 
                     free(Auxp);
                }else

                {
                     Auxp->anter->prox = Auxp->prox; //  lis -> (A -> B) , Lis ->B , Apaga A 
                     Auxp->prox->anter = Auxp->anter; 
                     free(Auxp);   
                }
        }
                

    }



}


void Imprimir(ListaDup* LisAuxP)
{
     NodaLista* Auxp = LisAuxP->Inic;

    
        while (Auxp != NULL){

            cout << "Os Elementos contidos na lista são  :: " << Auxp->num << endl;
            Auxp = Auxp->prox;

         
     }
     


}




