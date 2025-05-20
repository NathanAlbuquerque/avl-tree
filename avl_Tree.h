#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct SArvore{
    struct SArvore *esq;
    int dado;
    int altura;
    struct SArvore *dir;
} TArvore;

extern TArvore *raiz;

void printPreOrdem(TArvore *no);
void printOrdem(TArvore *no);
void printPosOrdem(TArvore *no);
void preencherABB(TArvore *no, int info);
TArvore *buscarABB(TArvore *no, int info);
void atualizarAltura(TArvore *no);
void imprimirAltura();
int fatorBalanceamento(TArvore *no);
void imprimirFatorBalanceamento(TArvore *no);
TArvore * buscarABB(TArvore * no, int info);
TArvore * rotacaoDireita(TArvore * no);
TArvore * rotacaoEsquerdaDireita(TArvore * no);
TArvore * rotacaoDireitaEsquerda(TArvore * no);
TArvore* inserirAVL(TArvore * no, int dado);
#endif