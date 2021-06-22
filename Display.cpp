
#include "Display.h"

void _gotoxy (short int X, short int Y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){X, Y});
}

unsigned char _PLANO::_Get_Estrutura_Mapa(unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Tipo_Estrutura){
    if(Mapa[Mapa_X][Mapa_Y] != 0)
        return Estruturas[Mapa[Mapa_X][Mapa_Y]-1][Tipo_Estrutura];
    else
        return 0;
}

void _PLANO::_Desenhar_Plano(void){
    for(unsigned char X = 0 ; X < 20 ; X++){
        for(unsigned char Y = 0 ; Y < 20 ; Y++){
            if(Mapa[X][Y] != 0){
                _gotoxy(X, Y);
                printf("%c", Estruturas[Mapa[X][Y]-1][0]);
            }
        }
    }
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
