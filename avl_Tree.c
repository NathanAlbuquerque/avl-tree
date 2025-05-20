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

int contarAltura(TArvore *no) {
    if (no == NULL)
        return 0;

    int alturaEsq = contarAltura(no->esq);
    int alturaDir = contarAltura(no->dir);
    int maior;                                //quero que retorne 1, 2 ou 3 para tomar a ação da rotação

    if (alturaEsq > alturaDir) {
        maior = alturaEsq;
    } else {
        maior = alturaDir;
    }

    return maior + 1; // 
}

int alturaNo(TArvore *no) {   // definindo a altura do nó
if (no == NULL) {
        return -1;       // verificar se o nó é nulo
    }
return no->altura;   // se o nó não for nulo retorna altura dele
}

void atualizarAltura(TArvore *no) {
    if (no == NULL) return;
    atualizarAltura(no->esq);
    atualizarAltura(no->dir);
    int alturaEsq = no->esq ? no->esq->altura : 0; // verifica se o nó esquerdo é nulo
    int alturaDir = no->dir ? no->dir->altura : 0; // verifica se o nó direito é nulo
    no->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1; // atualiza a altura do nó
}


void imprimirAltura() {
    int alturaEsquerda = contarAltura(raiz->esq);
    int alturaDireita = contarAltura(raiz->dir);
    int alturaTotal = contarAltura(raiz);

    // Atualiza o campo altura do nó raiz
    if (raiz != NULL)
        raiz->altura = alturaTotal;

    printf("\n\nAltura do no raiz: %d\n", raiz ? raiz->altura : -1);
    printf("Altura da subArvore esquerda: %d\n", alturaEsquerda);
    printf("Altura da subArvore direita: %d\n", alturaDireita);
    printf("Altura total da AVL: %d\n\n", alturaTotal);
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
