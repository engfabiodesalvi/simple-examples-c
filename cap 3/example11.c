#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo da função
int encontrar_maior(int a, int b, int c);

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
    // Exemplo 1 - Retornando um valor simples
    int x = 15, y = 23, z = 19;

    int resultado = encontrar_maior(x, y, z);

    printf("Maior valor: %d\n", resultado);

    return 0;
}

// Retorna o maior valor entre três inteiros
int encontrar_maior(int a, int b, int c) {
    int maior = a;

    if (b > maior) maior = b;
    if (c > maior) maior = c;

    return maior;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%