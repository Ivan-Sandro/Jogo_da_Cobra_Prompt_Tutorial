#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


#include "Display.h"
#include <cstdio>

class _PLAYER {
    private:

        unsigned char Vida = true;
        unsigned short int Pontos = 0;

        unsigned char Jogador_Posisoes[(LARGURA_MAPA-2)*(ALTURA_MAPA-2)+1][2];  // [][0] -> X || [][1] -> Y //

        unsigned char Diresao = 0;
        unsigned short int Tamanho_Jogador = 0;

    public:
        unsigned short int _Get_Pontos(void);
        unsigned char _Get_Posisao(unsigned char X, unsigned char Y);
        unsigned char _Get_Vida(void);

        void _Push_Pontos(unsigned char Nova_Pontuasao);
        void _push_Vida(unsigned char Novo_Estado);

        void _Evento_Impacto_Player(_PLANO &Display);
        void _Iniciar_Jogador_Posisoes(unsigned char X, unsigned char Y);
        void _Direcionar_Player(void);
        void _Mover_Player(_PLANO &Display);
};


#endif // PLAYER_H_INCLUDED
