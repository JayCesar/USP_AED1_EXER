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
   int sup, inf, meio;
   inf = 0;
   while (inf <= sup){
        meio = (inf + sup) / 2;
        if(ch == l.A[meio].chave) return meio;
        else{
            if (l.A[meio].chave < ch) inf = meio + 1;
            else sup = meio - 1 ;
        }
   }
   return -1;
}

// Inserção de elemento na lista (de forma direta) 
bool inserirElemento(LISTA *l, int i, TIPOCHAVE ch){
        if((l->nrmElem >= MAX) || (i < 0) || (i > (l->nrmElem))) return (false);
        // Se a lsita tiver cheia, ou a posição for negativa, ou a posição for maior do que o número de elementos (FALSE);
        if((l->nrmElem > 0) && (i < l->nrmElem))
            for (int j = l->nrmElem; j >= (i + 1); j--)
                l->A[j] = l->A[j-1]; // Pega o da esquerda e põe na direita
        l->A[i].chave = ch;
        l->nrmElem++;
        return(true);
}   

// Programa principal
int main(){
    LISTA x;
    inicializarLista(&x);
    return 0;
}