#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

#define MAX_LINE 256
#define MAX_NAME 100

// Estrutura para armazenar os dados presentes na linha
typedef struct {
    char nome[MAX_NAME];
    int idade;
    float salario;
} LinhaDados;

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
    //printf("%s\n\n", setlocale(LC_ALL, "en_US.UTF-8"));     
    printf("%s\n\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));     

    // MANIPULAÇÃO DE ARQUIVCOS

    // Este programa modifica a separação decimal dos números obtidos do arquivo para atender a região selecionada.
    // Modifica "." para "," na string para posterior conversão em float ou double.

    // DETALHES DO MÉTODO
    // Semelhante ao CSV
    // Use este método se:
    // - Precisar manipular strings complexas com vírgulas
    // - Interoperabilidade com other programs
    // - Boa performance

    // A chave é sempre utilizar fgets() para a leitura inteira da linha, então analisá-la (parsing), evitando muitos problemas comuns de entrada em C!
    
    // Variável para manipular o arquivo
    FILE *arquivo;
    // Variável para receber os dados de uma linha
    char linha[MAX_LINE];
    // Estrutura para receber os dados obtidos da leitura da linha
    LinhaDados linhaDados;

    // Abertura para escrita (cria ou sobrescreve)
    arquivo = fopen(".\\dados\\funcionarios3.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    } 

    // Escrevendo no formato semelhante ao CSV
    // Escrita de dados em arquivo com a formatação: nome idade salario
    // Separação decimal "."
    fprintf(arquivo, "\"João Silva\",30,3500.50\n");
    fprintf(arquivo, "\"Maria Santos\",25,4200.00\n");
    fprintf(arquivo, "\"Pedro Costa\",35,5500.75\n");
    fprintf(arquivo, "\"Florença Conceição\",51,2356.25\n");

    // Fechar arquivo após o uso
    fclose(arquivo);
    
    // Abrir arquivo para leitura
    arquivo = fopen(".\\dados\\funcionarios3.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }    

    // Lendo no formato semelhante ao CSV
    printf("Dados dos funcionários:\n");
    // Ler as linhas até chegar ao final do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {    
        // Para armazenar os tokens
        char *token;

        // Remove o caracter de nova linha
        linha[strcspn(linha, "\n")] = 0;

        // Obtendo o nome como um string
        // Analisa (parse) o nome quotado
        token = strtok(linha, "\"");

        // Se houver um token
        if (token) {
                // Atulizando o nome
                strcpy(linhaDados.nome, token);

                // Obtem o restante dos dados após a quota
                // Obtendo a idade como um inteiro
                token = strtok(NULL, ",");
                // Atualizando a idade
                linhaDados.idade = atoi(token);

                // Obtendo o salário como um float                
                token = strtok(NULL, ",");
                // Substiruindo a separação decmal de "." por ","
                for (int i = 0; i < strlen(token); i++) {
                    if (token[i] == '.')
                        token[i] = ',';
                }
                // Atualizando o salário
                linhaDados.salario = atof(token);

                // Imprimindo os dados da linha
                printf("Nome: '%s', Idade: %d, Salário: %.2f\n",
                    linhaDados.nome, linhaDados.idade, linhaDados.salario);                
        }



    }

    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%