#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Controle de Fluxo Avançado
    // Comando Continue: Pula para a Próxima Iteração
    // Imprimir Apenas Números Pares de 1 a 20

    printf("\nNúmeros pares de 1 a 20:\n");

    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            continue; // pula o resto do loop para números ímpares
        }
        printf("%d\n", i);
    }
     
    printf("\n");

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%