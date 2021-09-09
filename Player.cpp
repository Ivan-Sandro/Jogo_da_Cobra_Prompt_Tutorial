
#include "Player.h"

void _PLAYER::_Iniciar_Player(unsigned char Posisao_Inicial_X, unsigned char Posisao_Inicial_Y){

    Posisoes_Cobra_X.push_back(Posisao_Inicial_X);
    Posisoes_Cobra_Y.push_back(Posisao_Inicial_Y);
    Posisoes_Cobra_X.push_back(Posisao_Inicial_X);
    Posisoes_Cobra_Y.push_back(Posisao_Inicial_Y);

    Tamanho_Cobra = 1;
    Vida = 1;
    Diresao = 0;
    Pontos = 0;

    Player_Fazendo_Curva = 0;

    Representar_Numero_corpo[0] = 32    ;
    Representar_Numero_corpo[1] = 207   ;
    Representar_Numero_corpo[2] = 186   ;
    Representar_Numero_corpo[3] = 205   ;
    Representar_Numero_corpo[4] = 188   ;
    Representar_Numero_corpo[5] = 187   ;
    Representar_Numero_corpo[6] = 200   ;
    Representar_Numero_corpo[7] = 201   ;
}

void _PLAYER::_Direcionar_Player(void){
    if(_kbhit())
    {
        Player_Fazendo_Curva = 1;

        switch(_getch())
        {
            case 'w':
                if(Diresao == RIGHT)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 4;
                else if(Diresao == LEFT)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 6;

                if(Diresao == DOWN)
                    Beep(1000, 100);
                else
                    Diresao = UP;
            break;

            case 's':
                if(Diresao == RIGHT)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 5;
                else if(Diresao == LEFT)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 7;

                if(Diresao == UP)
                    Beep(1000, 100);
                else
                    Diresao = DOWN;
            break;

            case 'a':
                if(Diresao == UP)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 5;
                else if(Diresao == DOWN)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 4;

                if(Diresao == RIGHT)
                    Beep(1000, 100);
                else
                    Diresao = LEFT;
            break;

            case 'd':
                if(Diresao == UP)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 7;
                else if(Diresao == DOWN)
                    Numero_representativo_do_Segundo_Bloco_Cobra = 6;

                if(Diresao == LEFT)
                    Beep(1000, 100);
                else
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
                Numero_representativo_do_Segundo_Bloco_Cobra = 2;

            Posisoes_Cobra_Y[0]--;
        break;

        case DOWN:
            if(Player_Fazendo_Curva == 0)
                Numero_representativo_do_Segundo_Bloco_Cobra = 2;

            Posisoes_Cobra_Y[0]++;
        break;

        case LEFT:
            if(Player_Fazendo_Curva == 0)
                Numero_representativo_do_Segundo_Bloco_Cobra = 3;

            Posisoes_Cobra_X[0]--;
        break;

        case RIGHT:
            if(Player_Fazendo_Curva == 0)
                Numero_representativo_do_Segundo_Bloco_Cobra = 3;

            Posisoes_Cobra_X[0]++;
        break;
    }
    if(Player_Fazendo_Curva !=0)
        Player_Fazendo_Curva--;
}

void _PLAYER::_Puxar_Corpo(void){
    for(short unsigned int X = Tamanho_Cobra ; X > 0 ; X--){
        Posisoes_Cobra_X[X] = Posisoes_Cobra_X[X-1];
        Posisoes_Cobra_Y[X] = Posisoes_Cobra_Y[X-1];
    }
}

void _PLAYER::_Desenhar_Player(void){
    _gotoxy(Posisoes_Cobra_X[1], Posisoes_Cobra_Y[1]);
    printf("%c", Representar_Numero_corpo[Numero_representativo_do_Segundo_Bloco_Cobra]);

    _gotoxy(Posisoes_Cobra_X[Tamanho_Cobra], Posisoes_Cobra_Y[Tamanho_Cobra]);
    printf("%c", Representar_Numero_corpo[0]);

    _gotoxy(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0]);
    printf("%c", Representar_Numero_corpo[1]);
}

void _PLAYER::_Somar_Pontos(void){
    Pontos++;
}
void _PLAYER::_Printar_Pontos(unsigned char X, unsigned char Y){
    _gotoxy(X, Y);
    printf("PONTOS: %d      ", Pontos);
}

void _PLAYER::_Verificar_Impacto(_PLANO &Janela){
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'B'){
        Vida--;
    }else
    if(Janela._Get_Estrutura_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 1) == 'F'){
        Beep(500, 20);
        Janela._Mudar_Valor_Mapa(Posisoes_Cobra_X[0], Posisoes_Cobra_Y[0], 0);
        Posisoes_Cobra_X.push_back(Posisoes_Cobra_X[0]);
        Posisoes_Cobra_Y.push_back(Posisoes_Cobra_Y[0]);
        Tamanho_Cobra++;
        _Somar_Pontos();
        _Printar_Pontos(30, 10);
        Janela._Criar_Fruta(Posisoes_Cobra_X, Posisoes_Cobra_Y);
    }
    for(short unsigned int X = 1 ; X < Tamanho_Cobra ; X++){
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
