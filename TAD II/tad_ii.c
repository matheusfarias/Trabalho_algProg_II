#include "tad_ii.h"

int verificaVazio(celula* lst) {
    if (lst == NULL)
        return 0;
    else
        return 1;
}

void inserirInicio(int x, celula** lst) {
    celula* novo;
    novo = (celula*)malloc(sizeof(celula));
    novo->chave = x;
    novo->prox = *lst;
    if(*lst == NULL) {
        novo->prox = novo;
        *lst = novo;
    }else {
        celula* p;
        celula* ant;
        p = *lst;

        do {
            ant = p;
            p = p->prox;
        }while(p != *lst);

        novo->prox = *lst;
        *lst = novo;
        ant->prox = novo;
    }
}

void inserirFinal(int x, celula** lst) {
     celula* novo;
    novo = (celula*)malloc(sizeof(celula));
    novo->chave = x;

    if(*lst == NULL) {
        novo->prox = novo;
        *lst = novo;
    }else {
        celula* p;
        celula* ant;

        p = *lst;
        do {
            ant = p;
            p = p->prox;
        }while(p != *lst);

        ant->prox = novo;
        novo->prox = *lst;
    }
}

void removerInicio(celula** lst) {
    if(*lst == NULL) 
        printf("Lista vazia");
    else {
        celula* p;
        celula* ant;

        p = *lst;
        do {
            ant = p;
            p = p->prox;
        }while(p != *lst);

        p = *lst;
        *lst = (*lst)->prox;
        ant->prox = *lst;
        free(p);
    }
}

void removerElemento(int x, celula** lst) {
    if(*lst == NULL)
        printf("lista vazia");
    else{
        if((*lst)->chave == x) 
            removerInicio(lst);
        else{
            celula* p;
            celula* ant;
            p = *lst;
            do{
                ant = p;
                p = p->prox;
            }while(p != *lst && p->chave != x);
            
            if(p == *lst){
                printf("chave nao encontrada");
            }else{
                if(p->prox == *lst) {
                    ant->prox = *lst;
                    free(p);
                }else {
                    ant->prox = p->prox;
                    free(p);
                }
            }
        }
    }
}


int tamanhoLista(celula* lst) {
    celula* p;
    int cont = 0;

    p = lst;
    do {
        cont++;
        p = p->prox;
    }while(p != lst);

    return cont;
}

int maior(celula* lst) {
    celula* p;
    int maior;
    maior = (lst)->chave;

    p = lst;
    do {
        if(p->chave > maior)
            maior = p->chave;
        p = p->prox;
    }while(p != lst);

    return maior;

}

celula* concatenar(celula* lst1, celula* lst2) {
    celula* lst3 = NULL;
    celula* p;

    p = lst1;
    do {
        inserirFinal(p->chave, &lst3);
        p = p->prox;
    }while(p != lst1);

    p = lst2;
    do {
        inserirFinal(p->chave, &lst3);
        p = p->prox;
    }while(p != lst2);

    return lst3;
}

void imprimir(celula* lst) {
    celula* p;
    p = lst;
    do {
        printf("%d ", p->chave);
        p = p->prox;
    }while(p != lst);
    printf("\n");
}