#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

/*************************************************************************
*
* Tudo aquilo que � mostrado na tela durante o jogo, Jogador, Mapa, Etc,
* s�o salvas aqui com suas respectivas defini��es
*
************************************************************************/

#define Largura_Mapa 20
#define Altura_Mapa 20

class Plano{
    private:
    //Char para economizar mem�ria, um short int tem 2 bytes, um char tem 1, e n�o h� a necessidade de guardar mais do que 255 valores.
        unsigned char Mapa[Largura_Mapa][Altura_Mapa] =   {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                                                           2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};

                                                            // Esquerda -> Representa��o mapa
        unsigned char Estruturas[4][3]   =  {1, 219, 'B',   // Meio     -> Representa��o em ASCII
                                             2, 220, 'B',   // Direita  -> Tipo de Estrutura
                                             3, 223, 'B',   // ' ' -> Vazio || 'B' -> Barreira || 'P' -> Player
                                             4, 79 , 'P'};

    public:
        void _Mudar_Valor_Mapa(unsigned char X, unsigned char Y, unsigned char Valor);
        void _Desenhar_Mapa(void);
};

#endif // MAPA_H_INCLUDED
