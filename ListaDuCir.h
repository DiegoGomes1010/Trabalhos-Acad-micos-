#ifndef CIRLISTA
#define CIRLISTA


//Estrutura de Dados.

typedef struct NoCir 
{
    int num;
    struct NoCir* prox;
    struct NoCir* ant;

}NoDaListaCir;


typedef struct ListaCir
{
    NoDaListaCir* InicioDaLista;
    NoDaListaCir* FimDaLista;

}ListaDuCir;

// Funções do Programa
ListaDuCir* InicializaListaCir();
int ListaDuCirVazia(ListaDuCir* AuxiPLis);
void Inserir(ListaDuCir* AuxiPLis,int num);
void InserirFim(ListaDuCir* AuxiPLis,int num);
void Imprimir (ListaDuCir* AuxiPLis);
void Remove(ListaDuCir* AuxiPLis, int num);

NoDaListaCir* InicializaNoDaLis(int num);
void Destroi(NoDaListaCir* AuxiP);
#endif