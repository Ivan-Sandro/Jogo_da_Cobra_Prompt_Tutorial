
#include "Player.h"

#define DIRESAO_UP 1
#define DIRESAO_DOWN 2
#define DIRESAO_LEFT 3
#define DIRESAO_RIGHT 4

void Player::_Direcionar_Player(void){

    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w':
                if(Diresao != DIRESAO_DOWN)Diresao = DIRESAO_UP;
            break;

            case 's':
                if(Diresao != DIRESAO_UP)Diresao = DIRESAO_DOWN;
            break;

            case 'a':
                if(Diresao != DIRESAO_RIGHT)Diresao = DIRESAO_LEFT;
            break;

            case 'd':
                if(Diresao != DIRESAO_LEFT)Diresao = DIRESAO_RIGHT;
            break;
        }
    }
}

void Player::_Evento_Impacto_Player(Plano &Display){

    if(Display._Verificar_Impacto(Jogador_Posisoes[0][0], Jogador_Posisoes[0][1], 'P')){
        printf("morreu");
    }
    else if(Display._Verificar_Impacto(Jogador_Posisoes[0][0], Jogador_Posisoes[0][1], 'F')){
        printf("FRUTINHA");
        Display._Gerar_Fruta();
    }
    else if(Display._Verificar_Impacto(Jogador_Posisoes[0][0], Jogador_Posisoes[0][1], 'B')){
        printf("Morreu barreirinha");
    }

}


void Player::_Mover_Player(Plano &Display){

    Display._Mudar_Valor_Mapa(Jogador_Posisoes[Tamanho_Jogador][0], Jogador_Posisoes[Tamanho_Jogador][1], 0);
    switch(Diresao)
    {
        case DIRESAO_UP:
            Jogador_Posisoes[0][1]--;
        break;
        case DIRESAO_DOWN:
            Jogador_Posisoes[0][1]++;
        break;
        case DIRESAO_LEFT:
            Jogador_Posisoes[0][0]--;
        break;
        case DIRESAO_RIGHT:
            Jogador_Posisoes[0][0]++;
        break;
    }

    for(unsigned short int X = Tamanho_Jogador ; X > 0 ; X--){
        Jogador_Posisoes[X][1] = Jogador_Posisoes[X+1][1];
        Jogador_Posisoes[X][0] = Jogador_Posisoes[X+1][0];
    }

    _Evento_Impacto_Player(Display);

    Display._Mudar_Valor_Mapa(Jogador_Posisoes[0][0], Jogador_Posisoes[0][1], 5);
}

