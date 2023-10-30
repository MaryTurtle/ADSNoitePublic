#include <stdio.h>
#include "livro.h"

p_livro v[MAX];
char encontrar_titulo[MAX];

int main() {
    int i = 0;
    int opcao = 0;
    do {
        int p = 0;

        printf("\n\tMenu Principal\n");
        printf("=========================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Imprimir dados de um unico livro\n");
        printf("3. Imprimir todos os dados de livros\n");
        printf("4. Pesquisar livro\n");
        printf("9. Sair do programa\n");
        scanf("%d", &opcao);

    switch(opcao){
        case 1:
            ler_dados(i);
            printf("Tecle qualquer tecla para continuar \n");
            i++;
            getchar();
            break;
        case 2:
            printf("Digite a posicao a imprimir: \n");
            scanf("%d", &p);
            imprimir_unico(p);
            getchar();
            break;
        case 3:
            imprimir_tudo();
            getchar();
            break;
        case 4:
            fflush(stdin);
            printf("Digite o titulo ou o autor do livro: \n");
            gets(encontrar_titulo);
            pesquisar(encontrar_titulo);
            getchar();
            break;
        case 9:
            printf("Fim\n");
            break;
        default:
            printf("Opcao invalida \n");

        }

    }while(opcao !=9);

}
