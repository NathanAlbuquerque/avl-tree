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
void atualizarAltura(TArvore *no);
int fatorBalanceamento(TArvore *no);
TArvore * buscarABB(TArvore * no, int info);
TArvore * rotacaoDireita(TArvore * no);
TArvore * rotacaoEsquerda(TArvore * no);
TArvore * rotacaoEsquerdaDireita(TArvore * no);
TArvore * rotacaoDireitaEsquerda(TArvore * no);
TArvore* inserirAVL(TArvore * no, int dado);
void salvar_json(FILE *arquivo, TArvore *no);
void exportar_arvore_json(const char *nome_arquivo, TArvore *raiz);
#endif