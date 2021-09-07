# Snake_Game_CMD_Basic_tutorial

  Snake Game is a simple game, I divided this project in 2 main files (ignoring the "main" file):

  Display.h, have the commands for drawn the map, and all the structures you will see.

  Player.h, have the commands for the player, your movement for example.


  In Display.h we have the map, with the position values of the structures, and functions that for example, generate the objects like an apple, the matrix "estruturas" has the representations of the structures of the map, and the type of structure, whether it is a barrier that the player will die if touch, or a fruit that it will increase in size if touching, and the code of the respective structure in ASCII.
  
  In Player.h we have the snake, your represetations like your body, drawn the snake, check impacts, etc.
  
  In Main.h we have the variable startups and the game loop.
  
  In Game Loop, we have 6 main functions:

  Jogador._Puxar_Corpo(); -> Whenever the snake moves, her head changes places, but the position of her body needs to follow the path that the head is going, almost "pulling the body" by the path of the head.
  
  Jogador._Direcionar_Player(); -> This function gets the keyboard keys for change the snake direction.
  
  Jogador._Mover_Player(); -> This function will move the snake for the respectve direction.
  
  Jogador._Verificar_Impacto(Janela); -> This function will check all the colisions of the game, the colision with the skane and it is body, or the snake with the structs of the map, so until, we pass as a parameter the class "_PLANO".
  
  Jogador._Desenhar_Player(); -> Here we will drawn the snake, but, we do not are using a graphic system, so every time when we writes something the display updates, this causes a higher processing effort than it would be if you drew everything and updated it once, and it also makes it extremely easy for a visual writing bug and program slowdowns, however, to create the feeling of snake movement, do not necessary down all snake, just the face, the block right after the face and erase the end of the snake, for that project at least, to make the moviment felling we do this in this project, and to make the snake curves uses the vetor "Representar_Numero_Corpo" to change the second block after the snake's head, creating this ilusion.
  
  Sleep(100); -> Waits 100 miliseconds to repeat the cycle of main game.
 
