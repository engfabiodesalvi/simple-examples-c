#include <stdio.h>
#include <locale.h>

int main() {
    // Try to set to empty string (system default)
    char* result = setlocale(LC_ALL, "");
    if (result == NULL) {
        printf("setlocale with empty string failed\n");
    } else {
        printf("setlocale succeeded: %s\n", result);
    }
    
    // Try specific locales
    const char* locales[] = {"C", "en_US.UTF-8", "English_United States.1252", "Portuguese_Brazil.UTF-8", NULL};
    
    for (int i = 0; locales[i] != NULL; i++) {
        result = setlocale(LC_ALL, locales[i]);
        if (result != NULL) {
            printf("Success with: %s -> %s\n", locales[i], result);
            //break;
        } else {
            printf("Failed with: %s\n", locales[i]);
        }
    }
    
    return 0;
}