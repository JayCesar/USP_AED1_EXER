#include <stdio.h>
#include <stdlib.h>
// stdlib.h> Ppossui funções envolvendo 
// alocação de memória, controle de processos, conversões e outras.
#include <string.h> 
/* Ao incluir esse arquivo de cabeçalho em seu programa (<string.h>), você ganha acesso
 a várias funções úteis para trabalhar com strings, como: strcpy por exemplo*/
#include <locale.h>

typedef struct {
    int busId;
    char destination[300];
    char passangerName[300];
    float totalPrice;
} busTicket;

busTicket travelTicket;

void inicializar(){
    travelTicket.busId = 0;
    strcpy(travelTicket.destination, "NULL");
    strcpy(travelTicket.passangerName, "NULL");
    travelTicket.totalPrice - 0.0;
}

void imprimir(busTicket ticket){
    printf(" \n O numero (id) do onibus e: %d ", ticket.busId);
    printf(" \n O destino da viagem e: %s", ticket.destination);
    printf(" \n O nome do passageiro e: %s ", ticket.passangerName);
    printf(" \n O preco do ticket e: %.2f ", ticket.totalPrice);
    printf(" \n \n");
};

void comprarPassagem(busTicket *ticket){
    int ticketAmount = 0;
    double totalPrice = 0;
    printf("\n Digite o codigo(id) do onibus: ");
    scanf("%d", &ticket->busId);
    printf(" \n Digite o nome do destino: ");
    scanf("%s", &ticket->destination);
    printf(" \n Digite o nome passageiro: ");
    scanf("%s", &ticket->passangerName);
    printf(" O valor da passagem e R$ 400.00 p/ pessoa (adulto)");
    printf(" \n Digite quantas passagens que desja comprar: ");
    scanf("%d*c", &ticketAmount);
    ticket->totalPrice = ticketAmount * 400.0;
}

void menu(){
    int opcao;
    do 
    {
        printf("\n Opcoes: ");
        printf(" \n 1. Inicializar a Estrutura");
        printf(" \n 2. Imprimir");
        printf(" \n 3. Comprar passagem");
        printf(" \n 4. Para sair. \n");
        printf(" \n Digite a opcao desejada: ");
        scanf("%d%*c", &opcao);
        switch(opcao)
        {
            case 1:
                inicializar();
            break;
            case 2:
                imprimir(travelTicket);
            break;
            case 3:
                comprarPassagem(&travelTicket);
            break;
            default:
                printf(" \n Opcao nao existente.");
            break;
        }
    } 
    while (opcao != 4);
}


int main(){
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}
