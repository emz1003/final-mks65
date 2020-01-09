#include "final.h"

void initializeBoard(struct cell gameBoard[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++) {
      gameBoard[i][j].symbol = WATER;
      gameBoard[i][j].position.row = i;
      gameBoard[i][j].position.col = j;
    }
  }
}

void printBoard(struct cell gameBoard[ROWS][COLS]){
  printf("  0 1 2 3 4 5 6 7 8 9\n");
  for (int i = 0; i < ROWS; i++) {
    char temp = i + 65;
    printf("%c ", temp);
    for (int j = 0; j < COLS; j++) {
      switch(gameBoard[i][j].symbol){
        case HIT: printf("%c ", HIT); break;
        case MISS: printf("%c ", MISS); break;
        case WATER:
        default: printf("%c ", WATER); break;
      }
    }
    printf("\n");
  }
}

void putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, char* direction){
  for (i = 0; i < input.length; i++) {
    if (!strcmp(direction, HORIZONTAL)){
      gameBoard[position.row][position.col + i].symbol = ship.symbol;
    }
    else { //Would be vertically oriented
      gameBoard[position.row + i][position.col].symbol = ship.symbol;
    }
  }
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
  coor1.row = carriercoor[0] - 65;
  coor1.col = carriercoor[1];
  putShip(gameBoard, carrier, coor1, carrierdirec);
  printBoard(gameBoard);
}
