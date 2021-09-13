
#include "Display.h"

constexpr unsigned char UP     = 1;
constexpr unsigned char DOWN   = 2;
constexpr unsigned char LEFT   = 3;
constexpr unsigned char RIGHT  = 4;

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

void _PLANO::_Mudar_Valor_Mapa(unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Valor){
    Mapa[Mapa_X][Mapa_Y] = Valor;
}

void _PLANO::_Criar_Fruta(std::vector <unsigned char> &Posisoes_Invalidas_X, std::vector <unsigned char> &Posisoes_Invalidas_Y){
    unsigned char Posisao_Fruta_X;
    unsigned char Posisao_Fruta_Y;
    unsigned char Posisao_Valida;

    do
    {
        Posisao_Valida = 0;

        Posisao_Fruta_X = rand() % 20;
        Posisao_Fruta_Y = rand() % 20;

        if(Mapa[Posisao_Fruta_X][Posisao_Fruta_Y] != 0){
            Posisao_Valida = 1;
        }else{
            for(short int X = 0 ; X < short(Posisoes_Invalidas_X.size()) ; X++)
            {
                if(Posisao_Fruta_X == Posisoes_Invalidas_X[X] && Posisao_Fruta_Y == Posisoes_Invalidas_Y[X]){
                    Posisao_Valida = 1;
                }
            }
        }


    }while(Posisao_Valida != 0);
    Mapa[Posisao_Fruta_X][Posisao_Fruta_Y] = 4;
    _gotoxy(Posisao_Fruta_X, Posisao_Fruta_Y);
    printf("%c", Estruturas[3][0]);
}

void _GAME_OVER(void){
    for(unsigned char Y = 2 ; Y <= 22 ; Y++){
        _gotoxy(5, Y);
        printf("%c", 219);
        _gotoxy(85, Y);
        printf("%c", 219);
    }
    for(unsigned char X = 5 ; X <= 85 ; X++){
        _gotoxy(X, 2);
        printf("%c", 220);
        _gotoxy(X, 22);
        printf("%c", 223);
    }

    _gotoxy(30, 10);
    printf("FIM DE JOGO =^(");
}

void _Desenhar_Menu(void){
    for(unsigned char Y = 1 ; Y <= 20 ; Y++){
        _gotoxy(0, Y);
        printf("%c", 219);
        _gotoxy(50, Y);
        printf("%c", 219);
    }
    for(unsigned char X = 0 ; X <= 50 ; X++){
        _gotoxy(X, 0);
        printf("%c", 220);
        _gotoxy(X, 20);
        printf("%c", 223);
    }

    for(unsigned char X = 1 ; X < 50 ; X++){
        for(unsigned char Y = 1 ; Y < 20 ; Y++){
            _gotoxy(X, Y);
            printf("%c", 177);
        }
    }

    _gotoxy(14, 9);
    printf("TECLE ALGO PARA INICIAR!");
}
