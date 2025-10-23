#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo(s) da(s) função(ões)

int main() {
    //  mostrar caracteres acentuados
    // SetConsoleOutputCP( CP_UTF8 ); 

    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    // Atenção! Utilize o caractere de separação decimal referente à região definida!
    // Brasil -> ','
    // Estados Undos -> '.'    
    //setlocale(LC_ALL, "en_US.UTF-8");    
    //setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");  
    printf("%s\n\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));     

    // Trabalhando com Ponteiros

    // Declarando as variáveis
    int valor = 42;
    int *ponteiro = &valor;

    // Imprimindo dados das variáveis
    printf("Valor da variável: %d\n", valor);
    printf("Endereço da variável: %p\n", &valor);
    printf("Valor do ponteiro: %p\n", ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);

    // Modificação através do ponteiro
    *ponteiro = 100;
    printf("Novo valor da variável: %d\n", valor);

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%