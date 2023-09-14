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
NO* busca(LISTA *l, int ch, NO* *ant){ // busca ....... &ant (ficaria assim a implementação)
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

// INSERÇÃO (ela insere na ordem);
bool inserir(LISTA *l, int ch){
    NO* ant;
    NO* atual = busca(l, ch, &ant);
    if(atual) return false; // Já existe
    NO* novo = (NO*) malloc(sizeof(NO)); // Aqui o NO sem asteriscos é a estrutura, o tipo!
    novo->chave = ch;
    // Agora preciso tratar os casos de inserção
    // Caso haja um anterior

    // Agora verifico se a lista está vazia (se não existe início) e já aplico os dois casos
    if(ant) {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    else{
        novo->prox = l->inicio; // Lista vazia é quando o iníccio é null
        l->inicio = novo;
    }   
    return true; 
}

// (1) MOVER Ch para frente da lista (versão 1);
// (2) MOVER P para frente da lista (versão 2);

// (Versão 1);
void moverChParaInicio(LISTA *l, int ch){ // Aqui é um caso especial
    NO* ant;
    if(l->inicio && l->inicio->chave == ch) return; // Passo 1: preciso mover?
    NO* p = busca(l, ch, &ant); // Passo 2: Busca
    if(ant) ant->prox = p->prox;  // Passo 3: Recortar o elemento
    else l->inicio = p->prox;
    // Agora movo para o início da lista
    p->prox = l->inicio; // Passo 4: Colocar no início
    l->inicio = p;
}

// Obs: A (versão 2) ele fez na lousa mas não consegui anotar


// Destruir a lista
void destruir(LISTA* l){
    NO* p = l->inicio;
    while(p){
        NO* aux = p->prox;
        free(p);
        p = aux;
    }
    l->inicio = NULL;
}

// Seuja uma lista que aceita chaves repetidas, sem ordem;
// Problema: eliminar todas ocorrências de uma chave ch