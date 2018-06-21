#include <stdio.h>
#include <stdlib.h>

struct cel {
    int chave;
    struct cel* prox;
};

typedef struct cel celula;

int verificaVazio(celula* lst);
void inserirFinal(int x, celula** lst);
void inserirInicio(int x, celula** lst);
void removerInicio(celula** lst);
void removerElemento(int x, celula** lst);
int tamanhoLista(celula* lst);
int maior(celula* lst);
celula* concatenar(celula* lst1, celula* lst2);
void imprimir(celula* lst);