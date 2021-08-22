
#include "Player.h"

void _PLAYER::_Iniciar_Posisoes(unsigned char X, unsigned char Y){
    Posisoes_Cobra_X.push_back(X);
    Posisoes_Cobra_Y.push_back(Y);
    Posisoes_Cobra_X.push_back(X);
    Posisoes_Cobra_Y.push_back(Y);
    Numero_Bloco_Cobra.push_back(1);
    Numero_Bloco_Cobra.push_back(0);
}

void _PLAYER::_Direcionar_Player(void){
    if(_kbhit())
    {
        Player_Fazendo_Curva = 1;

        switch(_getch())
        {
            case 'w':
                if(Posisoes_Cobra_X.size()>2)
                {
                    if(Diresao == RIGHT)
                        Numero_Bloco_Cobra[1] = 4;
                    else if(Diresao == LEFT)
                        Numero_Bloco_Cobra[1] = 6;
                }

                Diresao = UP;
            break;

            case 's':
                if(Posisoes_Cobra_X.size()>2)
                {
                    if(Diresao == RIGHT)
                        Numero_Bloco_Cobra[1] = 5;
                    else if(Diresao == LEFT)
                        Numero_Bloco_Cobra[1] = 7;
                }

                Diresao = DOWN;
            break;

            case 'a':
                if(Posisoes_Cobra_X.size()>2)
                {
                    if(Diresao == UP)
                        Numero_Bloco_Cobra[1] = 5;
                    else if(Diresao == DOWN)
                        Numero_Bloco_Cobra[1] = 4;
                }

                Diresao = LEFT;
            break;

            case 'd':
                if(Posisoes_Cobra_X.size()>2)
                {
                    if(Diresao == UP)
                        Numero_Bloco_Cobra[1] = 7;
                    else if(Diresao == DOWN)
                        Numero_Bloco_Cobra[1] = 6;
                }

                Diresao = RIGHT;
            break;
        }
    }
}
void _PLAYER::_Mover_Player(void){
    switch(Diresao)
    {
        case UP:
            if(Player_Fazendo_Curva == 0)
                Numero_Bloco_Cobra[1] = 2;

            Posisoes_Cobra_Y[0]--;
        break;

        case DOWN:
            if(Player_Fazendo_Curva == 0)
                Numero_Bloco_Cobra[1] = 2;

            Posisoes_Cobra_Y[0]++;
        break;

        case LEFT:
            if(Player_Fazendo_Curva == 0)
                Numero_Bloco_Cobra[1] = 3;

            Posisoes_Cobra_X[0]--;
        break;

        case RIGHT:
            if(Player_Fazendo_Curva == 0)
                Numero_Bloco_Cobra[1] = 3;

            Posisoes_Cobra_X[0]++;
        break;
    }
    if(Player_Fazendo_Curva !=0 && Posisoes_Cobra_X.size()>2)
        Player_Fazendo_Curva--;
}

void _PLAYER::_Puxar_Corpo(void){
    for(short int X = short(Numero_Bloco_Cobra.size()) ; X > 0 ; X--){
        Posisoes_Cobra_X[X] = Posisoes_Cobra_X[X-1];
        Posisoes_Cobra_Y[X] = Posisoes_Cobra_Y[X-1];
    }
}

void _PLAYER::_Desenhar_Player(void){
    _gotoxy(Posisoes_Cobra_X[Posisoes_Cobra_X.size()-1], Posisoes_Cobra_Y[Posisoes_Cobra_Y.size()-1]);
    printf("%c", Representar_Numero_corpo[Numero_Bloco_Cobra[Posisoes_Cobra_X.size()-1]]);

    _gotoxy(Posisoes_Cobra_X[1], Posisoes_Cobra_Y[1]);
    printf("%c", Representar_Numero_corpo[Numero_Bloco_Cobra[1]]);
    _gotoxy(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0]);
    printf("%c", Representar_Numero_corpo[Numero_Bloco_Cobra[0]]);
}

void _PLAYER::_Somar_Pontos(void){
    Pontos++;
}
void _PLAYER::_Printar_Pontos(void){
    _gotoxy(30, 10);
    printf("PONTOS: %d      ", Pontos);
}

void _PLAYER::_Verificar_Impacto(_PLANO &Janela){
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'B'){
        Vida--;
    }else
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'F'){
        Janela._Mudar_Valor_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 0);
        Posisoes_Cobra_X.push_back(Posisoes_Cobra_X[0]);
        Posisoes_Cobra_Y.push_back(Posisoes_Cobra_Y[0]);
        Numero_Bloco_Cobra.pop_back();
        Numero_Bloco_Cobra.push_back(2);
        Numero_Bloco_Cobra.push_back(0);
        _Somar_Pontos();
        _Printar_Pontos();
        Janela._Criar_Fruta(Posisoes_Cobra_X, Posisoes_Cobra_Y);
    }
    for(short int X = 1 ; X < short(Numero_Bloco_Cobra.size())-1 ; X++){
        if(Posisoes_Cobra_X[0] == Posisoes_Cobra_X[X] && Posisoes_Cobra_Y[0] == Posisoes_Cobra_Y[X]){
            Vida--;
        }
    }

}

char _PLAYER::_Get_Vida(void){
    return Vida;
}

std::vector <unsigned char> &_PLAYER::_Get_Posisoes_Cobra_X(void){
    return Posisoes_Cobra_X;
}
std::vector <unsigned char> &_PLAYER::_Get_Posisoes_Cobra_Y(void){
    return Posisoes_Cobra_Y;
}
