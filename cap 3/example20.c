// ETAPA 1: Inclusão de Bibliotecas e Definição de Limites

// Funções de entrada e saída (como printf e scanf)
#include <stdio.h>
// Manipulação de arquivos e outras funções utilitárias
#include <stdlib.h>
// Trabalhar com strings, como copiar ou camparar
#include <string.h>

#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Definindo alguns limites

// Quantidade máxima de livros no sistema
#define MAX_LIVROS 100
// Tamanho máximo do nome do autor ou título
#define MAX_NOME 50


// ETAPA 2: Criando a Estrutura Livro
struct Livro {
    int codigo;
    char titulo[MAX_NOME];
    char autor[MAX_NOME];
    int ano_publicacao;
    int disponivel; // 1 = disponível, 0 = emprestado
};

// ETAPA 3: Criando o Banco de Dados da Biblioteca
// Array que guarda até 100 livros
struct Livro biblioteca[MAX_LIVROS]; 
// Quantos livros foram cadastrados
int total_livros = 0;

// ETAPA 4: Protótipo(s) da(s) função(ões)
void carregar_biblioteca(void);
void salvar_biblioteca(void);
void adicionar_livro(void);
void listar_livros(void);
int buscar_livro(int codigo);
void emprestar_livro(void);
void devolver_livro(void);
void menu_principal(void);

int main() {
    //  mostrar caracteres acentuados
    // SetConsoleOutputCP( CP_UTF8 ); 

    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    // Atenção! Utilize o caractere de separação decimal referente à região definida!
    // Brasil -> ','
    // Estados Undos -> '.'    
    //setlocale(LC_ALL, "en_US.UTF-8");    
    //setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");  
    printf("%s\n\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));     

    // Exemplos PRátics Integrados

    // Exemplo Prático: Sistema de Gestão de Bibliteca

    // Uso dos principais conceitos da linguagem C:
    // - structs
    // - arrays
    // - funções
    // - ponteiros (implícitos em arrays e structs)
    // - manipulação de arquivos

    // Objetivo
    // - Cadastrar livros
    // - Listar todos os livros regitrados
    // - Marcar livros como emprestados ou devolvidos
    // - Salvar todos os dados em arquivos para persistência

    // ETAPA 5: A Funçã Main

    // Lê os dados do arquivo, se existirem
    carregar_bibliteca();
    // Mostra  menu interativo ao usuário
    menu_principal();
    // Salva alterações feitas no programa
    salvar_biblioteca();

    return 0;
}

// ETAPA 6: Carregando Dados do Arquivo
void carregar_biblioteca(void) {
    // Abre o arquivo em modo leitura - r
    FILE *arquivo = fopen("biblioteca.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de bibliteca não encontrado. Iniciando bibliteca vazia.");
        return;
    }

    // Lê os dados utilizando fscanf e os armazena no array de structs
    while (fscanf(arquivo, "%d %s %s %d %d",
            &biblioteca[total_livros].codigo,
            biblioteca[total_livros].titulo,
            biblioteca[total_livros].autor,
            &biblioteca[total_livros].ano_publicacao,
            &biblioteca[total_livros].disponivel) == 5 &&
        total_livros < MAX_LIVROS) {

        total_livros++;
    }    

    fclose(arquivo);
    printf("Bilioteca carrega com %d livros(s).\n", total_livros);
}
// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%