# Snake_Game_CMD_Basic_tutorial - English

  Snake Game is a simple game, I divided this project in 2 main files (ignoring the "main.h" file):

  Display.h have the commands for drawn the map and all the structures you will see.

  Player.h have the commands for the player, your movement for example.


  In Display.h we have the map, with the positions and values of the structures, and functions that for example, generate the objects like an apple, the matrix "estruturas" has the representations of the structures of the map, and the type of structure, whether it is a barrier that the player will die if touch, or a fruit that it will increase in size if touching, and the code of the respective structure in ASCII.
  
  In Player.h we have the snake, your represetations like your body, drawn the snake, check impacts, etc.
  
  In Main.h we have the variable startups and the game loop.
  
  In Game Loop, we have 6 main functions:

  Jogador._Puxar_Corpo(); -> Whenever the snake moves, her head changes places, but the position of her body needs to follow the path that the head is going, almost "pulling the body" by the path of the head.
  
  Jogador._Direcionar_Player(); -> This function gets the keyboard keys for change the snake direction.
  
  Jogador._Mover_Player(); -> This function will move the snake for the respectve direction.
  
  Jogador._Verificar_Impacto(Janela); -> This function will check all the colisions of the game, the colision with the skane and it is body, or the snake with the structs of the map, so until, we pass as a parameter the class "_PLANO".
  
  Jogador._Desenhar_Player(); -> Here we will drawn the snake, but, we do not are using a graphic system, so every time when we writes something the display updates, this causes a higher processing effort than it would be if you drew everything and updated it once, and it also makes it extremely easy for occur a visual writing bug, however, to create the feeling of snake movement, do not necessary draw all snake, just the face, the block right after the face and erase the end of the snake, for that project at least, to make the moviment sensation we do that in this project, and to make the snake curves uses the vetor "Representar_Numero_Corpo" for change the second block after the snake's head, creating this ilusion.
  
  Sleep(100); -> Waits 100 miliseconds to repeat the cycle of game loop.
 
  Now I hope you have a better idea about the logic behind a Snake Game.
  
# Snake_Game_CMD_Basic_Tutorial - Português.

  O jogo da cobra é um jogo simples, eu dividi esse projeto em 2 arquivos principais (ignorando o arquivo "main.h")
  
  Display.h possui os comandos para desenhar o mapa e todas as estruturas que você irá ver.
  
  Player.h possui os comandos para o player, seu movimento por exemplo.
  
  No Display.h nós temos o mapa, com as posições e valores das estruturas, e funções que por exemplo, gera os objetos como a maça, a matriz "estrutura" possui as representações das estruturas do mapa, e o tipo de estrutura, se é uma barreira que o player vai morrer se tocar, ou uma fruta que ele irá aumentar de tamanho se tocar, e o código da respectiva estrutura em ASCII.
  
  In player.h nos temos a cobra, sua representação como seu corpo, desenhar a cobra, chegar impacto, etc.
  
  In Main.h nó stemos as inicializações de variaveis e o loop do jogo.
  
  No loop do jogo, nós temos 6 funções principais.
  
  Jogador._Puxar_Corpo(); -> Sempre que a cobra se move, sua cabeça muda de lugar, mas a posição de seu corpo precisa acompanhar o caminho que a cabeça está indo, quase "puxando o corpo" para a direção da cabeça.
  
  Jogador._Direcionar_Player(); -> Essa função vai mover a cobra para a respectiva direção.
  
  Jogador._Desenhar_Player(); -> Aqui nós iremos desenhar a cobra, mas, nós não estamos usando um sistema gráfico, então sempre que nós desenhamos alguma coisa na tela o display atualiza, isso causa um esforço de processamento maior do que seria se você desenhasse tudo e atualizasse uma vez, e também torna extremamente fácil para um bug de escrita visual, no entando, para cria a sensação de movimento da cobra, não é necessário desenhar toda a cobra, apenas o rosto, o bloco logo após o rosto e apagar o final da cobra, para esse projeto pelo menos, para fazer a sensação de movimento fazemos isso neste projeto, e para fazer as curvas da cobra usamos o vetor "Representar_Numero_Corpo" para mudar o segundo bloco após a cabeça da cobra, criando essa ilusão.
  
  Sleep(100); -> Espera 100 milisegundos para repetir o ciclo do loop do jogo.
  
  Agora eu espero que você tenha uma ideia melhor sobre a lógica por trás de um Snake Game.
