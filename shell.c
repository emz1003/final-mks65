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
    gamePlay();
  } else if(!strcmp(line, "join game")){
      printf("Joined game!\n");
  } else if(!strcmp(line, "exit")){
      return 1; //exits the entire program
  } else {
      printf("Command not valid!\n");
  }
  return 0;
}

void gamePlay(){
  struct cell gameBoard[ROWS][COLS];
  initializeBoard(gameBoard);
  printBoard(gameBoard);
  printf("\n");
  printf("Now, place your ships! Enter in a coordinate pair (row, column) of where you want your ship to start.\n");
  printf("If you're going horizontally, enter in the leftmost coordinate of where you want your ship to be.\n");
  printf("If you're going vertically, enter in the lowest coordinate of where you want your ship to be.\n");
  printf("\n");

  printf("Place your carrier! Ship length: 5. Enter in the coordinate in this format: A2 / Enter in the direction in this format: HORIZONTAL or VERTICAL\n");
  printf("Coordinate: ");
  char carriercoor[10];
  char carrierdirec[10];
  fgets(carriercoor, sizeof carriercoor, stdin);
  printf("Direction: ");
  fgets(carrierdirec, sizeof carrierdirec, stdin);
  struct ship carrier;
  struct coordinate coor1;
  carrier.symbol = CARRIER;
  carrier.length = 5;
  coor1.row = carriercoor[0] - 65
  coor1.col = carriercoor[1];
  putShip(gameBoard, carrier, coor1, carrierdirec);
  printBoard(gameBoard);
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
