#include <stdio.h>
#include <stdlib.h>

struct cel {
    int chave;
    struct cel* ant;
    struct cel* prox;
};

typedef struct cel celula;

int verificaVazio(celula* lst);
void insere(int x, celula** lst);
void remover(int x, celula** lst);
void removeOcorrencias(int x, celula** lst);
int tamanhoLista(celula* lst);
int verificaIgual(celula* lst1, celula* lst2);
void imprimir(celula* lst);
