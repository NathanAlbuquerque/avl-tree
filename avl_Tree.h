#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct SArvore{
    struct SArvore *esq;
    int dado;
    int altura;
    struct SArvore *dir;
} TArvore;

extern TArvore *raiz;

void preOrdem(TArvore *no);
void ordem(TArvore *no);
void posOrdem(TArvore *no);
void preencherABB(TArvore *no, int info);
TArvore *buscarABB(TArvore *no, int info);
int contarAltura(TArvore *no);
int alturaNo(TArvore *no);
void atualizarAltura(TArvore *no);
void imprimirAltura();
#endif