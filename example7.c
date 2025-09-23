#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    // Validação de Entrada com scanf()
    int numero;

    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    printf("Digite um número: ");
    
    if (scanf("%d", &numero) != 1) {
        printf("Entrada inválida!\n");
        return 1; // Encerra o programa com erro
    }

    return 0;
}

// run into prompt:
// $ exemplo7.exe
// $ echo %errorlevel%