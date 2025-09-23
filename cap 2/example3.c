#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Operadores Lógicos: Combinando Condições    
    
    int idade;

    printf("\nDigite sua idade: ");

    // verifica se foi digitado um valor numérico
    if (scanf("%d", &idade) == 1) {
        // Verifica se esta na idade adulta ou é jovem ou idoso        
        if (idade >= 18 && idade < 65) {
            printf("\nVocê esta na idade adulta!\n");                
        } else {
            printf("\nVocê é jovem ou idoso!\n");
        }  
    } else {
        printf("\nAcesso negado: valor incorreto!\n");
        return 1;
    }
      
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%