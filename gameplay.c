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

void putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction){
  for (i = 0; i < input.length; i++) {
    if (direction == HORIZONTAL){
      gameBoard[position.row][position.col + i].symbol = ship.symbol;
    }
    else { //Would be vertically oriented
      gameBoard[position.row + i][position.col].symbol = ship.symbol;
    }
  }
}
