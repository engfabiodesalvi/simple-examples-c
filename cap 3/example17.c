#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Declarando a struct
struct Resultado {
    int soma;
    int produto;
    int diferenca;
};

// Protótipo(s) da(s) função(ões)
struct Resultado calcular(int a, int b);

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

    // Retorno de valores em funções
    // Exemplo 4 - Retornando uma Struct (Vários Dados Organizados)

    // Declarando a variável struct
    struct Resultado r = calcular(10, 5);

    // Imprimindo o resultado
    printf("Soma: %d\n", r.soma);
    printf("Produto: %d\n", r.produto);
    printf("Diferença: %d\n", r.diferenca);

    return 0;
}

// A função retorna uma struct
struct Resultado calcular(int a, int b) {
    struct Resultado r;
    r.soma = a + b;
    r.produto = a * b;
    r.diferenca = a - b;
    return r;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%