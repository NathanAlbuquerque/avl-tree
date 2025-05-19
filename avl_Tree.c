#include <stdio.h>
#include <stdlib.h>
#include "avl_Tree.h"

TArvore *raiz = NULL; 

void preOrdem(TArvore * no){
    if (no == NULL)
        return;

    printf("%d ",no->dado);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void ordem(TArvore * no){
    if (no == NULL)
        return;

    ordem(no->esq);
    printf("%p %d ", (void *)no, no->dado);
    ordem(no->dir);
}

void posOrdem(TArvore * no){
    if (no == NULL)
        return;

    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->dado);
}

void preencherABB( TArvore * no, int info){
    if (no == NULL)
        return;

    TArvore * novo;

    if (info < no->dado){
        if (no->esq == NULL){
            novo = malloc(sizeof(TArvore));
            novo->dado = info;
            novo->dir = novo->esq = NULL;
            no->esq = novo;
        }else
            preencherABB(no->esq, info);
    }else if (info > no->dado){
        if (no->dir == NULL){
            novo = malloc(sizeof(TArvore));
            novo->dado = info;
            novo->dir = novo->esq = NULL;
            no->dir = novo;
        }else
            preencherABB(no->dir, info);
    }else{
        printf("Não é possível inserir valores duplicados numa árvore binária de busca");
    }
}

TArvore * buscarABB(TArvore * no, int info) {
    if (no == NULL)
        return no;
    
    if (no->dado == info) {
        return no;
    } if (no->dado > info) {
        return buscarABB(no->esq, info);
    } else {
        return buscarABB(no->dir, info);
    }
}

/*
Funções a serem feitas:
Atualizar o campo fb (fator de balanceamento).
Detectar desbalanceamento após inserção.
Fazer as 4 rotações AVL:
Rotação simples à direita (LL)
Rotação simples à esquerda (RR)
Rotação dupla à direita (LR)
Rotação dupla à esquerda (RL)
*/
