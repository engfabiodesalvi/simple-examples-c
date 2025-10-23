#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo da função
void operacoes(int a, int b, int *soma, int *produto, int *diferenca);

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
    // Exemplo 3 - Retornando Múltiplos Valores com Ponteiros

    int x = 10, y = 4;
    int soma, produto, diferenca;

    operacoes(x, y, &soma, &produto, &diferenca);

    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", produto);
    printf("Diferenca: %d\n", diferenca);

    return 0;
}

// Calcula várias operações e retorna os valores pelos ponteiros
void operacoes(int a, int b, int *soma, int *produto, int *diferenca) {
    *soma = a + b;
    *produto = a * b;
    *diferenca = a - b;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%