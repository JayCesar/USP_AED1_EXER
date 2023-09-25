// Estes foram os testes que fiz com o Edgar no Lab 8 (17/08/2023) sobre Lista Sequencias

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int TIPOCHAVE;
#define MAX 50

//Estrutura Registro
typedef struct {
 TIPOCHAVE chave;
} REGISTRO;

//Estrutura Lista
typedef struct {

 REGISTRO A[MAX];
 int nroElem;

} LISTA;

void iniciaLista(LISTA *l){
    l->nroElem = 0;
}

void veTamanho(LISTA l){    
    printf("Tamanho = %d\n", l.nroElem);
}

void insere(LISTA *l, TIPOCHAVE ch){
    
    l->A[l->nroElem].chave = ch;
    l->nroElem++;

}


void imprimeLista(LISTA *l){
    for (int i = 0; i < l->nroElem; i++){
        printf("Posicao %d = %d\n",i, l->A[i].chave);
    }
}

void primeiro(LISTA *l){
    printf("Primeiro Elemento lista = %d\n", l->A[0].chave);

}

void ultimo(LISTA *l){
    
    printf("Ultimo Elemento lista = %d\n", l->A[l->nroElem-1].chave);

}

void destruir(LISTA *l){
    l->nroElem = 0;
}

int posicao(LISTA *l, int n){

return l->A[n].chave;

}

bool inserirElemListaSeq(TIPOCHAVE ch, int pos, LISTA *l){
    for (int i = 0; i < l->nroElem; i++){
        if (ch == l->A[i].chave){
            return false;
        }
    }
    for (int i = l->nroElem; i > pos; i-- ){

        l->A[i+1].chave = l->A[i].chave;     
    
    }
    l->A[pos].chave = ch;
    l->nroElem++;
    return true;
}

int buscaSeq(TIPOCHAVE ch, LISTA l){
    for (int i = 0; i < l.nroElem; i++){
        if (ch == l.A[i].chave){
            return i;
        }
    }
    return -1;
}

bool removeElem(TIPOCHAVE ch, LISTA *l){

    for (int i = 0; i < l->nroElem; i++){
        if (ch == l->A[i].chave){
            l->nroElem--;
            for (int j = i; j < l->nroElem; j++){
                l->A[j].chave = l->A[j+1].chave;
            }
            return true;
        }   
    }
    return false;

}

int main(){
    LISTA x;
    iniciaLista(&x);
    veTamanho(x);
    insere(&x, 13);
    insere(&x, 10);
    insere(&x, 12);
    insere(&x, 14);
    veTamanho(x);
    
    
    return 0;
}