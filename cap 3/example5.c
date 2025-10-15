#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()

#include <locale.h>
#include <wchar.h> // Tratar strings acentuadas com espaçamentos iguais na impressão no prompt
#include <ctype.h> // isdigit()

#define MAX_LINE 256
#define MAX_NAME 100

// Estrutura para armazenar os dados presentes na linha
typedef struct {
    char nome[MAX_NAME];
    int idade;
    float salario;
} LinhaDados;

int main() {
    // Mostrar caracteres acentuados
    // Não funciona com determinadas funções
    //SetConsoleOutputCP( CP_UTF8 ); 
    
    // habilita UTF-8 no terminal 
    // Utilizar esta função para o correto funcinamento da biblioteca wchar.h
    // Atenção! Utilize o caractere de separação decimal referente à região definida!
    // Brasil -> ','
    // Estados Undos -> '.'    
    //setlocale(LC_ALL, "en_US.UTF-8");    

    printf("%s\n", setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"));      

    //printf("Teste: ã ç é ô %.2f\n\n", 3.14);

    // MANIPULAÇÃO DE ARQUIVCOS

    // Este programa modifica a separação decimal dos números obtidos do arquivo para atender a região selecionada.
    // Modifica "." para "," na string para posterior conversão em float ou double.

    // DETALHES DO MÉTODO
    // Uso de fgets() e sscanf()
    // Use este método na maioreia dos casos porque:
    // - Manipula naturalmente os espaços nos nomes
    // - Maipulação robusta dos erros
    // - Fácil para entender e modificar
    // - Boa performance

    // A chave é sempre utilizar fgets() para a leitura inteira da linha, então analisá-la (parsing), evitando muitos problemas comuns de entrada em C!

    // Variável para manipular o arquivo
    FILE *arquivo;
    // Variável para receber os dados de uma linha
    char linha[MAX_LINE];
    // Estrutura para receber os dados obtidos da leitura da linha
    LinhaDados linhaDados;

    // Abertura para escrita (cria ou sobrescreve)
    arquivo = fopen(".\\dados\\funcionarios2.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    } 

    // Escrita de dados em arquivo com a formatação: nome idade salario
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

    printf("\nDados dos funcionários:\n");
    // Ler as linhas até chegar ao final do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Encontra os últimos dois números a partir do final
        char *ptr = linha + strlen(linha) - 1;

        // Move de trás para frente para encontrar o útimo número
        while (ptr > linha && !((*ptr >= '0' && *ptr <= '9') || *ptr == '.' || *ptr == ',')) {              
            ptr--;
        }

        // Analiza (parse) o último número
        char *num2_inicio = ptr;
        while (
            num2_inicio > linha && 
            ((*(num2_inicio-1) >= '0' && *(num2_inicio-1) <= '9') || *(num2_inicio-1) == '.' || *(num2_inicio-1) == ',')
        ) {
            if (*num2_inicio == '.') {
                *num2_inicio = ',';
                //printf("%c\n", *num2_inicio);
            }            
            num2_inicio--;
        }

        // Analisa (parse) o penúltimo número
        char *num1_inicio = num2_inicio;
        while (num1_inicio > linha && *(num1_inicio-1) == ' ') {
            num1_inicio--;
        }

        while (num1_inicio > linha && (*(num1_inicio-1) >= '0' && *(num1_inicio-1) <= '9')) {
            num1_inicio--;
        }

        // Extraindo as partes
        linhaDados.salario = atof(num2_inicio);
        linhaDados.idade = atoi(num1_inicio);

        // Extraindo o nome (tudo antes do primeiro número)
        int nome_tamanho = num1_inicio - linha;
        if (nome_tamanho > 0 && nome_tamanho < MAX_NAME) {
            strncpy(linhaDados.nome, linha, nome_tamanho);
            linhaDados.nome[nome_tamanho] = '\0';
            // Removendo os espaçs à direita (trailing spaces) do nome
            while (nome_tamanho > 0 && linhaDados.nome[nome_tamanho-1] == ' ') {
                linhaDados.nome[nome_tamanho-1] = '\0';
                nome_tamanho--;
            }
        }

        // Imprimindo os dados da linha
        printf("Nome: '%s', Idade: %d, Salário: %.2f\n",
            linhaDados.nome, linhaDados.idade, linhaDados.salario);

    }
    
    // Fechamento obrigatório
    fclose(arquivo);
    
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%