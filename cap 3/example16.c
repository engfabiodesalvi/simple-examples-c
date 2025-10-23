#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()
#include <locale.h> // setlocale()

// Definição da estrutura
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

// Protótipo(s) da(s) função(ões)
void exibir_produto(struct Produto p);
void aplicar_desconto (struct Produto *p, float percentual);

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

    // Aplicações Práticas de Structs
   
    // Representar entidades reais: alunos, clientes, produtos, veículos, fncionários;
    // - Modelar registros em arquivos (como bancos de dados simples);
    // - Implementar estruturas de dados mais complexas como listas encadeadas, árvores binárias, grafos etc.;
    // - Comunicação com hardware ou redes (ex: pacotes de dados).

    // Inicialização de struct
    struct Produto produto1 = {1001, "Notebook", 2500.00, 15};

    // Outra forma de inicialização
    struct Produto produto2;
    produto2.codigo = 1002;
    strcpy(produto2.nome, "Mouse");
    produto2.preco = 45.90;
    produto2.estoque = 50;

    // Exibir os produtos
    exibir_produto(produto1);
    exibir_produto(produto2);

    // Aplicando descontos
    aplicar_desconto(&produto1, 10); // 10% de desconto
    printf("Após desconto:\n");
    exibir_produto(produto1);

    return 0;
}

// Função que trabalha com struct
void exibir_produto(struct Produto p) {
    printf("Código: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preço: R$ %.2f\n", p.preco);
    printf("Estoque: %d unidades\n", p.estoque);
    printf("-----------------------\n");
}

// Função quee modifica struct (passagem por referência)
void aplicar_desconto (struct Produto *p, float percentual) {
    p->preco *= (1 - percentual / 100);
}

// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%