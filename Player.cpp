
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
        switch(_getch())
        {
            case 'w':
                Diresao = UP;
            break;

            case 's':
                Diresao = DOWN;
            break;

            case 'a':
                Diresao = LEFT;
            break;

            case 'd':
                Diresao = RIGHT;
            break;
        }
    }
}
void _PLAYER::_Mover_Player(void){
    switch(Diresao)
    {
        case UP:
            Posisoes_Cobra_Y[0]--;
        break;

        case DOWN:
            Posisoes_Cobra_Y[0]++;
        break;

        case LEFT:
            Posisoes_Cobra_X[0]--;
        break;

        case RIGHT:
            Posisoes_Cobra_X[0]++;
        break;
    }
}

void _PLAYER::_Puxar_Corpo(void){
    for(short int X = short(Numero_Bloco_Cobra.size()) ; X > 0 ; X--){
        Posisoes_Cobra_X[X] = Posisoes_Cobra_X[X-1];
        Posisoes_Cobra_Y[X] = Posisoes_Cobra_Y[X-1];
    }
}

void _PLAYER::_Desenhar_Player(void){
    for(short int X = short(Numero_Bloco_Cobra.size())-1 ; X >= 0 ; X--){
        _gotoxy(Posisoes_Cobra_X[X], Posisoes_Cobra_Y[X]);
        printf("%c", Representar_Numero_corpo[Numero_Bloco_Cobra[X]]);
    }
}

void _PLAYER::_Verificar_Impacto(_PLANO &Janela){
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'B'){
        Vida--;
    }
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'F'){
        Numero_Bloco_Cobra.pop_back();
        Numero_Bloco_Cobra.push_back(2);
        Numero_Bloco_Cobra.push_back(0);
        //Janela._Criar_Fruta(Posisoes_Cobra_X, Posisoes_Cobra_Y);
    }
    for(short int X = 1 ; X < short(Numero_Bloco_Cobra.size())-1 ; X++){
        if(Posisoes_Cobra_X[0] == Posisoes_Cobra_X[X] && Posisoes_Cobra_Y[0] == Posisoes_Cobra_Y[X]){
            Vida--;
        }
    }

}

unsigned char _PLAYER::_Get_Vida(void){
    return Vida;
}

std::vector <unsigned char> _PLAYER::_Get_Posisoes_Cobra_X(void){
    return Posisoes_Cobra_X;
}
std::vector <unsigned char> _PLAYER::_Get_Posisoes_Cobra_Y(void){
    return Posisoes_Cobra_Y;
}
