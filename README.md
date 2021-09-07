# Snake_Game_CMD_Basic_tutorial

  Snake Game is a simple game, I divided this project in 2 main files (ignoring the "main" file):

  Display.h, have the commands for drawn the map, and all the structures you will see.

  Player.h, have the commands for the player, your movement for example.


  In Display.h we have the map, with the position values of the structures, and functions that for example, generate the objects like an apple, the matrix "estruturas" has the representations of the structures of the map, and the type of structure, whether it is a barrier that the player will die if touch, or a fruit that it will increase in size if touching, and the code of the respective structure in ASCII.
  
  In Player.h we have the snake, your represetations like your body, drawn the snake, check impacts, etc.
  
  In Main.h we have the variable startups and the game loop.
  
  In Game Loop, we have 6 main functions:

  Jogador._Puxar_Corpo(); -> Whenever the snake moves, her head changes places, but the position of her body needs to follow the path that the head is going, almost "pulling the body" by the path of the head.
  
  Jogador._Direcionar_Player(); -> This function gets the keyboard keys for change the snake direction 
  
  Jogador._Mover_Player(); -> This function will move the snake for the respectve direction
  
  Jogador._Verificar_Impacto(Janela); -> This function will check all the colisions of game
 
