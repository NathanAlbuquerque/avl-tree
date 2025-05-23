#include <stdio.h>
#include <stdlib.h>
#include "avl_Tree.h"

extern TArvore * raiz;

void menu(){
    printf("\n\n========= Menu =======\n\n");
    printf("\n VERSÃO 2.0 \n");
    printf("[a] - Inserir No\n");
    printf("[b] - Buscar No\n");
    printf("[c] - Imprimir Grafo\n");
    printf("[d] - Converter GRAFO para JSON\n");
    printf("[e] - Sair\n");
    printf("\n=======================\n\n");
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
                printf("\n\n========= INSERIR NO =======\n\n");
                printf("Para sair do loop, digite 0.\n");

                if (raiz == NULL) {
                    raiz = inserirAVL(NULL, lerInteiro("Informe o valor da raiz: "));
                    printf("Arvore criada com sucesso!\n\n");
                }

                while (1){
                    printf("Informe o valor que sera inserido na arvore: ");
                    leitura = lerInteiro(": ");
                    if (leitura == 0)
                        break;

                    raiz = inserirAVL(raiz, leitura);
                    atualizarAltura(raiz);

                    // mostra as alturas logo após inserir
                    printf("\n\nAltura do no raiz: %d\n", raiz ? alturaNo(raiz) : -1);
                    printf("Altura da subArvore esquerda: %d\n", alturaNo(raiz->esq));
                    printf("Altura da subArvore direita: %d\n", alturaNo(raiz->dir));

                    printf("Fator de balanceamento da raiz: %d\n", fatorBalanceamento(raiz));
                }

                printf("\n\nArvore preenchida com sucesso!\n\n");
                break;
            case 'b':
                printf("\n\n========= BUSCAR NO =======\n\n");
                while (1){
                        printf("\nInforme o valor que sera procurado na árvore: ");
                        leitura = lerInteiro(": ");
                        if (leitura == 0)
                        break; 
                        TArvore * endereco = buscarABB(raiz, leitura);
                        if (endereco == NULL) {
                            printf("\nEndereço nao encontrado.\n\n");
                        } else {
                            printf("\nEndereço encontrado: %p, Valor: %d\n\n", endereco, endereco->dado);
                        }
                    };
                break;
            case 'c': 
                        printf("\n\n========= MENU DE IMPRESSAO =======\n\n");
                        printf("\nInforme a ordem de impressao: ");
                        printf("\n[1] Pre-Ordem \n[2] ORDEM \n[3] Pos-Ordem \n[4] Todos");
                        printf("\n\n==================================\n\n");

                        int imprimir = lerInteiro(": ");

                        switch (imprimir)
                            {
                            case 1:
                                printf("\n\n========= PRE-ORDEM =======\n\n");
                                printPreOrdem(raiz);
                                printf("\n");
                                break;
                            case 2:
                                printf("\n\n========= ORDEM =======\n\n");
                                printOrdem(raiz);
                                printf("\n");
                                break;
                            case 3: 
                                printf("\n\n========= POS-ORDEM =======\n\n");
                                printPosOrdem(raiz);
                                printf("\n");
                                break;
                            case 4:
                                printf("\n\n========= PRE-ORDEM =======\n\n");
                                printPreOrdem(raiz);
                                printf("\n");
                                printf("\n\n========= ORDEM =======\n\n");
                                printOrdem(raiz);
                                printf("\n");
                                printf("\n\n========= POS-ORDEM =======\n\n");
                                printPosOrdem(raiz);
                                printf("\n");
                                break;
                            default:
                                break;
                            }
                        break;
            case 'd':
                exportar_arvore_json("avl.json", raiz);
                printf("\nÁrvore exportada com sucesso para 'avl.json'.\n");
                break;
            case 'e': break;
        default:
            printf("\nValor invalido, por favor insira uma letra minuscula de (a) a (d): ");
            break;
        }
}

void page(){
    char escolha;
    int loop = 1;
    int voltar;
    int validacao;
    menu();

      do{
        printf("\nDigite a opcao desejada: ");
        scanf(" %c", &escolha);
        while (getchar() != '\n'); // limpa o buffer de entrada
        validacao = (escolha >= 'a' && escolha <= 'e');
        if (escolha == 'e'){
            printf("\nFinalizando o programa...Obrigado pela atencao!\n");
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

int main(){
    page();
    return (EXIT_SUCCESS);
}