#include "poli.h"

void inicializar(poli** lst) {
    poli* novo;
    novo = (poli*)malloc(sizeof(poli));
    novo->cons = 0;
    novo->exp = 0;
    novo->prox = NULL;
}

void inserir(int x, int y, poli** lst) {
    poli* novo;
    poli* p;
    poli* ant;
    novo = (poli*)malloc(1*sizeof(poli));
    novo->cons = x;
    novo->exp = y;
    novo->prox = NULL;

    if(*lst == NULL) 
        *lst = novo;
    else {
        p = *lst;
        while(p != NULL && p->exp != y){
            ant = p;
            p = p->prox;
        }
        if(p == NULL) {
            ant->prox = novo;
        }else{
            ant->cons = ant->cons + x;
        }
    }
}

void eliminarTermo(int x, poli** lst) {
    poli* p;
    poli* ant;

    p = *lst;
    int cont = 0;
    while(p != NULL && p->exp != x) {
        cont++;
        ant = p;
        p = p->prox;
    }
    if(p == NULL)
        printf("Valor nao encontrado\n");
    else if(cont == 0){
        ant = *lst;
        *lst = (*lst)->prox;
        free(ant);
    }else {
        ant->prox = p->prox;
        free(p);
    }
}

void reinicializar(poli** lst) {
    poli* p;
    while(*lst != NULL) {
        p = *lst;
        *lst = (*lst)->prox;
        free(p);
    }
    inicializar(lst);
}

double calcularPoli(int x, poli* lst) {
    poli* p;
    double resultado = 0;
    double pot;

    for(p = lst; p != NULL; p = p->prox) {
        pot = 0;
        pot = pow(x, p->exp);
        resultado += pot*p->cons;
    }

    return resultado;
}

void imprimir(poli* lst) {
    poli* p;
    printf("P(x) = ");
    for(p = lst; p != NULL; p = p->prox) {
        if(p->cons > 0) {
            if(p->exp == 0)
                printf("+%d", p->cons);
            else
                printf("+%dX^%d", p->cons, p->exp);
        }else {
            if(p->exp == 0)
                printf("%d", p->cons);
            else    
                printf("%dX^%d", p->cons, p->exp);
        }
    }   
    printf("\n");
}