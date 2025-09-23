#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Estrutras de decisão
    
    // Condicionais Aninhadas

    // if..else
    
    // Verificação de idade
    
    int idade;

    printf("\nDigite sua idade: ");

    // verifica se foi digitado um valor numérico
    if (scanf("%d", &idade) == 1) {
        // verifica se a idade é maior ou igual a 18
        if (idade >= 18) {
            printf("\nAcesso liberado: você é maior de idade!\n");
        } else {
            printf("\nAcesso negado: você é menor de idade!\n");
        }  
    } else {
        printf("\nAcesso negado: valor incorreto!\n");
        return 1;
    }
      
    return 0;
}

// run into prompt:
// $ exemplo{number}.exe
// $ echo %errorlevel%