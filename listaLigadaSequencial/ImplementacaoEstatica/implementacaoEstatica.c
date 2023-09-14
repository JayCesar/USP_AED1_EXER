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

A lista está CHEIA quando não há mais nós disponíveis (i.e., quando dispo == -1). 

A lista está VAZIA quando não há elemento inicial (i.e., quando inicio == -1).

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

    while (i != -1){
        if (l.A[i].chave >= ch) break; // Todo Break sai do loop;
        *ant = i;  // Assim eu tõ acessando o local de memória
        i = l.A[i].prox;
    }
    if (i == -1) return -1;
    if (l.A[i].chave == ch) return (i);
    else return -1;
}

/*
O gerenciamento de nós livres e ocupados exige a criação de rotinas específicas para “alocar” e “desalocar”
um nó da lista apontada por dispo. A alocação envolve descobrir o índice de uma posição válida no vetor na
qual novos dados possam ser inseridos, além de retirar esta posição da lista de disponíveis. A desalocação
envolve a devolução de uma posição à lista de disponíveis para que possa ser reutilizada.

As rotinas de alocação/desalocação não devem ser chamadas sem que sejam seguidas da
correspondente inserção/exclusão, pois haverá perda de dados e a estrutura se tornará inconsistente.
*/

// Obter nó disponível - a lista é alternada
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

// Exclusão do elemento de chave indicada
bool excluirElemListaEnc(int ch, LISTA *l){
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if( i < 0) return (false);
    if(ant == -1) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    // Eu basicamente elimente apenas mudando os 'prox'
    devolverNo(l, i);
    return true;
}

// inserção em lista ordenada sem duplicações
bool inserirElemListaEncOrd(int ch, LISTA *l){
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if((l->dispo < 0) || (i != -1)) return(false);
    i = ObterNo(l);
    l->A[i].chave = ch;
    if(l->inicio < 0) {
        // inserção do primeiro elemento de lista vazia
        l->inicio = i;
        l->A[i].prox = -1;
    }
    else{
        if (ant < 0){
            // inserção no início de lista já existente
            l->A[i].prox = l->inicio; 
            l->inicio = i;
        }
        else {
            // inserção entre dois elementos
            l->A[i].prox = l->A[ant].prox;
            l->A[ant].prox = i;
        }
        return(true);
    }
}


int main()
{
    return 0;
}