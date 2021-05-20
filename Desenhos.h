#ifndef DESENHOS_H_INCLUDED
#define DESENHOS_H_INCLUDED

#include <cstdio>
#include <windows.h>
#include <conio.h>

//Comando pra setar a posição do cursor em alguma cordenada do console
void _gotoxy (short int X, short int Y);

void _Desenhar_Menu     (void);

void _Desenhar_Barreiras(void);

void _Desenhar_Cobra    (void);

void _Desenhar_Comida   (void);

#endif // DESENHOS_H_INCLUDED
