#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

/*************************************************************************
*
* Tudo aquilo que é mostrado na tela durante o jogo, Jogador, Mapa, Etc,
* são salvas aqui com suas respectivas definições
*
************************************************************************/

#include <ctime>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#define LARGURA_MAPA 20
#define ALTURA_MAPA 20

class _PLANO{
    private:
    //Char para economizar memória, um short int tem 2 bytes, um char tem 1, e não há a necessidade de guardar mais do que 255 valores.
        unsigned char Mapa[LARGURA_MAPA][ALTURA_MAPA] =   {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};


        unsigned char Estruturas[5][3]   =  {1, 219, 'B',   // Esquerda -> Representação mapa
                                             2, 220, 'B',   // Meio     -> Representação em ASCII
                                             3, 223, 'B',   // Direita  -> Tipo de Estrutura
                                             4, 233, 'F',   // 'B' -> Barreira || 'P' -> Player || 'F' -> Fruta
                                             5, 79 , 'P'};

        unsigned char Quantidade_Estruturas = 5;

    public:
        unsigned char _Get_Estrutura(unsigned char Estrutura, unsigned char Tipo_Representar);
        unsigned char _Get_Quantidade_Estruturas(void);
        unsigned char _Get_Mapa (unsigned char X, unsigned char Y);

        void _Push_Mapa(unsigned char X, unsigned char Y, unsigned char Valor);
        void _Gerar_Fruta(void);
        bool _Verificar_Objeto_Plano( unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Objeto);
        void _Desenhar_Mapa(void);

};

void _gotoxy (short int X, short int Y);

void _Desenhar_Menu(void);
void _Printar_Pontos(unsigned int Pontos);

#endif // DISPLAY_H_INCLUDED
