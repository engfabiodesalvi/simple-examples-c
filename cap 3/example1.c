#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()

#include <locale.h>
#include <wchar.h> // Tratar strings acentuadas com espaçamentos iguais na impressão no prompt


int main() {
    //  mostrar caracteres acentuados
    // SetConsoleOutputCP( CP_UTF8 ); 
    
    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");    

    // Declaração e inicialização de um array (vetor) unidimensional de inteiros
    int numeros[5] = {10, 20, 30, 40, 50};

    // Acesso as elementos pelo índice
    printf("Primeiro elemento: %d\n", numeros[0]);
    printf("Último elemento: %d\n", numeros[4]);

    // Modificação de elementos
    numeros[2] = 35;

    // Iteração através do array
    for (int i = 0; i < 5; i++) {
        printf("Posição %d: %d\n", i, numeros[i]);
    }

    return 0;

}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%