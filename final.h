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

//length of ships
#define CL 5 //carrier
#define BL 4 //battleship
#define CR 3 //cruiser
#define SL 3 //submarine
#define DL 2 //destroyer

//STRUCTS
struct coordinate {
  int row;
  int col;
};

struct cell {
  char symbol;
  struct coordinate position;
};

struct ship {
  char symbol;
  int length;
  //char *name;
};

//FUNCTION HEADERS
int createshell();
void gamePlay();
void initializeBoard(struct cell gameBoard[ROWS][COLS]);
void printBoard(struct cell gameBoard[ROWS][COLS]);
int execute(char * line);
int putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction);
int isCoorValid(struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction);
void addShiptoBoard(struct cell gameBoard[ROWS][COLS], struct ship input, char shipType, int shipLength);
void hitTarget(struct cell gameBoard[ROWS][COLS]);
