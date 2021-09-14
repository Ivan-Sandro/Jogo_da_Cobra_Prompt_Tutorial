
#include "Display.h"
#include "Player.h"
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
    system("title SNAKE GAME autor: Ivan Sandro Gomes Vieira Nóbrega");
    srand(time(NULL));

    _Desenhar_Menu();
    _getch();

    system("cls");

    _PLAYER Jogador;

    Jogador._Iniciar_Player(10, 10);

    _Criar_Fruta(Jogador._Get_Posisoes_Cobra_X(), Jogador._Get_Posisoes_Cobra_Y());
    _Desenhar_Plano();
    Jogador._Printar_Pontos(30, 10);

    do
    {
        Jogador._Puxar_Corpo();
        Jogador._Direcionar_Player();
        Jogador._Mover_Player();
        Jogador._Verificar_Impacto();
        Jogador._Desenhar_Player();

        Sleep(100);
    }
    while(Jogador._Get_Vida() > 0);
    _getch();

    system("cls");
    _GAME_OVER();
    Jogador._Printar_Pontos(50, 15);

    _getch();

    return 0;
}
