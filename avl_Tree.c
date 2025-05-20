#include <stdio.h>
#include <stdlib.h>
#include "avl_Tree.h"

TArvore *raiz = NULL;

/**
 * Percorre e printa a árvore no sentido de pré-ordem
 * @param TArvore *no "Nó raiz do qual a função vai iniciar a percorrer, geralmente a raiz"
 * @return void
 */
void printPreOrdem(TArvore * no) {
    if (no == NULL) return;
    printf("%p %d ", no, no->dado);
    printPreOrdem(no->esq);
    printPreOrdem(no->dir);
}

/**
 * Percorre e printa a árvore no sentido de ordem
 * @param TArvore *no "Nó raiz do qual a função vai iniciar a percorrer, geralmente a raiz"
 * @return void
 */
void printOrdem(TArvore * no) {
    if (no == NULL) return;
    printOrdem(no->esq);
    printf("%p %d ", (void *)no, no->dado);
    printOrdem(no->dir);
}

/**
 * Percorre e printa a árvore no sentido de pós-ordem
 * @param TArvore *no "Nó raiz do qual a função vai iniciar a percorrer, geralmente a raiz"
 * @return void
 */
void printPosOrdem(TArvore * no) {
    if (no == NULL) return;
    printPosOrdem(no->esq);
    printPosOrdem(no->dir);
    printf("%p %d ", (void *)no, no->dado);
}

/**
 * Atualiza as informações de altura de toda a árvore
 * @param TArvore *raiz "Raiz da árvore"
 * @return void
 */
void atualizarAltura(TArvore * raiz) {
    if (raiz == NULL) return;
    atualizarAltura(raiz->esq);
    atualizarAltura(raiz->dir);
    int alturaEsq = raiz->esq ? raiz->esq->altura : 0; // verifica se o nó esquerdo é nulo
    int alturaDir = raiz->dir ? raiz->dir->altura : 0; // verifica se o nó direito é nulo
    raiz->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1; // atualiza a altura do nó
}

int fatorBalanceamento(TArvore * no) {
    int alturaEsq = no->esq ? no->esq->altura : -1;
    int alturaDir = no->dir ? no->dir->altura : -1;

    if (no == NULL) {
        return 0; 
    }
    return no->esq->altura - no->dir->altura; 
}

void imprimirFatorBalanceamento(TArvore *no) {
    int fb = fatorBalanceamento(no);
    printf("Fator de balanceamento da raiz: %d\n", fb);
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

TArvore * rotacaoDireita(TArvore * no) {
    TArvore * nova_raiz = no->esq;
    TArvore * temp = nova_raiz->dir;

    nova_raiz->dir = no;
    no->esq = temp;

    atualizarAltura(no);
    atualizarAltura(nova_raiz);

    return nova_raiz;
}

TArvore * rotacaoEsquerda(TArvore * no) {
    TArvore * nova_raiz = no->dir;
    TArvore * temp = nova_raiz->esq;

    nova_raiz->esq = no;
    no->dir = temp;

    atualizarAltura(no);
    atualizarAltura(nova_raiz);

    return nova_raiz;
}

TArvore * rotacaoEsquerdaDireita(TArvore * no) {
    no->esq = rotacaoEsquerda(no->esq);
    return rotacaoDireita(no);
}

TArvore * rotacaoDireitaEsquerda(TArvore * no) {
    no->dir = rotacaoDireita(no->dir);
    return rotacaoEsquerda(no);
}

TArvore* inserirAVL(TArvore * no, int dado) {
    
    if (no == NULL) {
        TArvore* novo = malloc(sizeof(TArvore));
        novo->dado = dado;
        novo->esq = novo->dir = NULL;
        novo->altura = 1;
        return novo;
    }

    if (dado < no->dado) {
        no->esq = inserirAVL(no->esq, dado);
    } else if (dado > no->dado) {
        no->dir = inserirAVL(no->dir, dado);
    } else {
        printf("dado duplicado nao permitido.\n");
        return no;
    }

    atualizarAltura(no);

    int fb = fatorBalanceamento(no);

    // Caso Esquerda-Esquerda
    if (fb > 1 && dado < no->esq->dado)
        return rotacaoDireita(no);

    // Caso Direita-Direita
    if (fb < -1 && dado > no->dir->dado)
        return rotacaoEsquerda(no);

    // Caso Esquerda-Direita
    if (fb > 1 && dado > no->esq->dado)
        return rotacaoEsquerdaDireita(no);

    // Caso Direita-Esquerda
    if (fb < -1 && dado < no->dir->dado)
        return rotacaoDireitaEsquerda(no);

    return no;
}

