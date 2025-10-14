#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> // SetConsoleOutputCP()


int main() {
    //  mostrar caracteres acentuados
    SetConsoleOutputCP( CP_UTF8 ); 
    

    return 0;
}



// run into prompt:
// $ prompt $G
// $ exemplo{number}.exe
// $ echo %errorlevel%