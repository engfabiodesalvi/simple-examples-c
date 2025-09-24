#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Laços (loops)
    // Estrutura Completa de Controle
    // Automatizando Tarefas 

    // Laço For
    // Somar os Números de 1 a 100

    int soma = 0;

    for (int i = 1; i <= 100; i++) {
        soma += i; // soma = soma + 1
    }

    printf("\nA soma dos números de 1 a 100 é: %d.\n", soma);
     
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%