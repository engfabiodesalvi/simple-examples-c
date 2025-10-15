#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()

#include <locale.h>
#include <wchar.h> // Tratar strings acentuadas com espaçamentos iguais na impressão no prompt


int main() {
    //  mostrar caracteres acentuados
    // SetConsoleOutputCP( CP_UTF8 ); 
    
    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    //setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");  
    printf("%s\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));  

    // Manipulação de arquivos

    // Declaração da variável que manipulará o arquivo
    FILE *arquivo;

    // Abertura para escrita (cria ou sobrescreve)
    arquivo = fopen(".\\dados\\dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    // Escrita no arquivo
    fprintf(arquivo, "Primeira linha do arquivo\n");
    fprintf(arquivo, "Segunda linha com número: %d\n", 42);

    // Fechamento obrigatório
    fclose(arquivo);

    // Abertura para leitura
    arquivo = fopen(".\\dados\\dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("Lido: %s", linha);
    }

    // Fechamento obrigatório
    fclose(arquivo);
    
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%