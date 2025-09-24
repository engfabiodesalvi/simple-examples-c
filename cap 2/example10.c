#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Controle de Fluxo Avançado
    // Comando Break: Saída Imediata do Laço
    // Encontrar um Número em um Array e parar ao Encontrar
    int numeros[] = {2, 4, 6, 8, 10, 12};
    // número bytes numeros dividido pelo número de bytes de um elemento deste array
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int busca = 8;
    int encontrado = 0;

    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] == busca) {
            encontrado = 1;
            printf("Número %d encontrado na posição %d.\n", busca, i);
            break; // Sai do for assim que encontrar
        }
    }

    if (!encontrado) {
        printf("Número %d não encontrado.\n", busca);
    }
     
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%