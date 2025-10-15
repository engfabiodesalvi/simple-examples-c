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
    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");    

    // Manipulação de arquivos
    // Processamento de Dados Texto

    // Declaração da variável que manipulará o arquivo
    FILE *logFile;
    // Declaração das variáveis de manipulação dos dados texto
    char linha[200];
    int totalAcessos = 0;
    int acessosErro = 0;

    // Abertura para escrita (cria ou sobrescreve)
    logFile = fopen(".\\dados\\access.log", "r");
    if (logFile == NULL) {
        printf("Erro ao abrir arquivo de log!\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), logFile) != NULL) {
        totalAcessos++;

        // verifica se a linha contém códigos de erros HTTP communs
        if (strstr(linha, " 404 ") || strstr(linha, " 500 ")) {
            acessosErro++;
        }
    }

    // Fechar o arquivo após o uso
    fclose(logFile);

    // Impressão dos resultados
    printf("Total de acessos: %d\n", totalAcessos);
    printf("Acessos com erro: %d\n", acessosErro);
    printf("Taxa de erro: %.2f%%\n", (float) acessosErro / totalAcessos * 100);

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%