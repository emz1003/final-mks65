#include "final.h"

int execute(char * line){
  if (!strcmp(line, "help")){ ///Instructions on commands available
      printf("To sign in, type 'sign in'\n");
      printf("To log in, type 'log in'\n");
      printf("To create game, type 'create game'\n");
      printf("To join game, type 'join game'\n");
      printf("To exit the game, type 'exit'\n");
  } else if (!strcmp(line, "sign in")){
      printf("Signed in!\n");
  } else if (!strcmp(line, "log in")){
      printf("Logged in!\n");
  } else if(!strcmp(line, "create game")){ //Create gameplay
    gamePlay(playerOneBoard, playerOneMain);
    printf("Now, enter in 'start game 1' to start the game!\n");
  } else if(!strcmp(line, "join game")){
    gamePlay(playerTwoBoard, playerTwoMain);
    printf("Now, enter in 'start game 2' to start the game!\n");
  } else if(!strcmp(line, "start game 1")){
    playerOne();
  } else if(!strcmp(line, "start game 2")){
    playerTwo();
  } else if(!strcmp(line, "exit")){
      return 1; //exits the entire program
  } else {
      printf("Command not valid!\n");
  }
  return 0;
}

int createshell(){
    char input[1024];
    printf("welcome to Battleship!\n");
    printf("If you're new to this game, type in 'help' to see the list of valid commands!\n");
    while(1) {
        printf("Enter in a command: ");
        fgets(input, sizeof input, stdin);
        input[strlen(input) - 1] = '\0';
        if(execute(input)){
            break;
        }
    }
    return 0;
}
