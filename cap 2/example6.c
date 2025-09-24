#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Laços (loops)
    // Estrutura de Repetição
    // Automatizando Tarefas 

    // Laço Do-While
    // Garantindo pelo Menos uma Execução
    // Adivinhe o número secreto

    int numero = 0, tentativas = 0;
    int returnNumero = 0;
    const int NUMERO_SECRETO = 42;

    printf("\nJogo de Adivinhação!\n");
    printf("\nTente adivinhar o número entre 1 e 100:\n");

    do {
        printf("Digite um número: ");
        
        // Digite um número
        returnNumero = scanf("%d", &numero);
        
        tentativas++;

        // IMPORTANTE!!!!!!!!!
        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
        while (getchar() != '\n');

        // Analisando o número digitado
        if (returnNumero == 1) {
            if (numero < NUMERO_SECRETO) {
                printf("Muito baixo! Tente novamente.\n");
            } else if (numero > NUMERO_SECRETO) {
                printf("Muito alto! Tente novamente.\n");
            } else {
                printf("Parabéns! Você acertou em %d tentativas!\n", tentativas);
            }
        } else {
            printf("Valor inválido!\n");
        }

    } while (numero != NUMERO_SECRETO);
     
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%