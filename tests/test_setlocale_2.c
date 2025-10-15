#include <stdio.h>
#include <locale.h>

int main() {
    // Common Windows locales to test
    const char* locales[] = {
        "C",
        "English",
        "English_United States",
        "English_US",
        "Portuguese",
        "Portuguese_Brazil", 
        "Portuguese_Brazilian",
        NULL
    };
    
    for (int i = 0; locales[i] != NULL; i++) {
        char* result = setlocale(LC_ALL, locales[i]);
        if (result != NULL) {
            printf("SUCCESS: %s -> %s\n", locales[i], result);
        } else {
            printf("FAILED: %s\n", locales[i]);
        }
    }
    return 0;
}