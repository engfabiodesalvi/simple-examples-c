#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main() {
    SetConsoleOutputCP( CP_UTF8 ); //  mostrar caracteres acentuados

    // Conversr de temperatura

    float temperatura, convertida;
    char escala;

    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);

    printf("Digite a escala (C para Celsius, F para Fahrenheit): ");
    scanf(" %c", &escala);

    if (escala == 'C' || escala == 'c') {
        convertida = (temperatura * 9.0 / 5.0) + 32.0;
        printf("%.2f°C = %.2f°F\n", temperatura, convertida);
    } else if (escala == 'F' || escala == 'f') {
        convertida = (temperatura - 32.0) * 5.0 / 9.0;
        printf("%.2f°F = %.2f°C\n", temperatura, convertida);
    } else {
        printf("Escala inválida!\n");
        return 1;
    }

    return 0;
}

// run into prompt:
// $ exemplo7.exe
// $ echo %errorlevel%