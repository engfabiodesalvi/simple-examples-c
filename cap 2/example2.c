#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Estrutras de decisão

    // Condicionais Aninhadas

    // if..else
    
    // Decisões mais Detalhadas
    
    int idade;

    printf("\nDigite sua idade: ");

    // verifica se foi digitado um valor numérico
    if (scanf("%d", &idade) == 1) {
        // Verifica se é criança ou maior de idade
        // Verifica se a idade é maior ou igual a 18        
        if (idade >= 18) {
            // Verifica se é adulto ou idoso
            if (idade < 65) {
                printf("\nAcesso liberado! Adulto!\n");
            } else {
                printf("\nAcesso liberado! Idoso!\n");                
            }
        } else {
            printf("\nAcesso negado! Menor de idade!\n");
        }  
    } else {
        printf("\nAcesso negado: valor incorreto!\n");
        return 1;
    }
      
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%