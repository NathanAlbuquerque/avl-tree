#include <stdio.h>
#include <stdlib.h>
#include "avl_Tree.h"

extern TArvore *raiz;

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
                    imprimirAltura();              // mostra as alturas logo após inserir
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

int main(){
    page();
    return (EXIT_SUCCESS);
}