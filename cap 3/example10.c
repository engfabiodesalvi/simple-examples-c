#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Protótipo da função
void alterar_array(int vet[], int tamanho);

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

    // Passagem por referência
    
    int numeros[3] = {1, 2, 3};
    printf("Antes: %d\n", numeros[0]);
    alterar_array(numeros, 3);
    printf("Depois: %d\n", numeros[0]);

    return 0;
}

void alterar_array(int vet[], int tamanho) {
    vet[0] = 999;
}
// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%