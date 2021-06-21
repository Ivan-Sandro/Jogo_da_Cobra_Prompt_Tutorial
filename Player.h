#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <conio.h>
#include "Display.h"

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

class _PLAYER{
    private:
        unsigned char Vida = 1;
        char Diresao = 0;

        std::vector <unsigned char> Posisoes_Cobra_X;
        std::vector <unsigned char> Posisoes_Cobra_Y;

        std::vector <unsigned char> Numero_Bloco_Cobra;

        unsigned char Representar_Numero_corpo [3] = {32, 207, 79};

    public:
        void _Verificar_Impacto(_PLANO &Janela);
        void _Puxar_Corpo(void);
        void _Iniciar_Posisoes(unsigned char X, unsigned char Y);
        void _Direcionar_Player(void);
        void _Mover_Player(void);
        void _Desenhar_Player(void);
        unsigned char _Get_Vida(void);
        std::vector <unsigned char> _Get_Posisoes_Cobra_X(void);
        std::vector <unsigned char> _Get_Posisoes_Cobra_Y(void);

};

#endif // PLAYER_H_INCLUDED
