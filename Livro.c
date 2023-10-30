#include "Livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inicializa(){
    int i;
    for (i = 0; i<MAX; i++){
        v[i] = NULL;
    }
}

void ler_dados(int i){
    while(1) {
        if (v[i] == NULL) {
            v[i] = (p_livro) malloc(sizeof(livro));
            fflush(stdin);
            printf("Digite o titulo do livro: \n");
            gets(v[i]->titulo);
            fflush(stdin);

            if (apenas_letras(v[i]->titulo) == 0) {
                printf("Erro 404 - Título do livro contém dígitos ou outros caracteres não-alfabéticos \n");
                printf("Digite novamente\n\n");
                free(v[i]);
                v[i] = NULL;
                continue;
            }
            printf("Digite o Autor: \n");
            gets(v[i]->autor);
            fflush(stdin);

            if (apenas_letras(v[i]->autor) == 0) {
                printf("Erro 405 - Autor do livro contém dígitos ou outros caracteres não-alfabéticos \n");
                printf("Digite novamente\n\n");
                free(v[i]);
                v[i] = NULL;
                continue;
            }

            printf("Digite o ISBN: \n");
            gets(v[i]->isbn);
            fflush(stdin);
            if (strlen(v[i]->isbn) > 13){
                printf("Tamanho do ISBN excedido!\n");
                printf("Digite novamente\n\n");
                free(v[i]);
                v[i] = NULL;
                continue;
            }

            printf("Digite o valor: \n");
            fflush(stdin);
            scanf("%f", &v[i]->preco);

            printf("Digite a quantidade em estoque: \n");
            scanf("%d", &v[i]->estoque);

            break;
        }
    }
}

void imprimir_unico(int i){
    if (v[i] != NULL){
        printf("Nome:        %s \n", v[i]->titulo);
        printf("Autor:       %s \n", v[i]->autor);
        printf("ISBN:        %s \n", v[i]->isbn);
        printf("Preco: R$    %.2f \n", v[i]->preco);
        printf("Qtd Estoque: %d \n", v[i]->estoque);
        printf("\n");
    }
}

void imprimir_tudo(){
    int i;
    for (i = 0; i<MAX; i++){
        imprimir_unico(i);
    }
}

void pesquisar(const char *p_buscar){
    int livro_econtrado = 0;

    for (int i = 0; i < MAX; i++) {
        if (v[i] !=NULL && (strcmp(v[i]->titulo, p_buscar) == 0 || strcmp(v[i]->autor, p_buscar) == 0)){
            imprimir_unico(i);
            livro_econtrado = 1;
            }
        }
    if(!livro_econtrado){
        printf("Livro nao encontrado! \n");
    }
}

int apenas_letras(char *p_str){
    for (int i = 0; p_str[i] != '\0'; i++) {
        if (!isalpha(p_str[i]) && !isspace(p_str[i])){
            return 0; // Se encontrar qualquer caractere que não seja uma letra ou espaço, retorna 0
        }
    }
    return 1; // Se percorrer toda a string e não encontrar dígitos, retorna 1
}
