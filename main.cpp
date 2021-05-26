#include "Display.h"
#include "Player.h"
#include "Eventos.h"

using namespace std;

int main()
{
    srand(time(NULL));

    _Desenhar_Menu();
    getch();
    system("cls");

    _PLANO Plano_Mapa;
    _PLAYER Jogador;

    Plano_Mapa._Gerar_Fruta();
    Plano_Mapa._Desenhar_Mapa();
    Jogador._Iniciar_Jogador_Posisoes(10, 10);

    while(Jogador._Get_Vida() == true)
    {
        system("cls");
        Plano_Mapa._Desenhar_Mapa();
        _Printar_Pontos(Jogador._Get_Pontos());
        Jogador._Direcionar_Player();
        Jogador._Mover_Player(Plano_Mapa);

        Sleep(100);

    }

    _gotoxy(40, 15);
    printf("MORREU!");
    getch();
    return 0;
}
