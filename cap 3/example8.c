#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo das funções
int calcular_fatorial(int n);
float calcular_media(int n1, int n2, int n3);
float calcular_media_array(int numeros[], int tamanho_numeros);
void exibir_resultado(float media);

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

    // Programa que uiliza Funções
    // - Calculo de fatorial fatorial
    // - Calculo de média de notas
    // - Exibe resultado com base na média
    
    // Número para o cálculo do fatorial
    int numero = 5;
    // Valores para o calculo da média
    int numeros[] = {80, 90, 70, 20, 55};
    // Resultado da média
    float media;
    // Resultado da média
    float media_array;

    // Chamando a função que retorna o fatorial
    int fat = calcular_fatorial(numero);
    printf("Fatorial de %d = %d\n", numero, fat);

    // Chamando a função que retorna a média
    media = calcular_media(80, 90, 70);

    // Chamando a função que retorna a média de um array
    media_array = calcular_media_array(numeros, sizeof(numeros) / sizeof(numeros[0]));

    // Chamando a função void (sem retorno)
    exibir_resultado(media);

    // Chamando a função void (sem retorno)
    exibir_resultado(media_array);    

    return 0;
}

// Função para calcular o fatorial (sem recursão)
int calcular_fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função para calcular a média de 3 números
float calcular_media(int n1, int n2, int n3) {
    prinf("1 %d\n2 %d\n3 %d\n", n1, n2, n3);
    return (n1 + n2 + n3) / 3.0;
}

// Função para calcular a média do array números
float calcular_media_array(int numeros[], int tamanho_numeros) {
    int soma = 0;
    for (int i = 0; i < tamanho_numeros; i++) {
        soma += numeros[i];
        printf("%d - %d\n", i, numeros[i]);
    }
    return (float) soma / tamanho_numeros;
}

// Função void para exibir o resultado baseado na média
void exibir_resultado(float media) {
    printf("Média: %.2f\n", media);
    if (media >= 70) {
        printf("Status: Aprovado\n");
    } else {
        printf("Status: Reprovado\n");
    }
}


// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%