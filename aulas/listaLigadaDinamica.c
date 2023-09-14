// Aula do dia 14/09 - Quinta-feira
// Listas Ligadas Dinâmicas
#include <malloc.h>
# include <stdbool.h>

typedef struct estrutura {
    int chave;
    int info;
    struct estrutura *prox;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

// BUSCA
NO* BUSCA(LISTA *l, int ch, NO* *ant){ // busca ....... &ant (ficaria assim a implementação)
    *ant = NULL;
    NO* p = l->inicio;
    while (p){
        if(p->chave = ch) return p;
        if(p->chave > ch) return NULL; // Só funciona em uma lista ordenada por chave
        *ant = p;
        p = p->prox;
    }
    return NULL; // Isso é caso não funcione em nenhum dos casos acima
}


// TODO: Colocar lado a lado (busca diâmica e Busca sequencial)
// TODO: Por que ' NO* *ant)';
// Eu posso modificar ele - NO* *ant (Eu posso fazer o que precisar com isso)

// EXCLUSÃO
bool excluir(LISTA *l, int ch){
    NO* ant;
    NO* atual = busca(l, ch, &ant);
    if (atual == NULL) return false; // Ou if (!atual)
    if (ant) ant->prox = atual->prox; // se existe um anterior
    else l->inicio = atual->prox; // Caso seja o primeiro item e não haja algo antes
    // Depois preciso fazer o free (liberar o espaço);
    free(atual);
    return true;
}

// INSERSÇÃO
bool inserir(LISTA *l, int ch){
    NO* ant;
    NO* atual = busca(l, ch, &ant);
    if(atual) return false; // Já existe
}