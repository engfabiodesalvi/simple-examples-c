#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Condicionais Compostas    
    
    int idade = 0, renda = 0;
    int returnIdade = 0, returnRenda  = 0;

    printf("\nDigite sua idade: ");
    // digite sua idade
    returnIdade = scanf("%d", &idade);

    printf("\nDigite sua renda: ");
    // digite sua renda
    returnRenda = scanf("%d", &renda);    

    // verifica se foi digitado um valor numérico para idade e para renda
    if (returnIdade == 1 && returnRenda == 1) {
        // Utiliza condicionais compostas para definir a melhor linha de crédito
        // com base na idade e na renda do usuário        
        if (idade >= 18 && renda >= 2000) {
            printf("\nAprovado para o cartão de crédito premium!\n");                
        } else if (idade >= 18 && renda >= 1000) {
            printf("\nAprovado para o cartão de crédito básico!\n");
        } else {
            printf("\nNão aprovado para cartão de crédito!\n");
        }
    } else {
        printf("\nAcesso negado: valor(es) incorreto(s)!\n");
        return 1;
    }
      
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%