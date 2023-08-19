#include <stdio.h>

void verificar(int *numero){
    
    *numero = *numero + 5;

}

int main(){
    int y = 2;
    int *x = &y;

    printf("%d\n", x);

    verificar(x);
    
    printf("%d\n", *x);
    
    return 0;
}