#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef struct
{
    int chave;
    int prox; // Quando com -1 (indica que não há um sucessor)
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int inicio; // Elementos efetivos (posição no vetor onde começa a lista)
    int dispo;  // Elementos livres
} LISTA;

/*

Ao ser criada, a lista possui inicio = -1 (que indica que a lista está vazia) e dispo = 0 (ou seja, a primeira
posição do vetor está disponível).

O campo prox do último registro recebe o valor -1 indicando que não há mais elementos depois daquele ponto.

*/

// Inicializando a lista
void inicializarListaLigadaEstatica(LISTA *l)
{
    l->inicio = -1;
    l->dispo = 0;
    for (int i = 0; i < MAX - 1; i++)
    {
        l->A[i].prox = i + 1; // Aponta para o próximo até 49 e 49 vai apontar para -1;
    }
    l->A[MAX - 1].prox = -1; // Ou seja, não há um elemento sucessor;
}

// Exibiando a lista completa
void exibirLista(LISTA l)
{                     // Vamos supor que a lista não esta vazia
    int i = l.inicio; // Mas não é inicio = -1?
    while (i > -1)
    {
        printf("d", l.A[i].chave);
        i = l.A[i].prox;
    }
}

// BuscaSequencial, retornando a posição da chave e do anterior
int buscaSeqOrd(int ch, LISTA l, int *ant)
{
    int i = l.inicio;
    *ant = -1; // Porque não existe

    while (i != -1)
    {
        if (l.A[i].chave >= ch) break; // Todo Break sai do loop;
        *ant = i;  // Assim eu tõ acessando o local de memória
        i = l.A[i].prox;
    }
    if (i == -1)
        return -1;
    if (l.A[i].chave == ch)
        return (i);
    else
        return -1;
}

// Obter nó disponível - a lista é alterada
int obterNo(LISTA* l) {
    int result = l->dispo;
    if(l->dispo > -1) {
        l->dispo = l->A[l->dispo].prox;
    }
    return(result);
}

// Devolver nó p/ dispo – a lista é alterada
void devolverNo(LISTA* l, int j) {
    l->A[j].prox= l->dispo;
    l->dispo = j;
}

int main()
{

    return 0;
}