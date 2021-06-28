
#include "Display.h"
#include "Player.h"
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    _Desenhar_Menu();
    _getch();

    system("cls");

    _PLANO Janela;
    _PLAYER Jogador;

    Jogador._Iniciar_Posisoes(10, 10);

    Janela._Criar_Fruta(Jogador._Get_Posisoes_Cobra_X(), Jogador._Get_Posisoes_Cobra_Y());
    Janela._Desenhar_Plano();

    do
    {
        Jogador._Puxar_Corpo();
        Jogador._Direcionar_Player();
        Jogador._Mover_Player();
        Jogador._Verificar_Impacto(Janela);
        Jogador._Desenhar_Player();

        Sleep(100);
    }
    while(Jogador._Get_Vida() > 0);
    _getch();
    return 0;
}
