#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <math.h>

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Operadores aritméticos    

    // Cuidados com overflow
    int a = 1000000;
    int b = 1000000;
    long long resultado = (long long) a * b; // Cast para evitar verflow
    printf("Cuidados com overflow.");
    printf("Resultado: %lld\n", resultado);

    // Divisão interia vs. divisão real
    int x = 7, y = 2;
    int inteiro = x / y;        // Resultado: 3
    float real = (float) x / y;  // Resultado: 3.5
    printf("Divisão inteira vs. divisao real.\n");
    printf("Divisão inteira: %d\n", inteiro);
    printf("Divisão real: %f\n", real);

    // Módulo
    printf("Módulo\n");
    int n = 17;
    if (n % 2 == 0) 
        printf("Par\n");
    else
        printf("Ímpar\n");


    // Operadores Relacionais

    // Comparando floats com tolerância
    if (fabs(a - b) < 0.0001)
        printf("Aproximadamente iguais\n");

    // Operadores Lógicos

    // Avaliação em curt-circuito
    if (x != 0 && y / x > 1) // Evita divisã por zero
        printf("Evita divisão por zero!\n");

    // Precedencia de Operadores
    int resultado2 = 2 + 3 * 4;      // 2 + (3*4) = 14
    int valor = 10 > 5 && 3 < 7;    // true && true = 1

    // Use parênteses para clareza
    int a2 = 1, b2 = 2, c = 1, d = 2, e = 3;
    int r = a + ((b * c) / d) - e;

    // Operadores de Incremento e Decremento
    int a3 = 5, b3 = 5;
    int x2 = ++a3; // x = 6, a3 = 6
    int y2 = b3++;

    // Conversão de Tipo (Casting)

    // Conversão implícita
    int inteiro2 = 10;
    float decimal = 3.5;
    float resultado3 = inteiro2 + decimal; // inteiro vira float

    // Conversão explícita
    int a4 = 7, b4 = 2;
    float div = (float) a / b; // Força divisão real
    int grande = 300;
    char pequeno = (char) grande; // Pode gerar valor inválido
}

// run into prompt:
// $ exemplo{number}.exe
// $ echo %errorlevel%