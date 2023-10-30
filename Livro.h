#define MAX 100

typedef struct Livro{
    char titulo[MAX];
    char autor[50];
    char isbn[13];
    float preco;
    int estoque;

}livro;
typedef livro *p_livro;

extern p_livro v[MAX];


//FUNCOES

void inicializa();

void ler_dados(int i);

void imprimir_unico(int i);

void imprimir_tudo();

void pesquisar(const char *p_buscar);

int apenas_letras(char *p_str);

