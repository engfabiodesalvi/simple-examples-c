int global = 100; // Escopo global

int main() {

    int local = 50; // Escopo local à função main

    if (local > 0) {
        int bloco = 25; // Escopo de bloco
        // Aqui: global, local e bloco são visíveis
    }

    // Aqui: 'bloco' Não é visivel
    return 0;

}