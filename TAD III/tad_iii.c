#include "tad_iii.h"

int verificaVazio(celula* lst) {
    if (lst ==  NULL) 
        return 0;
    else 
        return 1;
}

void insere(int x, celula** lst) {
    celula* novo;

    novo = (celula*)malloc(1*sizeof(celula));
    novo->chave = x;
    novo->prox = NULL;

    if(*lst == NULL) {
        novo->ant = NULL;
        *lst = novo;
    }else {
        celula* p;
        celula* ant;
        p = *lst;
        while(p != NULL && p->chave <= x) {
            ant = p;
            p = p->prox;
        }
            
        if(p != NULL && p->ant == NULL) {
            printf("if\n");
            novo->prox = *lst;
            (*lst)->ant = novo;
            *lst = novo;
        }else if(p != NULL) {
            printf("elseif\n");
            p->ant->prox = novo;
            novo->ant = p->ant;
            novo->prox = p;
            p->ant = novo;
        }else {
            printf("aqui\n");
            ant->prox = novo;
            novo->ant = ant;
        }
    }
}

void remover(int x, celula **lst) {

    celula *p;

    p = *lst;
    while(p!= NULL && p->chave != x)
        p = p->prox;

    if(p == NULL)
        printf("Nao encontrado\n");
    else{
        if(p->ant == NULL)
        {
            *lst = (*lst)->prox;
            if(*lst != NULL)
                (*lst)->ant = NULL;
            free(p);
        }
        else{
            p->ant->prox = p->prox;
            if(p->prox!=NULL)
                p->prox->ant = p->ant;
            free(p);
        }
    }
}

void removeOcorrencias(int x, celula** lst) {
    celula *p;
    int val = 1;
    while(val == 1) {
        p = *lst;
        while(p!= NULL && p->chave != x)
            p = p->prox;

        if(p == NULL) 
            val = 0;
        else{
            if(p->ant == NULL) {
                *lst = (*lst)->prox;
                 if(*lst != NULL)
                     (*lst)->ant = NULL;
                 free(p);
            }else{
                p->ant->prox = p->prox;
                if(p->prox!=NULL)
                    p->prox->ant = p->ant;
                free(p);
            }
        }
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


void imprimir(celula* lst) {
    celula* p;
    for(p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);
    printf("\n");

}