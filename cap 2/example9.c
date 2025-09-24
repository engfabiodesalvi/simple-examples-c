#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Laços (loops)
    // Estrutura Completa de Controle
    // Automatizando Tarefas 

    // Laço For
    // Processar um Array para Calcular a Média

    int numeros[] = {5, 10, 15, 20, 25};
    // sizeof(numeros) retorna  numero de bytes do array
    // sizeof(numeros[0]) retorna o número de bytes do primeiro item do array
    // O número de itens do array é o número de bytes do array dividido pelo número de bytes de alguma posição deste array.
    // Considerando que o tipo de dado int possui 32bytes
    // O tamanho do array possui 20 bytes
    // Uma posição deste array possui 4 bytes.
    // O númer de itens deste array vale 20 / 4 = 5 itens.
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }

    float media = (float) soma / tamanho;
    printf("\nA média dos números é: %.2f\n", media);
     
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%