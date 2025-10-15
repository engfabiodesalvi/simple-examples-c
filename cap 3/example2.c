#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()

#include <locale.h>
#include <wchar.h> // Tratar strings acentuadas com espaçamentos iguais na impressão no prompt


int main() {
    //  mostrar caracteres acentuados
    // SetConsoleOutputCP( CP_UTF8 ); 
    
    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    //setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");    
    printf("%s\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));

    // Declaração e inicialização de um array (vetor) multidimensional de inteiros
    // Matriz 3x3 representando um tabuleiro
    int tabuleiro[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Acesso de elemento
    printf("ELemento na posição [1][1]: %d\n", tabuleiro[1][1]);    

    // Modificação de elementos
    tabuleiro[0][0] = 0;

    // Percrrendo toda a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;

}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%