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
    // Atenção! Utilize o caractere de separação decimal referente à região definida!
    // Brasil -> ','
    // Estados Undos -> '.'    
    //setlocale(LC_ALL, "en_US.UTF-8");    
    //setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");  
    printf("%s\n", setlocale(LC_ALL, "en_US.UTF-8"));      

    // Manipulação de arquivos

    // Declaração da variável que manipulará o arquivo
    FILE *arquivo;

    // Abertura para escrita (cria ou sobrescreve)
    arquivo = fopen(".\\dados\\funcionarios1.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    // Escrita de dados em arquivo com a formatação: nome idade salario
    // Separação decimal "."
    fprintf(arquivo, "João_Silva 30 3500.50\n");
    fprintf(arquivo, "Maria_Santos 25 4200.00\n");
    fprintf(arquivo, "Pedro_Costa 35 5500.75\n");
    fprintf(arquivo, "Florença_Conceição 51 2356.25\n");
    
    // Fechar arquivo após o uso
    fclose(arquivo);

    // Abrir arquivo para leitura
    arquivo = fopen(".\\dados\\funcionarios1.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    // Variáveis que receberão os dados do arquivo
    char nome[50];
    int idade;
    float salario;

    printf("Dados dos funcionários:\n");
    // Ler dados formatados do arquivo enquanto houver dados a serem lidos
    // fscanf() retorna  numero de dados lidos
    while (fscanf(arquivo, "%s %d %f", nome, &idade, &salario) == 3) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", nome, idade, salario);
    }
    
    // Fechamento obrigatório
    fclose(arquivo);
    
    return 0;
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%