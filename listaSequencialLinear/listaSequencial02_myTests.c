#include <stdio.h>
#include <stdbool.h>
typedef int TIPOCHAVE;
#define MAX 50

// Estrutura Registro
typedef struct{
    TIPOCHAVE chave;
    // more filds
} REGISTRO;

// Estrutura Lista 
// Possui um vetor de REGISTRO dentro da estrutura
// Essse vetor terá um tamanho definido por uma variável exerna 
// chamado nrmElem;
typedef struct{

    REGISTRO A[MAX];
    int nrmElem;

}LISTA;

// Inicialziar a lista
void inicializarLista(LISTA *l){
    l->nrmElem=0;
}

// Vizualizar tamanho da lista
void vizualizarTamanho(LISTA l){
    printf("Tamanho da lista: %i", l.nrmElem);
}

// Buscar um elemento na lista (ordenada por chave ou não)
int buscaSequencial(TIPOCHAVE ch, LISTA l){
    for (int i = 0; i < l.nrmElem; i++){
        if (ch == l.A[i].chave) return i; // achou
    }
    return -1; // não achou
}

// Busca Binária
int buscaBinaria(LISTA l, TIPOCHAVE ch){
    int inf, sup, meio;
    inf = 0;
    sup = l.nrmElem;
    while (inf <= sup){
        meio = (inf + sup) / 2;
    }
    return -1;
}


int main(){
    LISTA x;
    inicializarLista(&x);
    return 0;
}