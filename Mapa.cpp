
#include "Mapa.h"
#include "Desenhos.h"


void Plano::_Desenhar_Mapa(void){

    for(unsigned short int Y = 0 ; Y < ALTURA_MAPA ; Y++){
        for(unsigned short int X = 0 ; X < LARGURA_MAPA ; X++){
            if(Mapa[X][Y]!= 0){
                _gotoxy(X, Y);
                printf("%c", Estruturas[Mapa[X][Y]-1][1]);
            }
        }
    }
}

void Plano::_Mudar_Valor_Mapa(unsigned char X, unsigned char Y, unsigned char Valor){
    Mapa[X][Y] = Valor;
}

bool Plano::_Verificar_Impacto(unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Objeto){

    for(unsigned char X = 0 ; X < Quantidade_Estruturas ; X++){
        if(Mapa[Mapa_X][Mapa_Y] == Estruturas[X][0]){
            if(Estruturas[X][2] == Objeto)return true;
        }
    }
    return false;
}

void Plano::_Gerar_Fruta(void){
    unsigned char Pos_X;
    unsigned char Pos_Y;
    do
    {
        Pos_X = (rand() % LARGURA_MAPA);
        Pos_Y = (rand() % ALTURA_MAPA);
    }while(_Verificar_Impacto(Pos_X, Pos_Y, 'P') && _Verificar_Impacto(Pos_X, Pos_Y, 'B'));
    _Mudar_Valor_Mapa(Pos_X, Pos_Y, Estruturas[4][0]);
}


