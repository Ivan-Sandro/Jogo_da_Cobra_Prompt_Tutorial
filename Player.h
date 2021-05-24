#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Mapa.h"
#include <conio.h>
#include <cstdio>

class Player {
    private:
        unsigned char Jogador_Posisoes[(LARGURA_MAPA-2)*(ALTURA_MAPA-2)+1][2] = {10, 10};  // [][0] -> X || [][1] -> Y //

        unsigned char Diresao = 0;
        short int Tamanho_Jogador = 0;

    public:
        void _Direcionar_Player(void);
        void _Mover_Player(Plano &Display);
        void _Evento_Impacto_Player(Plano &Display);
};



#endif // PLAYER_H_INCLUDED
