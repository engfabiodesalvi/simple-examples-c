#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

// Function definition
// função que valida um número
int validarNumero(int num) {
    // Checa se o número é positivo
    if (num < 0) {
        printf("\nNúmero inválido: negativo.\n");
        return 0; // Indica falha
    }
    return 1; // Indica sucesso
}

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Controle de Fluxo Avançado
    // Comando Return: Finaliza a Função Imediatamente
    // Validação Simples com Return Precoce

    int numero;

    printf("\nDigite um número positivo: ");
    scanf("%d", &numero);

    if (!validarNumero(numero)) {
        return 1; // Encerra o programa por erro
    }
     
    printf("\nNúmero válido: %d\n", numero);
    return 0; // Programa encerra normalmente
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%