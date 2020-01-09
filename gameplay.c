#include "final.h"

void initializeBoard(struct cell gameBoard[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++) {
      gameBoard[i][j].symbol = WATER;
      gameBoard[i][j].position.col = i;
      gameBoard[i][j].position.row = j;
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
        case CARRIER: printf("%c ", CARRIER); break;
        case BATTLESHIP: printf("%c ", BATTLESHIP); break;
        case CRUISER: printf("%c ", CRUISER); break;
        case SUBMARINE: printf("%c ", SUBMARINE); break;
        case DESTROYER: printf("%c ", DESTROYER); break;
        case WATER:
        default: printf("%c ", WATER); break;
      }
    }
    printf("\n");
  }
}

void putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction){
  for (int i = 0; i < input.length; i++) {
    if (direction){
      gameBoard[position.col][position.row + i].symbol = input.symbol;
    }
    else { //Would be horizontally
      gameBoard[position.col + i][position.row].symbol = input.symbol;
    }
  }
}

void gamePlay(){
  struct cell gameBoard[ROWS][COLS]; //main gameboard
  initializeBoard(gameBoard);
  printBoard(gameBoard);
  printf("\n");
  printf("Now, place your ships! Enter in a coordinate pair (row, column) of where you want your ship to start.\n");
  printf("If you're going horizontally, enter in the leftmost coordinate of where you want your ship to be.\n");
  printf("If you're going vertically, enter in the highest coordinate of where you want your ship to be.\n");
  printf("\n");

  printf("Place your carrier! Ship length: 5. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  printf("Coordinate: ");
  char carriercoor[10];
  char carrierdirec[10];
  fgets(carriercoor, sizeof carriercoor, stdin);
  printf("Direction: ");
  fgets(carrierdirec, sizeof carrierdirec, stdin);
  struct ship carrier;
  struct coordinate coor1;
  carrier.symbol = CARRIER;
  carrier.length = CL;
  coor1.col = carriercoor[0] - 65;
  coor1.row = carriercoor[1] - 48;
  putShip(gameBoard, carrier, coor1, (int)carrierdirec[0]);
  printBoard(gameBoard);
}
