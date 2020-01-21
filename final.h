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
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

union semun {
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                              (Linux-specific) */
};
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
#define SEMKEY 84771
#define SHMKEY 84775
#define SHM_SIZE 2048 // stores 32 users

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

struct user_info {
  char usr[32];
  char pwd[32];
  int is_active;
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
void create_db();
void access_db();
int signup(char * usr, char *pwd);
int signin(char * usr, char *pwd);
int signout(char * usr);

