#include <iostream>
#include "Desenhos.h"
#include "Mapa.h"
#include "Player.h"

using namespace std;

int main()
{
    /*unsigned char X = 0;
    for(int B = 0 ; B < 255 ; B++){
        std::cout << B << " === " << X << endl;
        X++;
    }*/
    _Desenhar_Menu();
    getch();
    system("cls");
    Plano Plano_Mapa;
    Plano_Mapa._Desenhar_Mapa();
    getch();

    Player Jogador;

    unsigned char EXIT_PROGRAM = false;

    while(EXIT_PROGRAM == false)
    {
        Jogador._Direcionar_Player();
        Jogador._Mover_Player(Plano_Mapa);

        system("cls");
        Plano_Mapa._Desenhar_Mapa();

        Sleep(300);
    }


    return 0;
}
