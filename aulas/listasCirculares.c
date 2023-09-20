// Aula do dia 20/09 - Listas Circulares
// Algoritmos
// Listas circulares
// Listas com sentinela
// TODO: Pegar um código e aplicar a circularidade

// Dada uma lista ligada dinâmia l1, efetuar uma cópia retornando o resultado (quero duplicar a lista):
// Eu percorro cada elemento e faço um MALLOC;
// É uma função que retorna um tipo ponteiro de LISTA;
LISTA* copia(LISTA *l1){ // Percorro uma lista e crio outra ao mesmo tempo;
    LISTA resp;
    resp.inicio = NULL;
    NO* p = l1->inicio;
    while(p){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave;
        novo->prox = NULL; // NÃO FAÇA novo->prox = p->prox;
        if(fim) fim->prox=novo;
        else resp.inicio = novo; // Se não tiha início, agora tem.
        fim->prox = novo; // Eu até poderia bolir o 'fim';
        p=p->prox;
    } // end while
    return (&resp); 
}

// Agora vem a circularidade (talvez eu utilize no EP):
// Dica: Eu primeiro resolvo o problema do EP e depois vem a circularidade

// Exibir Lista Circular
void exibirListaCirc(LISTA_CIRC *l){
    NO* P = l->inicio;
    while(p){
        prntf("%d", p->chave);
        p=p->prox;
        if(p==l->inicio) break; // Não termina mais em NULL
    }
}

// Remover primeiro Elemento da Lista (exclui o inicio)
void excluirPrimeiro(LISTA_CIRC *l){
    if(l->inicio){ // Agora preciso analisar os casos.
        NO* ult = ultimo(l->inicio);
        ult->prox = l->inicio->prox;
        NO* aux = l->inicio;
        l->inicio - l->inicio->prox;
        if(l->inicio == aux) p->inicio = NULL; // Se ainda for igual;
        free(aux);
    }
}

// Funçaõ auxiliar ULTIMO
NO* ultimo(NO* iniccio){
    NO* ult = null;
    NO* p = inicio;
    while(p){
        ult = p;
        p=p->prox;
        if(p==inicio) break;
    }
    return ult;
}

// Elemento Sentinela (Só tem impacto em algoritmo de busca)
typedef struct{
    NO* inicio;
    NO* sent;
} LISTA_SENT;

// Inicializar
void inicializar(LISTA_SENT *l){
    l->sent = (NO*) malloc(sizeof(NO));
    l->inicio = l->sent;
}

// Exibir
void exibir(LISTA_SENT *l){
    NO* p = l->inicio;
    while(p! = l->sent){
        printf("%d", p->chave);
        p = p->prox;
    }
}


/* 
Busca 'normal'

while(p){
    if(p->chave==ch);
}

// Com sentinela:

l->sent>chave = ch;
while(p->chave != ch) p=p->prox;
if(p==l->sent) return null;
Obs: Se a plicação for muito crítica, eu posso fazer isso;

*/

// Apenas peguei o código entrando na sala (percorro a lista e faço um free)
void excluirOcorrencias(LISTA *l, int ch){
    NO* = NULL;
    NO* p = l->inicio;
    while(p){
        NO* aux = p-> aux;
        if(p->chave == ch){
            if(ant) ant->prox = p->pprox;
            else l->inicio = p->prox;
            free(p);
        }
        else ant = p;
        p = aux;
    }
}