
#include "Desenhos.h"

void _gotoxy (short int X, short int Y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){X, Y});
}

void _Desenhar_Menu(void){

    for(unsigned short int Y = 1 ; Y <= 20 ; Y++){
        _gotoxy(0, Y);
        printf("%c", 219);
        _gotoxy(50, Y);
        printf("%c", 219);
    }

    for(unsigned short int X = 0 ; X <= 50 ; X++){
        _gotoxy(X, 0);
        printf("%c", 220);
    }

    for(unsigned short int X = 0 ; X <= 50 ; X++){
        _gotoxy(X, 20);
        printf("%c", 223);
    }


    for(unsigned short int X = 1 ; X < 50 ; X++){
        for(unsigned short int Y = 1 ; Y < 20 ; Y++){
            _gotoxy(X, Y);
            printf("%c", 177);
        }
    }

    _gotoxy(14, 9);
    printf("TECLE ALGO PARA INICIAR!");
}
