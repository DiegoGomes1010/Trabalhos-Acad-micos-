#ifndef LISTA
#define LISTA


typedef struct No 
{
    int num;
    struct No* prox;
    struct No* anter;        
}NodaLista;

    typedef struct lista
{
    NodaLista* Inic;
    NodaLista* Fim;
}ListaDup;


ListaDup* IniciaListadup();
int ListaVazia(ListaDup* LisAuxP);
void InserirIni(ListaDup* LisAuxP, int num);
void InserirFimDaLista(ListaDup* Lis, int num);
void Remove(ListaDup* LisAuxP, int num);
void Imprimir(ListaDup* LisAuxP);

NodaLista* IniciaNodup(int num);
void Destroi(NodaLista** Auxp);

#endif
