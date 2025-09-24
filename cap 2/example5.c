#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Estrutura de Controle
    // Estrutura Switch/Case
    // Múltiplas Alternativas    
    
    // Menu de Opções

    int opcao = 0;
    int returnOpcao = 0;

    printf("\nMenu:\n\n");
    printf("1 - Novo jogo\n");
    printf("2 - Carregar jogo\n");
    printf("3 - Sair\n");

    printf("\nEscolha uma opção: ");
    // digite sua opçao
    returnOpcao = scanf("%d", &opcao);
    

    // verifica se uma opcao foi digitada
    if (returnOpcao == 1) {
        switch(opcao) {
            case 1:
                printf("\nVocê escolheu iniciar um novo jogo.\n");
                break;
            case 2:
                printf("\nVocê escolheu carregar um jogo salvo.\n");
                break;
            case 3:
                printf("\nSaindo do jogo. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } else {
        printf("\nValor inválido!\n");
        return 1;
    }
      
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%