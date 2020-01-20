#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
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
#define CL 1 //carrier
#define BL 1 //battleship
#define CR 1 //cruiser
#define SL 1 //submarine
#define DL 1 //destroyer

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
};

//initialize the four boards of the game
struct cell playerOneBoard[ROWS][COLS]; //playerOne's board
struct cell playerOneMain[ROWS][COLS]; //playerOne's main game board
struct cell playerTwoBoard[ROWS][COLS]; //playerOne's main game board
struct cell playerTwoMain[ROWS][COLS]; //playerOne's main game board

//FUNCTION HEADERS
int createshell();
void gamePlay(struct cell ownBoard[ROWS][COLS], struct cell mainBoard[ROWS][COLS]);
void initializeBoard(struct cell gameBoard[ROWS][COLS]);
void printBoard(struct cell gameBoard[ROWS][COLS]);
int execute(char * line);
int putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction);
int isCoorValid(struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction);
void addShiptoBoard(struct cell gameBoard[ROWS][COLS], struct ship input, char shipType, int shipLength);
int isWin (struct cell gameBoard[ROWS][COLS]);
int hitTarget(struct cell gameBoard[ROWS][COLS], struct coordinate position);
void playerOne();
void playerTwo();
