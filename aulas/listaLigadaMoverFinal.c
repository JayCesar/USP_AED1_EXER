// Aula dia 13/09/2023 | Quarta-feira
#include <stdbool.h>
#include <stdio.h>
#define MAX 50

// Lista ligada:
typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int dispo;
} LISTALigEst;

typedef struct {
    int chave;
    int prox;
} REGISTRO;

// Lista Sequencial:
typedef struct {
 int chave;
} REGISTRO;

typedef struct {
 REGISTRO A[MAX];
 int nroElem;
} LISTAseq;

bool listasIguais(LISTAseq *l1, LISTALigEst *l2){

    int i1 = 0; //seq
    int i2 = l2->inicio;
    
    while(i2!= -1 && i1 < l1->nroElem){
        if (l1->A[i1].chave != l2->A[i2].chave) return false;
        i1++;
        i2 = l2->A[i2].prox;
    }
    // Agora eu faço o teste fora do laço:
    if (i1 < l1->nroElem || i2 != -1) return false; // tamanhos diferem
    return true;
}

// Obs: Isso torna-se complexo porque são duas listas

// Agora irei anexar
// Para insetir o final da lista, eu preciso achar o final da lista (primeiro);
// Eu preciso achar um endereço e ver se está disponível

// Inserir um elemento em uma lista ligada
bool anexar(LISTALigEst *l, int ch){
    int novo = obterNo(&l);
    if(novo == -1) return false; // se está vazio   
    l->A[novo].chave = ch;
    l->A[novo].prox = -1; // Adicionado posteriormente
    int i = l->inicio;
    int fim = -1;
    while (i != -1){
        fim = 1;
        i = l->A[i].prox;
    }  
    if (fim > -1){
        l->A[fim].prox = novo;
    }else{
        l->inicio = novo;
    }
}

// Obs: o que foi feito é implementação estática! Logo virá a dinâmica


int main(){
     
    return 0;
}