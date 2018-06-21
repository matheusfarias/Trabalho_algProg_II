#include "tad_iii.h"

int main() {
    int num;
    celula* lista = NULL;

    scanf("%d", &num);
    while(num != 0) {
        insere(num, &lista);
        scanf("%d", &num);
    }

    imprimir(lista);

    return 0;
}