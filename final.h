#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pwd.h>

//CONSTANTS
#define ROWS 10
#define COLS 10

#define WATER '~'
#define HIT '*'
#define MISS '+'

#define CARRIER 'c'
#define BATTLESHIP 'b'
#define CRUISER 'r'
#define SUBMARINE 's'
#define DESTROYER 'd'

//STRUCTS
struct coordinate {
  char row;
  int col;
};

struct cell {
  char symbol;
  struct coordinate position;
};

//FUNCTION HEADERS
int createshell();
void initializeBoard(struct cell gameBoard[ROWS][COLS]);
void printBoard(struct cell gameBoard[ROWS][COLS]);
int execute(char * line);
