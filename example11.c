#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Elementos Enriquecedores
    
    // Tratamento de Erro: Uma Necessidade Fundamental

    // Validação

    int num ;
    printf("Digite um número positivo: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Entrada inválida.\n");
        return 1;
    }
    return 0;
}

// run into prompt:
// $ exemplo7.exe
// $ echo %errorlevel%