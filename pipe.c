#include "final.h"

int main(){
  int fd;
  char * playerOne = "/systems/final-mks65/pipes";
  //Creating the neamed file(FIFO)
  mkfifo(playerOne, 0666);
  char hit1[10], hit2[10];
  while (isWin(mainBoard))
}
