
#include "Mapa.h"
#include "Desenhos.h"


void Plano::_Desenhar_Mapa(void){

    for(unsigned short int Y = 0 ; Y < Altura_Mapa ; Y++){
        for(unsigned short int X = 0 ; X < Largura_Mapa ; X++){
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


