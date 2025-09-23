#include <stdio.h>

int main() {
    int numero;
    float preco;
    char categoria;

    // Entrada de dados cm scanf()
    printf("Digite um número: ");
    scanf("%d", &numero);

    printf("Digite o preço: ");
    scanf("%f", &preco);

    printf("Digite a categoria: ");
    scanf(" %c", &categoria); // espaço antes de %c é importante!

    printf("Número: %d, Preço: %.2f, Categoria: %c\n",
            numero, preco, categoria);

    return 0;
}