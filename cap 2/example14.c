#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

void exibirMenu();

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Aplicações Práticas e Casos de Estudo
    // Sistema de Menu Interativo
    // Combinação de estruturas de decisão (switch/case) e repetição (do-while)

    // Sistema de Menu Interativo

    int opcao = 0, returnOpcao, returnValor;
    float saldo = 1000.0;
    float valor = 0.0;

    do {
        exibirMenu();
        returnOpcao = scanf("%d", &opcao);

        // IMPORTANTE!!!!!!!!!
        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
        while(getchar() != '\n');
        
        if (returnOpcao == 1) {
            switch (opcao) {
                case 1:
                    printf("\nSeu saldo atual é: R$ %.2f\n", saldo);
                    break;
                
                case 2:
                    printf("\nDigite o valor para depósito: R$ ");
                    returnValor = scanf("%f", &valor);

                    // IMPORTANTE!!!!!!!!!
                    // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
                    while(getchar() != '\n');   

                    // Verifica se foi digitado um valor numérico
                    if (returnValor == 1) {
                        if (valor > 0) {
                            saldo += valor;
                            printf("\nDepósito realizado! Novo saldo: R$ %.2f\n", saldo);
                        } else {
                            printf("\nValor inválido!\n");
                        }
                    } else {
                        printf("\nValor inválido!\n");                        
                    }
                    break;

                case 3:
                    printf("\nDigite o valor para saque: R$ ");
                    returnValor = scanf("%f", &valor);

                    // IMPORTANTE!!!!!!!!!
                    // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
                    while(getchar() != '\n');                       

                    // Verifica se foi digitado um valor numérico e se esse valor é maior do que zero
                    if (returnValor == 1 && valor > 0.0) {
                        if (valor > 0 && valor <= saldo) {
                            saldo -= valor;
                            printf("\nSaque realizado! Novo saldo: R$ %.2f\n", saldo);
                        } else {
                            printf("\nSaldo insuficiente!\n");
                        }
                    } else {
                        printf("\nValor inválido!\n");                        
                    }                    
                    break;
                
                case 4:
                    printf("\nObrigado por utilizar nosso sistema!\n");
                    break;

                default:
                    printf("\nOpção inválida! Tente novamente!\n");
                    break;

            }
        } else {
            printf("\nValor inválido!\n");
        }

    } while (opcao != 4);

    return 0; // Programa encerra normalmente
}

void exibirMenu() {
    printf("\n=== SISTEMA BANCÁRIO ===\n\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Sair\n\n");
    printf("Escolha uma opção: ");
}


// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%