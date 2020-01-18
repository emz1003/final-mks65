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
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

// union semun {
//     int val;               /* Value for SETVAL */
//     struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
//     unsigned short *array; /* Array for GETALL, SETALL */
//     struct seminfo *__buf; /* Buffer for IPC_INFO
//                               (Linux-specific) */
// };
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
#define SHMKEY 84772
#define SHM_SIZE 1048576

//#define HORIZONTAL 0
//#define VERTICAL 1

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
  char * usr;
  char * pwd;
  int *is_active;
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
void putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, char* direction);
int create_db();
int signup(char * usr, char *pwd);
int login(char * usr, char *pwd);
int logout(char * usr);
