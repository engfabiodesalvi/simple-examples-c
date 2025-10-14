#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()

#include <locale.h>
#include <wchar.h> // Tratar strings acentuadas com espaçamentos iguais na impressão no prompt
#include <ctype.h> // isdigit()

#define MAX_LINE 256
#define MAX_NAME 100

typedef struct {
    char nome[MAX_NAME];
    int idade;
    float salario;
} DataRow;

int main() {
    // Mostrar caracteres acentuados
    // Não funciona com determinadas funções
    // SetConsoleOutputCP( CP_UTF8 ); 
    
    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    // Atenção! Utilize os caracteres de separação decimal referentes à região definida!
    // Brasil -> ','
    // Estados Undos -> '.'    
    //setlocale(LC_ALL, "en_US.UTF-8");    
    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");    

    // Manipulação de arquivos

    // Variável para manipular o arquivo
    FILE *arquivo;
    // Variável para receber os dados de uma linha
    char linha[MAX_LINE];
    // Estrutura para receber os dados obtidos da leitura da linha
    DataRow row;

    // Abertura para escrita (cria ou sobrescreve)
    arquivo = fopen(".\\dados\\funcionarios2.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    } 

    // Escrita dados no arquivo com formataçã0: nome idade salario
    // Separação decimal "."
    fprintf(arquivo, "João Silva 30 3500.50\n");
    fprintf(arquivo, "Maria Santos 25 4200.00\n");
    fprintf(arquivo, "Pedro Costa 35 5500.75\n");
    
    // Fechar arquivo após o uso
    fclose(arquivo);
    
    // Abrir arquivo para leitura
    arquivo = fopen(".\\dados\\funcionarios2.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    printf("Dados dos funcionários:\n");
    // Ler as linhas até chegar ao final do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Encontra os últimos dois números a partir do final
        char *ptr = linha + strlen(linha) - 1;

        // Voltando para encontrar o útimo número
        while (ptr > linha && !((*ptr >= '0' && *ptr <= '9') || *ptr == '.')) {
            ptr--;
        }

        // Analiza (parse) o último número
        char *num2_inicio = ptr;
        while (num2_inicio > linha && ((*(num2_inici-1) >= '0')))
    }
    
    // Fechamento obrigatório
    fclose(arquivo);
    
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%