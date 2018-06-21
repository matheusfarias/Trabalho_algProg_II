#include "tad_i.h"

int main() {
    int n;
    celula* lista1 = NULL;
    celula* lista2 = NULL;
    celula* lista3 = NULL;

    scanf("%d", &n);
    while(n != 0) {
        inserir(n, &lista1);
        scanf("%d", &n);
    }

    scanf("%d", &n);
    while(n != 0) {
        inserir(n, &lista2);
        scanf("%d", &n);
    }

    imprimir(lista1);
    imprimir(lista2);
    int a;
    a = verificaIgual(lista1, lista2);
    if(a == 1) {
        printf("eh igual");
    }else{
        printf("eh diferente");
    }

    return 0;
}