
#include "Display.h"

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

void _Printar_Pontos(unsigned int Pontos){
    _gotoxy(30, 10);
    printf("PONTOS: %d", Pontos);
}

bool _PLANO::_Verificar_Objeto_Plano( unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Objeto){

    for(unsigned char X = 0 ; X < Quantidade_Estruturas ; X++){
        if(Mapa[Mapa_X][Mapa_Y] == Estruturas[X][0]){
            if(Estruturas[X][2] == Objeto)return true;
        }
    }
    return false;
}
void _PLANO::_Gerar_Fruta(void){
    unsigned char Pos_X;
    unsigned char Pos_Y;
    do
    {
        Pos_X = (rand() % LARGURA_MAPA);
        Pos_Y = (rand() % ALTURA_MAPA);

    }while(_Verificar_Objeto_Plano(Pos_X, Pos_Y, 'P') || _Verificar_Objeto_Plano( Pos_X, Pos_Y, 'B'));
    Mapa[Pos_X][Pos_Y] = Estruturas[3][0];
}

unsigned char _PLANO::_Get_Estrutura(unsigned char Estrutura, unsigned char Tipo_Representar){
    return Estruturas[Estrutura][Tipo_Representar];
}
unsigned char _PLANO::_Get_Quantidade_Estruturas(void){
    return Quantidade_Estruturas;
}

void _PLANO::_Desenhar_Mapa(void){

    for(unsigned short int Y = 0 ; Y < ALTURA_MAPA ; Y++){
        for(unsigned short int X = 0 ; X < LARGURA_MAPA ; X++){
            if(Mapa[X][Y]!= 0){
                _gotoxy(X, Y);
                printf("%c", Estruturas[Mapa[X][Y]-1][1]);
            }
        }
    }
}
unsigned char _PLANO::_Get_Mapa(unsigned char X, unsigned char Y){
    return Mapa[X][Y];
}
void _PLANO::_Push_Mapa(unsigned char X, unsigned char Y, unsigned char Valor){
    Mapa[X][Y] = Valor;
}


