#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo(s) da(s) função(ões)
void trocar_valores(int *a, int *b);
void calcular_operacoes(int a, int b, int *soma, int *produto, int *diferenca);

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

    // Trabalhando com ponteiros

    // Passagem por referência
    // Retornam multiplos valores ou modificam estruturas complexas

    // Exemplo de troca de valores
    int x = 10, y = 20;
    printf("Antes da troca: x = %d, y = %d\n", x, y);
    trocar_valores(&x, &y);
    printf("Depois da troca: x = %d, y = %d\n", x, y);

    // Exemplo de múltiplos retornos
    int num1 = 15, num2 = 3;
    int soma, produto, diferenca;
    calcular_operacoes(num1, num2, &soma, &produto, &diferenca);
    printf("Soma: %d, Produto: %d, Diferença: %d\n", soma, produto, diferenca);

    return 0;
}

// Função que troca valores usando ponteiros
void trocar_valores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que calcula múltiplos resultafos
void calcular_operacoes(int a, int b, int *soma, int *produto, int *diferenca) {
    *soma = a + b;
    *produto = a * b;
    *diferenca = a - b;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%