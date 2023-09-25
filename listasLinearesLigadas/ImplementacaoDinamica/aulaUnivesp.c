#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // outros campos..
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

// Funções de gerenciamento
/*
- Inicializar a estrutura
- Retornar a quantidade de elementos válidos;
- Exibir os elementos da estrutura
- Buscar por um elemento na estrutura
- Inserir elementos na estrutura
- Excluir elementos da estrutura
- Reinicializar a estrutura
*/

// Inicializar a estrutura
void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

// Retornar a quantidade de elementos válidos;
int tamanho(LISTA* l){
    PONT end = l->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

// Exibir os elementos da estrutura
void exibirLista(LISTA* l){
    PONT end = l->inicio;
    printf("Lista: \" ");
        printf("%i ", end->reg.chave);
        end = end->prox;
    printf("\"\"n");
}

// Buscar por um elemento na estrutura 
// (1) Sem estar ordenanda:
PONT buscaSequencial(LISTA* l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while(pos != NULL){
        if (pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;
}

// (2) Lista ordenada pelos valores das cahves dos registros (Ordenada)
PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while(pos != NULL && pos->reg.chave < ch) pos = pos->prox;
    if (pos != NULL & pos->reg.chave == ch) return pos;
    return NULL;
}

// Inserir elementos na estrutura

// (1) Função auxiliar que vai verificar se o elemento que quero inserir já existe:
PONT buscaSequencialEx(LISTA* l, TIPOCHAVE ch, PONT* ant){
    *ant = NULL;
    PONT atual = l->inicio;
    while((atual != NULL) && (atual->reg.chave<ch)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
    // IMPORTANTE: Independente se encontrar ou não, a variável ant terá o endereço do elemento anterior ao que deve ser inserido
}

// (2) Insersão ordenada:
bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialEx(l, ch, &ant);
    if(i != NULL) return false; // Ou seja, já existe
    i = (PONT) malloc(sizeof(ELEMENTO)); // Senão ele aloca memória para esse elemento
    i->reg = reg;
    if(ant == NULL){ // Caso seja o primeiro
        i->prox = l->inicio;
        l->inicio = i;
    } else{ // Caso não saja o primeiro
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

// Exclusão de um elemento
bool excluirElmLista(LISTA* l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaSequencialEx(l,ch,&ant);
    if (i == NULL) return false;
    if (ant == NULL) l->inicio = i->prox; // Caso seja o primeiro
    else ant->prox = i->prox; // Caso não seja o primeiro
    free(i); // Libero o i
}

// Reinicialização da lista
// Precisamos liberar/excluir todos os elementos dentro da lista (não basta só dizer que início é NULL)
void reinicializarLista(LISTA* l){
    PONT end = l->inicio;
    // Eu preciso de uma auxiliar porque preciso saber quem é o próximo elemento. Ela se chama apagar
    while (end != NULL){
        PONT apagar = end; // Essa é a variável auxiliar
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}