#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    float num1, num2, resultado;
    char operador;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite  operador (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    switch(operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero!\n");
                return 1;
            }
            break;
        default:
            printf("Operador inválido!\n");
            return 1;
    }
    printf("%.2f %c %.2f = %.2f\n", num1, operador, num2, resultado);
    return 0;

}

// run into prompt:
// $ exemplo7.exe
// $ echo %errorlevel%