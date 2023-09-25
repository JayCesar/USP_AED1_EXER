#include <stdio.h>
#include <stdbool.h>
typedef int TIPOCHAVE;
#define MAX 50

typedef struct{
    TIPOCHAVE chave;
    int prox;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio;
    int dispo; 
} LISTA;

// Inicializando a lista
void inicializarALista(LISTA *l){
    l->inicio = -1;
    l->dispo = 0;
    for (int i = 0; i < MAX - 1; i++){
        l->A->prox = i + 1;
    }
    l->A[MAX - 1].prox = - 1;
}

// Exibiando a lista completa
void exibeLista(LISTA l){
    int i = l.inicio;
    while (i > -1){
        printf("Item da posicao %d da lista: %d", l.A[i].chave);
        i = l.A[i].prox;
    }
}

// BuscaSequencial, retornando a posição da chave e do anterior
int buscaSeqOrd(int ch, LISTA l, int* ant){

    int i = l.inicio;
    *ant= -1;

    while (i != -1) {
        if(l.A[i].chave >= ch) break;
        *ant = i;
        i= l.A[i].prox;
    }

    if(i==-1) return -1;
    if(l.A[i].chave==ch) return(i);
    else return -1;
}

// Obter nó disponível - a lista é alterada
int obterNo(LISTA *l){
    int result = l->dispo;
    if (l->dispo > -1){
        l->dispo = l->A[l->dispo].prox;
    }
    return (result);
}

// Devolver nó p/ dispo – a lista é alterada
void devolverNo(LISTA *l, int j){
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

// Exclusão do elemento de chave indicada
bool excluirElemListaEnc(int ch, LISTA *l){
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if (i < 0) return(false);
    if (ant == -1) l->inicio = l->A[i].prox;

}



// if(ant == -1) l->inicio = l->A[i].prox;
// else l->A[ant].prox = l->A[i].prox;
// devolverNo(l, i);
// return(true);