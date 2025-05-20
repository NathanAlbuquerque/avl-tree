#include <stdio.h>
#include <stdlib.h>
#include "avl_Tree.h" //<-- nao entendi pra que isso

typedef struct SArvore {
    struct SArvore *esq;
    int dado;
    int altura;
    struct SArvore *dir;
} TArvore;

// TArvore * raiz = NULL; <--deve ser desnecessário já que tem o de baixo:

extern TArvore * raiz;

void menu(){
    printf("\n\n========= Menu =======\n\n");
    printf("[a] - Inserir No\n");
    printf("[b] - Buscar No\n");
    printf("[c] - Deletar No\n");
    printf("[d] - Imprimir Grafo\n");
    printf("[e] - Sair\n");
}

void limparTela() { 
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} 

int lerInteiro(char *mensagem){
    int valorInserido;
    char c;
    printf("%s", mensagem);
    while (1) {
        // Tenta ler um inteiro
        if (scanf("%d", &valorInserido) == 1) {
            // Verifica se há caracteres adicionais após o número
            c = getchar();
            if (c == '\n' || c == EOF) {
                return valorInserido;
            } else {
                printf("Entrada Invalida. Digite somente valores inteiros: ");
                // Limpa o buffer até o fim da linha
                while ((c = getchar()) != '\n' && c != EOF);
                printf("%s", mensagem);
            }
        } else {
            // Limpa o buffer até o fim da linha se a entrada não foi um número inteiro
            printf("Entrada Invalida. Digite somente valores inteiros: ");
            while ((c = getchar()) != '\n' && c != EOF);
            printf("%s", mensagem);
        }
    }
}

void lerAlternativa(char escolha){
    
    switch (escolha) {
            int leitura;
            case 'a': 

                if (raiz == NULL){
                    raiz = malloc(sizeof(TArvore));
                    printf("Informe o valor da raiz: ");
                    scanf("%d",&raiz->dado);
                    raiz->esq = NULL;
                    raiz->dir = NULL;
                }

                while (1){
                    printf("Informe o valor que sera inserido na arvore: ");
                    scanf("%d",&leitura);
                    if (leitura == 0)
                        break;
                    preencherABB(raiz, leitura);      
                    atualizarAltura(raiz);  
                    imprimirAltura(); // mostra as alturas logo após inserir
                    fatorBalanceamento(raiz);
                    imprimirFatorBalanceamento(raiz);
                }
                break;
            case 'b':
                while (1){
                        printf("\nInforme o valor que sera procurado na árvore: ");
                        scanf("%d",&leitura);
                        if (leitura == 0)
                            break;
                        TArvore * endereco = buscarABB(raiz, leitura);
                        if (endereco == NULL) {
                            printf("\nEndereço nao encontrado.\n\n");
                        } else {
                            printf("\nEndereço encontrado: %p, Valor: %d\n\n", (void*)endereco, endereco->dado);
                        }
                    };
                break;
            case 'c': ;break;
            case 'd': break;
            case 'e': break;
        default:
            printf("\nValor invalido, por favor insira uma letra minuscula de (a) a (d): ");
            break;
        }
}

void page(){
    char escolha;
    int loop=1;
    int voltar;
    int validacao;
    menu();

      do{
        printf("\nDigite a opcao desejada: ");
        scanf(" %c", &escolha);
        while (getchar() != '\n'); // limpa o buffer de entrada
        validacao = (escolha >= 'a' && escolha <= 'd');
        if (escolha == 'd'){
            loop = 0;
            break;
        }
        if (validacao){ 
            do{
                    limparTela();
                    lerAlternativa(escolha);
                    int voltarValido = 1;
                    printf("\n\nDeseja voltar ao Menu? (1)-Sim/ (0)-Nao. /\n"
                    " Para continuar, aperte (2) \n: ");
                    do{
                        voltar = lerInteiro("");
                        if (voltar == 1 || voltar == 0 || voltar == 2 ){
                            voltarValido = 0; 
                        } else{
                            printf("\nDigito inválido: ");
                            voltarValido = 1; 
                        }
                    }while(voltarValido);

                    if (voltar == 2){
                        limparTela();
                    }else if (voltar == 1){
                        limparTela();
                        menu();
                        break;
                    }else if (voltar==0){
                        limparTela();
                        printf("\nFinalizando o programa...Obrigado pela atencao!");
                        loop = 0; 
                        break;
                    }
                }while(voltar==2);

            }else{
                printf("\nValor invalido, por favor insira uma letra minuscula de (a) a (d): ");
            }
        }while(loop);
}



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
    printf("%d ", no->dado);
    ordem(no->dir);
}

void posOrdem(TArvore * no){
    if (no == NULL)
        return;

    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->dado);
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
        ordem(raiz);
        printf("\n\n");
    }
    return 0;
}