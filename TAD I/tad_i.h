#ifndef __TAD_I_
#define __TAD_I_

#include <stdio.h>
#include <stdlib.h>

struct cel{
    int chave;
    struct cel* prox;
};
typedef struct cel celula;

int verificaVazio(celula* lst);
void inserir(int x, celula** lst);
void remover(int x, celula** lst);
void removerPos(int pos, celula** lst);
int tamanhoLista(celula* lst);
int mediaNumeros(celula* lst);
int verificaIgual(celula* lst1, celula* lst2);
celula* intercalar(celula* lst1, celula* lst2);
void imprimir(celula* lst);

#endif
