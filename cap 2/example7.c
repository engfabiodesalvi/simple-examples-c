#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Laços (loops)
    // Estrutura Completa de Controle
    // Automatizando Tarefas 

    // Laço For
    // Imprimir os Primeiros 10 Números Naturais

    printf("Números de 1 a 10:\n");

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    printf("\n");
     
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%