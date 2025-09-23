#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Elementos Enriquecedores

    // Debudding e Boas Práticas

    // Comentários significativos

    // Verifica se  ano é bissexto
    int ano ;
    printf("Digite um ano: ");
    if (scanf("%d", &ano) == 1 || ano > 0) {
        // (divisível por 4, exceto século não divisível por 400)
        if ((ano % 4 == 0 && ano & 100 != 0) || (ano % 400 == 0)) {
            printf("%d - Ano bissexto\n", ano);
        } else {
            printf("%d - Ano não bissexto\n", ano);
        }
    } else {
        printf("Entrada inválida.\n");
        return 1;        
    }

    return 0;
}

// run into prompt:
// $ exemplo7.exe
// $ echo %errorlevel%