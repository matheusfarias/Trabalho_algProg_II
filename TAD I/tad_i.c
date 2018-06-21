#include "tad_i.h"

int verificaVazio(celula* lst){
    if(lst == NULL)
        return 1;
    else    
        return 0;
}

void inserir(int x, celula** lst) {
    celula* novo;
    
    novo = (celula*)malloc(1*sizeof(celula));
    novo->chave = x;
    novo->prox = NULL;
    
    if(*lst == NULL) 
        *lst = novo;
    else{
        celula* p;
        celula* ant;

        p = *lst;
        ant = NULL;
        int cont = 0;

        while(p != NULL && p->chave <= x) {
            cont++;
            ant = p;
            p = p->prox;
        }
        if(cont == 0) {
            novo->prox = *lst;
            *lst = novo;
        }else if(p != NULL) {
            ant->prox = novo;
            novo->prox = p;
        }else{
            ant->prox = novo;
        }
            
    } 
}

void remover(int x, celula** lst) {
    celula* p;
    celula* ant;

    p = *lst;
    int cont = 0;
    while(p != NULL && p->chave != x) {
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

void removerPos(int pos, celula** lst) {
    celula* p;
    celula* ant;
    int cont = 0;

    p = *lst;
    while(p != NULL & (cont+1) < pos) {
        ant = p;
        p = p->prox;
        cont++;
    }
    if(p == NULL)
        printf("Posicao invalida");
    else if(cont == 0) {
        ant = *lst;
        *lst = (*lst)->prox;
    }else{
        ant->prox = p->prox;
        free(p);
    }   
}

int tamanhoLista(celula* lst) {
    celula* p;
    int cont = 0;

    p = lst;
    while(p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}

int mediaNumeros(celula* lst) {
    celula* p;
    int soma = 0;
    int dv;

    dv = tamanhoLista(lst);
    p = lst;
    while(p != NULL) {
        soma += p->chave;
        p = p->prox;
    }
    return soma/dv;
}

int verificaIgual(celula* lst1, celula* lst2) {
    if(tamanhoLista(lst1) != tamanhoLista(lst2)) 
        return 0;
    else{
        celula* p1;
        celula* p2;

        p1 = lst1;
        p2 = lst2;
        while(p1 != NULL && p1->chave == p2->chave) {
            p1 = p1->prox;
            p2 = p2->prox;
        } 

        if(p1 == NULL)
            return 1;
        else{
            return 0;
        }
    }
}

celula* intercalar(celula* lst1, celula* lst2) {
    celula* novaLista = NULL;
    celula* p1;
    celula* p2;

    p1 = lst1;
    p2 = lst2;
    while(p1 != NULL && p2 != NULL) {
        if(p1->chave < p2->chave) {
            inserir(p1->chave, &novaLista);
            p1 = p1->prox;
        }else {
            inserir(p2->chave, &novaLista);
            p2 = p2->prox;
        }
    }
    if(p1 != NULL) {
        while(p1 != NULL) {
            inserir(p1->chave, &novaLista);
            p1 = p1->prox;
        }
    }
    if(p2 != NULL) {
        while(p2 != NULL) {
            inserir(p2->chave, &novaLista);
            p2 = p2->prox;
        }
    }

    return novaLista;
}


void imprimir(celula* lst) {
    celula* p;
    for(p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);
    printf("\n");

}
