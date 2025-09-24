#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()


int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados
    
    // Aplicações Práticas e Casos de Estudo

    // Validação de Dados com Múltiplas Tentativas

    char senha[20];
    int returnSenha = 0;
    const char SENHA_CORRETA[] = "admin123";
    int tentativas = 0;
    const int MAX_TENTATIVAS = 3;

    printf("\nSistema de Login\n");

    while (tentativas < MAX_TENTATIVAS) {

        printf("\nDigite a senha (%d/%d tentaivas): ", tentativas + 1, MAX_TENTATIVAS);

        // Solicita ao usuário uma senha
        returnSenha = scanf("%s", senha);

        // IMPORTANTE!!!!!!!!!
        // Limpando o buffer de entrada para prevenir problemas com outra chamada à função scanf()
        while(getchar() != '\n');

        if (returnSenha == 1) {
            // compara a senha digitada com a senha correta
            if (strcmp(senha, SENHA_CORRETA) == 0) {
                printf("\nLogin realizado com sucesso!\n");
                printf("Bem-vindo ao sistema!\n");
                return 0;
            } else {
                tentativas++;
                if (tentativas < MAX_TENTATIVAS) {
                    printf("\nSenha incorreta! Restam %d tentativas.\n", MAX_TENTATIVAS - tentativas);
                }
            }
        } else {
            printf("\nValor inválido!\n");
        }
    }

    printf("\nNúmero máximo de tentaivas excedido! Acesso bloqueado!\n");
    return 1;

}



// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%