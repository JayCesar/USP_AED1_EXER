#include <stdio.h>
/*
#include <stdlib.h> Essa biblio permite ussar essas 4 funções
malloc, calloc, realloc, free
E é comum utilizarmos o operador sizeof (foco de da aula)
*/

int main(void){

    int x;
    double y;

    // Para calcular o tamanho de um tipo de dado:
    // sizeof() retorna o tamanho em bytes daquele tipo de dados

    printf("%li\n", sizeof(x)); // Imprime 4 ( os 4 bytes)
    printf("%li\n", sizeof(y)); // Imprime 8 ( os 8 bytes)

    // Para calcular o tamnho de um vetor:
    int vetor[10];

    printf("%li\n", sizeof(vetor));

    // Testando com uma struct
    struct x{
        int a;
        int b;
        int c;
    };

    struct x estrutura;

    printf("%li\n", sizeof(estrutura));

    return 0;
}