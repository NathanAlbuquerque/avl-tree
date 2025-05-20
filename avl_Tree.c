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
    // printf("%d ", no->dado); modo mais simples
    ordem(no->dir);
}

void posOrdem(TArvore * no){
    if (no == NULL)
        return;

    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->dado);
}

int contarAltura(TArvore * no) {
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

int alturaNo(TArvore * no) {   // definindo a altura do nó
    if (no == NULL) {
            return -1;       // verificar se o nó é nulo
        }
    return no->altura;   // se o nó não for nulo retorna altura dele
}

void atualizarAltura(TArvore * no) {
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

    printf("\nAltura do no raiz: %d\n", raiz ? raiz->altura : -1);
    printf("Altura da subArvore esquerda: %d\n", alturaEsquerda);
    printf("Altura da subArvore direita: %d\n", alturaDireita);
    printf("Altura total da AVL: %d\n\n", alturaTotal);
}

int fatorBalanceamento(TArvore * no) {
    if (no == NULL) {
        return 0; 
    }
    return alturaNo(no->esq) - alturaNo(no->dir); 
}

void imprimirFatorBalanceamento(TArvore * no) {
    int fb = fatorBalanceamento(no);
    printf("Fator de balanceamento da raiz: %d\n\n", fb);
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

int fatorBalanceamento(TArvore *no) {
    if (no == NULL) {
        return 0; 
    }
    return alturaNo(no->esq) - alturaNo(no->dir); 
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
        printf("dado duplicado não permitido.\n");
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

int main() {
    int leitura;

    while (1) {
        printf("Digite um leitura (0 para parar): ");
        scanf("%d", &leitura);
        if (leitura == 0)
            break;

        raiz = inserirAVL(raiz, leitura);
        imprimirAltura();
        imprimirFatorBalanceamento(raiz);
        printf("imprimindo: ");
        ordem(raiz);
        printf("\n\n");
    }
    return 0;
}
