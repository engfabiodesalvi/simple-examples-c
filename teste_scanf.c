#include <stdio.h>

int main() {
    char numeros[50];

    printf("Digite um número: ");
    if (scanf("%49[^\\n]", numeros) == 1) {
        printf("Você digitou: %s\n", numeros);
    } else {
        printf("Falha ao ler.\n");
    }

    return 0;
}
