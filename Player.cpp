#include "Player.h"

#define DIRESAO_UP 1
#define DIRESAO_DOWN 2
#define DIRESAO_LEFT 3
#define DIRESAO_RIGHT 4

unsigned short int _PLAYER::_Get_Pontos(void){
    return Pontos;
}

unsigned char _PLAYER::_Get_Vida(void){
    return Vida;
}

void _PLAYER::_Push_Pontos(unsigned char Nova_Pontuasao){
    Pontos = Nova_Pontuasao;
}
void _PLAYER::_push_Vida(unsigned char Novo_Estado){
    Vida = Novo_Estado;
}

unsigned char _PLAYER::_Get_Posisao(unsigned char X, unsigned char Y){
    return Jogador_Posisoes[X][Y];
}

void _PLAYER::_Direcionar_Player(void){

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

void _PLAYER::_Iniciar_Jogador_Posisoes(unsigned char X, unsigned char Y){
    Jogador_Posisoes[0][0] = X;
    Jogador_Posisoes[0][1] = Y;
}

void _PLAYER::_Evento_Impacto_Player(_PLANO &Display){

    if(Display._Verificar_Objeto_Plano( _Get_Posisao(0, 0), _Get_Posisao(0, 1), 'P')){
        _push_Vida(false);
    }
    else if(Display._Verificar_Objeto_Plano(_Get_Posisao(0, 0), _Get_Posisao(0, 1), 'F')){
        Display._Gerar_Fruta();
        Tamanho_Jogador++;
        _Push_Pontos(_Get_Pontos() + 10);
    }
    else if(Display._Verificar_Objeto_Plano(_Get_Posisao(0, 0), _Get_Posisao(0, 1), 'B')){
        _push_Vida(false);
    }

}

void _PLAYER::_Mover_Player(_PLANO &Display){
    Display._Push_Mapa(Jogador_Posisoes[Tamanho_Jogador][0], Jogador_Posisoes[Tamanho_Jogador][1], 0);

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

    _Evento_Impacto_Player(Display);

    for(short int X = Tamanho_Jogador ; X > 0 ; X--){
        Jogador_Posisoes[X][1] = Jogador_Posisoes[X-1][1];
        Jogador_Posisoes[X][0] = Jogador_Posisoes[X-1][0];
    }

    Display._Push_Mapa(Jogador_Posisoes[0][0], Jogador_Posisoes[0][1], 5);

}

