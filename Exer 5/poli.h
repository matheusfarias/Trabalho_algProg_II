#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct cel {
    int cons;
    int exp;
    struct cel* prox;
};
typedef struct cel poli;

void inserir(int x, int y, poli** lst);
void inicializar(poli** lst);
void imprimir(poli* lst);
void eliminarTermo(int x, poli** lst);
void reinicializar(poli** lst);
double calcularPoli(int x, poli* lst);