#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    // Validação de Entrada com scanf()
    int numero;

    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    printf("Digite um número: ");
    // Verifica se foi digitado um valor numérico
    // A saída de uma função scanf() é o número de entradas válidas para o tipo de dado especificado.
    // Neste caso é uma entrada com valor inteiro que deve ser digitada.
    if (scanf("%d", &numero) != 1) {
        printf("Entrada inválida!\n");
        return 1; // Encerra o programa com erro
    }

    return 0;
}

// run into prompt:
// $ exemplo{number}.exe
// $ echo %errorlevel%