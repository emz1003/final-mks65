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
  printf("%d\n", direction);
  for (int i = 0; i < input.length; i++) {
    if (direction){ //Vertically
      printf("(%d, %d)\n", position.col + i, position.row);
      gameBoard[position.row + i][position.col].symbol = input.symbol;
    }
    else { //Horizontally
      printf("(%d, %d)\n", position.col, position.row + i);
      gameBoard[position.row][position.col + i].symbol = input.symbol;
    }
  }
}

void addShiptoBoard(struct cell gameBoard[ROWS][COLS], struct ship input, char shipType, int shipLength){
  printf("Coordinate: ");
  char coor[10];
  char direc[10];
  fgets(coor, sizeof coor, stdin);
  printf("Direction: ");
  fgets(direc, sizeof direc, stdin);
  struct coordinate coor1;
  input.symbol = shipType;
  input.length = shipLength;
  coor1.row = coor[0] - 65;
  coor1.col = coor[1] - 48;
  putShip(gameBoard, input, coor1, (int)direc[0] - 48);
  printBoard(gameBoard);
  printf("\n");
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

  //place all the ships down
  struct ship carrier;
  struct ship battleship;
  struct ship cruiser;
  struct ship submarine;
  struct ship destroyer;
  printf("Place your carrier! Ship length: 5. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(gameBoard, carrier, CARRIER, CL);
  addShiptoBoard(gameBoard, battleship, BATTLESHIP, BL);
  addShiptoBoard(gameBoard, cruiser, CRUISER, CR);
  addShiptoBoard(gameBoard, submarine, SUBMARINE, SL);
  addShiptoBoard(gameBoard, destroyer, DESTROYER, DL);
}
