#include <iostream>
#include "Desenhos.h"
#include "Mapa.h"
#include "Player.h"

using namespace std;

int main()
{
    srand(time(NULL));
   
    _Desenhar_Menu();
    getch();
    system("cls");
    Plano Plano_Mapa;
    Plano_Mapa._Desenhar_Mapa();
    getch();

    Player Jogador;
    Plano_Mapa._Gerar_Fruta();
    unsigned char EXIT_PROGRAM = false;

    while(EXIT_PROGRAM == false)
    {
        system("cls");
        Plano_Mapa._Desenhar_Mapa();
        Jogador._Direcionar_Player();
        Jogador._Mover_Player(Plano_Mapa);

        Sleep(100);

    }


    return 0;
}
