#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <cstdio>
#include <windows.h>
#include <vector>
#include <ctime>


void _Desenhar_Plano(void);
void _Criar_Fruta(std::vector <unsigned char> &Posisoes_Invalidas_X, std::vector <unsigned char> &Posisoes_Invalidas_Y);
unsigned char _Get_Estrutura_Mapa(unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Tipo_Estrutura);
void _Mudar_Valor_Mapa(unsigned char Mapa_X, unsigned char Mapa_Y, unsigned char Valor);


void _gotoxy (short int X, short int Y);

void _Desenhar_Menu(void);

void _GAME_OVER();

#endif // DISPLAY_H_INCLUDED
