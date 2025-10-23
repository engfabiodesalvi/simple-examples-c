#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Declarando as structs
struct Endereco {
    char rua[50];
    int numero;
};

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    struct Endereco endereco;
};

// Protótipo(s) da(s) função(ões)
void aumentar_idade(struct Pessoa *p) {
    p->idade++;
}

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

    // -------------------------------
    // Trabalhando com structs e arrays

    // Armazenando várias pessoas, livros, produtos, etc
    // Vetor com 100 pessoas
    struct Pessoa grupo[100];

    // Acessando os elementos
    grupo[0].idade = 30;
    strcpy(grupo[1].nome, "Maria");

    // -------------------------------    
    // Structs com ponteiros (Passagem por Referência)
    
    // Modificação por referência
    aumentar_idade(&grupo[0]);

    // -------------------------------
    // Structs dentro de Structs (Aninhadas)

    // Declarando um variável struct
    struct Pessoa p1;

    // Atribuinto valores
    strcpy(p1.nome, "Maria");
    p1.idade = 20;
    p1.altura = 1.57;
    strcpy(p1.endereco.rua, "Av. Brasil");
    p1.endereco.numero = 123;

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%