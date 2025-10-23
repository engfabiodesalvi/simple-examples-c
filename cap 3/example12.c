#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo da função
int dividir_seguro(float a, float b, float *resultado);

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

    // Retorno de valores em funções
    // Exemplo 2 - Retornando Status (Sucesso/Erro)
    
    float resultado;

    if (dividir_seguro(10.0, 2.0, &resultado)) {
        printf("Resultado da divisão: %.2f\n", resultado);
    } else {
        printf("Erro: Divisão por zero!\n");
    }
 
    if (dividir_seguro(10.0, 0.0, &resultado)) {
        printf("Resultado da divisão: %.2f\n", resultado);
    } else {
        printf("Erro: Divisão por zero!\n");
    }

    return 0;
}

// Função que tenta dividir e retornar status
int dividir_seguro(float a, float b, float *resultado) {
    if (b == 0) {
        return 0; // Erro: divisão por zero
    }

    *resultado = a / b;
    return 1; // Sucesso
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%