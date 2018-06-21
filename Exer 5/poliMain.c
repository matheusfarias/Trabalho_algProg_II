#include "poli.h"

int main() {
    int x;
    int y;

    double resultado = 0;

    int op;

    poli* polinomio = NULL;
    
    do{
        printf("1 - inserir\n");
        printf("2 - imprimir\n");
        printf("3 - reinicializar\n");
        printf("4 - Eliminar Termo\n");
        printf("5 - Calcular Polinomio\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            scanf("%d", &y);
            inserir(x, y, &polinomio);
        }else if(op == 2){
            imprimir(polinomio);
        }else if(op == 3) {
            reinicializar(&polinomio);
        }else if(op == 4) {
            scanf("%d", &x);
            eliminarTermo(x, &polinomio);
        }else if(op == 5) {
            scanf("%d", &x);
            resultado = calcularPoli(x, polinomio);
            printf("%.1f\n", resultado);
        }
    }while(op != 0);

}