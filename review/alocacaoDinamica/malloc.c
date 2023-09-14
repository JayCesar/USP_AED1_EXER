#include <stdio.h>
#include <stdlib.h>

int main(void){
    // O sistema operacional, antes do tempo execução, já aloca o espaço para as variáveis
    // Mas existirão programas onde não saberemos antes do tempo execução quanto de memórai precisamos alocar para o program
    // E é aqui que entrar a alocação dinâmica

    // Malloc = Memory Alocation
    int *p = (int *) malloc(sizeof(int)); // Preciso fazer o castng pra o tipo ponteiro, pois retoran um void
    // Ela irá retornar o ponteiro uqe aponta para o endereço do bloco que foi alocado com a função malloc;
    // Depois e digo o tamnho dessa memória que eu quero alocar;
    // Eu poderia fazer isso também: int *p = malloc(10 * sizeof(int));
    // Ou seja, um possível vetor de tamanho 10;
    // De novo: o malloc retorna um void;

    // Importante: quando eu aloco um espaço na memória, se tiver lixo lá, o malloc não irá remover!

    // Se a função não alocar memória, será retornado valor NULL;

    if ( p == NULL ){
        printf("Malloc nao funcionou");
    }

    // size_t é um tipo de valor inteiro sempre positivo


    return 0;
}
