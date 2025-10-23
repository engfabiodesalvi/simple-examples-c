#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Declarando as structs
struct Livro {
    int codigo;
    char titulo[50];
    char autor[50];
    int ano_publicacao;
    int disponivel;
};

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};


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

    // Trabalhando com structs

    // Declarando uma variável struct
    struct Livro livro;
    struct Pessoa aluno;

    // Atribuindo um valor
    strcpy(livro.titulo, "Memórias Póstumas de Brás Cubas");
    strcpy(livro.autor, "Machado de Assis");
    livro.ano_publicacao = 1881;
    livro.codigo = 1;
    livro.disponivel = 1; // 1 - True / 0 - False

    // Atribuindo um valor
    strcpy(aluno.nome, "Carlos");
    aluno.idade = 21;
    aluno.altura = 1.75;

    // Imprimindo valores no prompt
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano da publicação: %d\n", livro.ano_publicacao);
    printf("Código: %d\n", livro.codigo);
    printf("Disponível: %s\n", (livro.disponivel)? "sim" : "não");
    printf("\n");

    // Imprimindo valores no prompt
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Altura: %.2f\n", aluno.altura);

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%