#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
    struct SArvore * esq;
    int dado;
    int indice;
    struct SArvore * dir;
}TArvore;

TArvore * raiz;

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
    printf("%p %d ", no, no->dado);
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
    } else if (no->dado > info) {
        buscarABB(no->esq, info);
    } else if (no->dado < info) {
        buscarABB(no->dir, info);
    }
}

int main(int argc, char** argv) {

    int leitura;
    
    raiz = malloc(sizeof(TArvore));
    printf("Informe o valor da raiz: ");
    scanf("%d",&raiz->dado);
    raiz->esq = NULL;
    raiz->dir = NULL;
    //preencherArvore(raiz);

    while (1){
        printf("Informe o valor que será inserido na árvore: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
        preencherABB(raiz, leitura);
    }
    
    ordem(raiz);

    while (1){
        printf("Informe o valor que será procurado na árvore: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
        TArvore * endereco = buscarABB(raiz, leitura);
        if (endereco == NULL) {
            printf("\nEndereço não encontrado.\n\n");
        } else {
            printf("\nEndereço encontrado: %p, Valor: %d\n\n", endereco, endereco->dado);
        }
    }

    return (EXIT_SUCCESS);
}
/*
Alteração
*/