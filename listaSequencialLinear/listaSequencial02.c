#include <stdio.h>
#include <stdbool.h>
typedef int TIPOCHAVE;
#define MAX 50

// Criando a lista

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;


// Inicializando a lista:
void initiateList(LISTA *l){
    l->nroElem = 0;
}

// Ver o tamanho da lista
void getListSize(LISTA l){
    printf("Sife of the list: %d", l.nroElem);
}


// Insere item na lista
bool insertItem(LISTA *l, TIPOCHAVE ch){
    if (l->nroElem >= MAX) return false;
    else{
        l->A[l->nroElem].chave = ch;
        l->nroElem++;
        return true;
    }
}

// Imprimir a lista
void printList(LISTA l){
    for (int i = 0; i < l.nroElem; i++){
        printf("Position %d = %d", i, l.A[i].chave);
    }
}

// Pegar primeiro item da lista
void getFirstItem(LISTA l){
    printf("First item: %d", l.A[0].chave);
}

// Pegar último item da lista
void getLastItem(LISTA l){
    printf("Last item: %d", l.A[l.nroElem - 1].chave);
}

// Imrpimir a chave de uma posição n
void getChInPosition(LISTA l, int n){
    printf("The ch of positon %d is %d", n, l.A[n].chave);
}

// Destruir a lista:
void destroyList(LISTA *l){
    l->nroElem = 0; // Repare que é o mesmo que inicializar
}

// Buscar um elemento na lista (ordenada por chave ou não)
int senquencialSearch(LISTA l, TIPOCHAVE ch){
    for (int i = 0; i < l.nroElem; i++){
        if(ch == l.A[i].chave){
            return i;
        }
    }
    return -1; // not found
}

// Busca Binária
int binarySearach(TIPOCHAVE ch, LISTA l){
    int sup, inf, mid;
    inf = 0;
    sup = l.nroElem - 1;
    while (inf <= sup){
        mid = (inf + sup) / 2;
        if (ch == l.A[mid].chave) return mid;
        else{
            if(ch > l.A[mid].chave) inf = mid + 1;
            else sup = mid - 1;  
        }
    }
}

// Retornar a chave do n-ésimo elemento da lista sequencial
int enesimoElem(LISTA l, int n) {
if(n <= l.nroElem) return(l.A[n-1].chave);
else return(-1);
}

// Remover elemento
bool removeElem(TIPOCHAVE ch, LISTA *l){
    for (int i = 0; i < l->nroElem; i++){
        if (ch == l->A[i].chave){
            l->nroElem--;
            for(int j = i; j < l->nroElem; j++){
                l->A[j].chave = l->A[j+1].chave; // E aqui ocorre 'a magia'
            }
        }
    }
}

// Inserção de elemento na lista (de forma direta) 


int main(){

    return 0;
}