#include <stdlib.h>
#include <stdio.h>

/*
Para evitar a necessidade de definição antecipada do tamanho máximo da estrutura de implementação estática
(i.e., o vetor), podemos tirar proveito dos recursos de alocação dinâmica de memória das linguagens de
programação como C, deixando o gerenciamento de nós livres / ocupados a cargo do ambiente de
programação. Esta técnica constitui à implementação dinâmica de listas ligadas, e requer o uso das funções
disponibilizadas em malloc.h:
*/

#include <malloc.h>

/*
Em uma lista ligada de implementação dinâmica, não há mais uso de vetores. Cada elemento da lista é uma
estrutura do tipo NO, que contém os dados de cada elemento (inclusive a chave) e um ponteiro prox para o
próximo nó da lista. Um nome auxiliar (estrutura) é usado para permitir a auto-referência ao tipo NO que está
sendo definido.
*/

typedef struct estrutura{
    int chave;
    int info;
    struct estrutura *prox; // Uma autoreferência;
} NO;

/*
O tipo LISTA propriamente dito é simplesmente um ponteiro inicio apontando para o primeiro nó da
estrutura (ou para NULL no caso da lista vazia).

O último elemento da lista possui seu ponteiro prox também apontando para NULL. Embora não seja necessário o encapsulamento deste ponteiro em um tipo LISTA
(afinal, uma lista é apenas um ponteiro, que pode ser NULL ou não), esta medida será adotada aqui por
questões de padronização em relação aos tipos LISTA anteriores, e também porque alguns dos próximos
tipos agregarão mais informações a esta definição.
*/

typedef struct {
    NO* inicio; // Estou apontando para o primeiro NO da lista;
} LISTA;

/* A alocação e desalocação de nós é feita dinamicamente pelo próprio compilador C através das primitivas
malloc e free, respectivamente. */

// NO *p = (NO*) malloc(sizeof(NO)); // cria um novo NO em memoria, apontado para o p
// free(p); // a área de memória apontada por p é liberada;

/*
Via de regra, malloc() é usado em rotinas de inserção ou criação de novos nós, enquanto que free() é usado na
exclusão. Rotinas que não criam ou destroem nós dificilmente precisam usar estas funções.
*/

/*A única diferença significativa entre as implementações estática e dinâmica de listas ligadas está no fato de
que a implementação estática “simula” uma lista ligada em vetor, e nos obriga a gerenciar as posições livres e
ocupadas. Isso deixa de ser necessário no caso da alocação dinâmica “real”.*/


// Inicializando:
void inicializarLista(LISTA *l){
    l->inicio = NULL;
}

// Exibição da lista completa
void exibirLista(LISTA* l){
    NO* p = l->inicio;
    printf("Lista: \" ");
    while(p){ // Ou while(p != NULL)
        printf("%d", p->chave);
        p = p->prox;
    }
}

// Retornar o primeiro elemento da lista
NO* retornarPrimeiroElemLista(LISTA l){
    return (l.inicio);
}

// Retornar o último elemento da lista
NO* retornarUltimoElemLista(LISTA l){
    NO* p = l.inicio;
    if (p){
        while(p->prox) p = p->prox;
    }
    return(p);
}

// Retornar o enésimo elemento da lista
NO* enesimoElemLista(LISTA l, int n){
   NO* p = l.inicio;
   int i = 1;
   if(p)
    while((p->prox)&&(i < n))
    {
        p = p->prox;
        i++;
    }
    if(i != n) return(NULL);
    else return(p); 
}

int main(){
    return 0;
}




