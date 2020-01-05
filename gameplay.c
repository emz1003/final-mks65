#include "final.h"

void initializeBoard(struct cell gameBoard[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++) {
      char asciirow = j + 65;
      gameBoard[i][j].symbol = WATER;
      gameBoard[i][j].position.row = asciirow;
      gameBoard[i][j].position.col = j;
    }
  }
}

void printBoard(struct cell gameBoard[ROWS][COLS]){
  int i = 0, j = 0;
  printf("  0 1 2 3 4 5 6 7 8 9\n");
  for (i = 0; i < ROWS; i++) {
    printf("%c ", i);
    for (j = 0; j < COLS; j++) {
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
